from cmsis_svd.parser import SVDParser
import yaml

import argparse
import os, sys

def get_peripheral(device, peripheral_name):
    for p in device.peripherals:
          if p.name == peripheral_name:
            return p
    raise ValueError(f"Peripheral {peripheral_name} not found")

def get_register(device, peripheral_name, register_name):
    peripheral = get_peripheral(device, peripheral_name)
    for r in peripheral.registers:
          if r.name == register_name:
            return (r, peripheral.base_address, r.address_offset, r.reset_value, r.size)
    raise ValueError(f"register {register_name} not found")

class yml_type_array:
    def __init__(self, yml_array_type):
        self.structs = []
        self.collect_peri_gen = []
        for k, v in yml_array_type.items():
            registers_array = []
            data = []
            if isinstance(v["data"], list):
                registers_array += v["data"]
            else:
                registers_array.append(v["data"])

            for reg in registers_array:
                if "#" in reg:
                    for i in range(v["length"]):
                        data.append(reg.replace("#", str(i)))
            self.structs.append([v["struct_name"], v["varname"],  v["length"], data, False])
    def generate(self, register_name, peri):
        for struct in self.structs:
            if (struct[4] == True) and (peri in self.collect_peri_gen):
                return None
            if register_name in struct[3]:
                struct[4] = True
                self.collect_peri_gen.append(peri)
                return f"{struct[0]} {struct[1]}[{struct[2]}];\n"
    
            
class yml_cfg_type:
    def __init__(self, yml_peripheral_cfg, unit_number="0"):
        self.type = {"array": None, "var": None}
        self.collect_register = []
        self.collect_unit_register = []
        self.collect_data_type = []
        self.collect_register_type = {}
        self.unit_number = unit_number
        self.index_unit = {}

        if "array" in yml_peripheral_cfg.keys():
            registers_array = []
            for k, v in yml_peripheral_cfg["array"].items():
                if isinstance(v["data"], list):
                     registers_array += v["data"]
                else:
                    registers_array.append(v["data"])
                self.collect_data_type.append((v["struct_name"], list(v["data"])))
                
                for reg in registers_array:
                    if "#" in reg:
                        for i in range(v["length"]):
                            data = reg.replace("#", str(i))
                            self.collect_register.append(data)
                            index = reg.rindex("#")
                            unit_reg = reg.replace("#", self.unit_number)
                            if unit_reg not in self.collect_unit_register:
                                self.index_unit[unit_reg]= index
                                self.collect_unit_register.append(unit_reg)
            self.type["array"] = yml_type_array(yml_peripheral_cfg["array"])
        
        for infor_type in self.collect_data_type:
            for i, item in enumerate(infor_type[1]):
                if "#" in item:
                    infor_type[1][i] = item.replace("#", "x")

    def get_register_type_infor(self, data_dict):
        for k, v in data_dict.items():
            if k in self.collect_unit_register:
                key = list(k)
                key[self.index_unit[k]] = "x"
                self.collect_register_type["".join(key)] = v
            else:
                return
    def generate(self, indent=1):
        gen_data = "\n"
        level = [0, 1, 2, 3]
        for infor_type in self.collect_data_type:
            gen_data += " "*indent*level[0] + f"typedef struct {{\n"
            for item in infor_type[1]:
                if item in self.collect_register_type.keys():
                    data_reg = self.collect_register_type[item]
                    list_data_reg = data_reg.split("\n")
                    for data in list_data_reg:
                        gen_data += " "*indent*level[2] + data + "\n"
                else:
                    gen_data += " "*indent*level[2] + f"  __IO uint32_t {item}_reg\n"

            gen_data  += " "*indent*level[0] + f"}} {infor_type[0]};\n"
        return gen_data


class yaml_cfg_register:
    def __init__(self, yml_cfg):
        self.yml_cfg = yml_cfg
        self.peripheral_names = []
        for k, v in yml_cfg.items():
            unit = None
            if "$" in k:
                unit = v["unit"]
            self.peripheral_names.append({k: yml_cfg_type(v), "unit": unit})

        self.collect_modify_perripheral_names = {}
        for index, p in enumerate(self.peripheral_names):
            for k, v in p.items():
                if k == "length" and k == "unit":
                    continue
                if "$" in k:
                    perisplit = k.split('$')
                    list_peri = []
                    for i in list(p["unit"]):
                        perisplit[-1] = str(i)
                        peristr = "".join(perisplit)
                        list_peri.append(peristr)
                    self.collect_modify_perripheral_names[k] = (list_peri, index)
                else:
                    self.collect_modify_perripheral_names[k] = (k, index)

class struct_register:
    def __init__(self, device, peripheral_name, register_name, modify_register):
        self.peripheral_name = peripheral_name
        self.register_name = register_name
        peri_infor=get_register(device, peripheral_name, register_name)
        self.fields = peri_infor[0].fields
        self.address_offset = peri_infor[2]
        self.reset_value = peri_infor[3]
        self.device_bit_width = peri_infor[4]
        self.modify_register = modify_register
        # if self.modify_register != None:
        #     print(self.register_name)
        #     print(self.modify_register)
    
    def generate_struct(self, indent=0, only_fields=False):
        if not self.fields or len(self.fields) == 1 or only_fields:
            gen_content = indent * " " + f"__IO uint{self.device_bit_width}_t {self.register_name.upper()}_reg;\n"
            # print(gen_content)
            return gen_content

        self.fields.sort(key=lambda f: f.bit_offset if hasattr(f, "bit_offset") else (f.lsb if hasattr(f, "lsb") else 0))

        hierachy_level=[0*" ", 4*" ", 8*" "]
        gen_content = indent * " " + f"union {{\n"
        gen_content += indent * " " + hierachy_level[1] + f"__IO uint{self.device_bit_width}_t {self.register_name.upper()}_reg;\n\n"
        gen_content += indent * " " + hierachy_level[1] + f"// bit fields\n"
        gen_content += indent * " " + hierachy_level[1] + f"struct {{\n"

        list_tracking_length_offset = 0
        count_reserved = 0
        for f in self.fields:
            bit_off  = getattr(f, "bit_offset", None)
            bit_wid  = getattr(f, "bit_width",  None)

            # (Some SVDs may use lsb/msb; fallback)
            if bit_off is None and hasattr(f, "lsb") and hasattr(f, "msb"):
                bit_off = f.lsb
                bit_wid = f.msb - f.lsb + 1

            if bit_off > list_tracking_length_offset:
                gen_content += indent * " " + hierachy_level[2] + f"__IO uint{self.device_bit_width}_t RESERVED{count_reserved}: {bit_off - list_tracking_length_offset};\n"
                list_tracking_length_offset = bit_off
                count_reserved += 1
            gen_content += indent * " " + hierachy_level[2] + f"__IO uint{self.device_bit_width}_t {f.name.upper()}_bit : {bit_wid}; // bit offset={bit_off}  bit width={bit_wid}  access={f.access}\n"
            list_tracking_length_offset = bit_off + bit_wid
        
        if list_tracking_length_offset < self.device_bit_width:
            gen_content += indent * " " + hierachy_level[2] + f"__IO uint{self.device_bit_width}_t RESERVED{count_reserved} : {self.device_bit_width - list_tracking_length_offset};\n"
            list_tracking_length_offset = self.device_bit_width

        gen_content += indent * " " + hierachy_level[1] + f"}} {self.register_name.upper()}_bits;\n"
        gen_content += indent * " " + f"}};\n"

        # print(gen_content)
        return gen_content

class struct_periheral:
    def __init__(self, device, peripheral_name, struct_modify: yaml_cfg_register = None):
        self.peripheral_name = peripheral_name
        self.peripheral = get_peripheral(device, peripheral_name)
        self.modify_reg = None
        for k, v in struct_modify.collect_modify_perripheral_names.items():
            for peri_name in v[0]:
                if self.peripheral_name == peri_name:
                    for e, f in struct_modify.peripheral_names[v[1]].items():
                        if e != "unit" and e != "length":
                            self.modify_reg  = [f, peri_name]
        
        self.registers = [struct_register(device, peripheral_name, r.name, self.modify_reg ) for r in self.peripheral.registers]
        self.registers.sort(key=lambda r: r.address_offset)
        self.registers_dict = {}
        for r in self.registers:
            if r.address_offset not in self.registers_dict:
                self.registers_dict[r.address_offset] = [r]
            else:
                self.registers_dict[r.address_offset].append(r)
        
        for key in self.registers_dict.keys():
            for r in self.registers_dict[key]:
                if self.modify_reg:
                    self.modify_reg[0].get_register_type_infor({r.register_name: r.generate_struct()})

    def generate_struct(self):
        gen_content = f"// Peripheral {self.peripheral.name} @ base_addess=0x{self.peripheral.base_address:08X}\n"
        gen_content += f"typedef struct {self.peripheral_name.lower()}_t {{\n\n"

        list_tracking_length_offset = 0
        count_reserved = 0
        for key in self.registers_dict.keys():

            offset_indent = 0
            if len(self.registers_dict[key]) > 1:
                gen_content += f"    union {{\n"
                offset_indent = 4

            for r in self.registers_dict[key]:
                if self.modify_reg != None:
                    if (self.modify_reg[1] == self.peripheral_name and r.register_name in self.modify_reg[0].collect_register):
                        register_modify_arr = self.modify_reg[0].type["array"]
                        if register_modify_arr:
                            data = register_modify_arr.generate(r.register_name, self.peripheral_name)
                            if data:
                                gen_content += f"    {data}"

                        continue
                if list_tracking_length_offset < r.address_offset:
                    gen_content += f"    __IO uint8_t RESERVED{count_reserved}[{r.address_offset - list_tracking_length_offset}];\n\n"
                    list_tracking_length_offset = r.address_offset
                    count_reserved += 1
                gen_content += offset_indent * " " + f"    // {r.register_name} @ offset=0x{r.address_offset:08X}\n"
                gen_content += r.generate_struct(indent= 4 + offset_indent, only_fields=False) + "\n"
                list_tracking_length_offset = r.address_offset + r.device_bit_width // 8

            if len(self.registers_dict[key]) > 1:
                gen_content += f"    }};\n\n"

        gen_content += f"}} {self.peripheral_name.lower()}_t;\n\n"
        return gen_content

class interrupt_periheral:
    def __init__(self, device, cortex):
        self.cpu_interrupt = self.cortex_interrupt_support(cortex)
        self.peripheral_interrupts = self.peripheral_interrupt_support(device)

    def peripheral_interrupt_support(self, device):
        peripherals = device.peripherals
        interrupt_list = list()
        for peripheral in peripherals:
            if hasattr(peripheral, 'interrupts') and peripheral.interrupts:
                interrupt_list += ({interrupt.name + "_IRQn": [interrupt.value, interrupt.description + " Interrupt"]} for interrupt in peripheral.interrupts)

        interrupt_list.sort(key=lambda p: list(p.values())[0])
        filter_list = list()
        filter_interrupt_list = list()
        for interrupt in interrupt_list:
            for k, v in interrupt.items():
                if v[0] not in filter_list:
                    filter_list.append(v[0])
                    filter_interrupt_list.append(interrupt)
        return list(filter_interrupt_list)

    def cortex_interrupt_support(self, cortex):
        dict_cortex_support = {
            "cortex-M": {
            "NonMaskableInt_IRQn": [-14, "Non Maskable Interrupt"],
            "HardFault_IRQn": [-13, "Hard Fault Interrupt"],
            "MemoryManagement_IRQn": [-12, "Memory Management Interrupt"],
            "BusFault_IRQn": [-11, "Bus Fault Interrupt"],
            "UsageFault_IRQn": [-10, "Usage Fault Interrupt"],
            "SVCall_IRQn": [-5, "SVCall Interrupt"],
            "DebugMonitor_IRQn": [-4, "Debug Monitor Interrupt"],
            "PendSV_IRQn": [-2, "PendSV Interrupt"],
            "SysTick_IRQn": [-1, "SysTick Interrupt"],
            }
        }
        if cortex in dict_cortex_support:
            return dict_cortex_support[cortex]
        else:
            print("ERR: Not found cortex")
            sys.exit(1)


class struct_device:
     
    def __init__(self, device, core, struct_modify: yaml_cfg_register = None):
        self.core = core
        self.device = device
        self.peripherals = [struct_periheral(device, p.name, struct_modify) for p in device.peripherals]
        self.peripherals.sort(key=lambda p: p.peripheral_name)
        self.struct_modify = struct_modify
    
    def generate_struct(self):
        gen_content = f"// Device {self.device.name}\n\n"
        for p in self.peripherals:
            gen_content += p.generate_struct()
        return gen_content

    def generate_struct_type(self):
        gen_content = f"/*------------------------ Device type Define ---------------------*/\n"
        if self.struct_modify:
            for peripheral in self.struct_modify.peripheral_names:
                for k, v in peripheral.items():
                    if k != "unit":
                        if v:
                            gen_content += v.generate()
        return gen_content + "\n"
    
    def generate_macro_define(self):
        gen_content = "/*------------------------ Device Macro Define ---------------------*/\n"
        gen_content += f"// Device {self.device.name}\n\n"
        indent = 20
        for p in self.peripherals:
            gen_content += f"#define PERI_{p.peripheral_name.upper()}" + (indent-len(p.peripheral_name))*" " + f"(({p.peripheral_name.lower()}_t *) 0x{p.peripheral.base_address:08X})\n"
        return gen_content
    
    def generate_macro_header(self):
        gen_content =  f"#ifndef {self.device.name}_H_\n"
        gen_content += f"#define {self.device.name}_H_\n\n"
        gen_content += "#include <stdint.h>\n\n"
        gen_content += "#define __IO volatile\n\n"
        return gen_content

    def generate_cpu_config_infor(self):
        __DEVICE_REV = "__{}_REV"
        __MPU_PRESENT = "__MPU_PRESENT"
        __NVIC_PRIO_BITS = "__NVIC_PRIO_BITS"
        __VENDOR_SYSTICKCONFIG = "__Vendor_SysTickConfig"
        __FPU_PRESENT = "__FPU_PRESENT"

        cpu = self.device.cpu
        dict_cpu = dict()

        cpu_revision = list(cpu.revision)
        for i, item in enumerate(cpu_revision):
            if item.isalpha():
                cpu_revision[i] = "0"
        
        cpu_revision = "".join(cpu_revision)

        dict_cpu[__DEVICE_REV.format(cpu.name.name)] = cpu_revision
        dict_cpu[__MPU_PRESENT] = int(cpu.mpu_present)
        dict_cpu[__NVIC_PRIO_BITS] = cpu.nvic_prio_bits
        dict_cpu[__VENDOR_SYSTICKCONFIG] = cpu.vendor_systick_config
        dict_cpu[__FPU_PRESENT] = int(cpu.fpu_present)

        gen_content = "/* CPU information */\n"
        indent = 33
        for key, value in dict_cpu.items():
            macro_part = "#define " + key
            value_part = str(value)
            space_name = indent - len(macro_part)
            gen_content +=  macro_part + " " * space_name + value_part + "\n"
        
        gen_content += "\n"
        return gen_content
    
    def generate_interrupt_event_enumerate(self):
        cortex_interrupt = interrupt_periheral(self.device, self.core)

        indent = 28
        gen_content = """/**
* @brief Interrupt Number Definition, according to the selected device
*        in @ref Library_configuration_section
*/\n"""

        gen_content += "typedef enum {\n"
        gen_content += f"/****** {self.core} Processor Exceptions Numbers *******************************************************************/\n"
        for interrupt_name, value in cortex_interrupt.cpu_interrupt.items():
                gen_content += "  " + interrupt_name + " " * (indent - len(interrupt_name)) + "= " + str(value[0]) + "," + " " * (4 - len(str(value[0]))) + "/*!<" + value[1] + " "*(72-len(value[1])) + "*/\n"

        for peripheral_interrupt in cortex_interrupt.peripheral_interrupts:
            for interrupt_name, value in peripheral_interrupt.items():
                gen_content += "  " + interrupt_name + " " * (indent - len(interrupt_name)) + "= " + str(value[0]) + "," + " " * (4 - len(str(value[0]))) + "/*!<" + value[1] + " "*(72-len(value[1])) + "*/\n"
        
        gen_content += "} IRQn_Type;\n\n"
        return gen_content

def show_register_infor(register, base_address=0):
    abs_addr = base_address + register.address_offset
    print(f"  {register.name:<24} @ +0x{register.address_offset:04X} = 0x{abs_addr:08X}  reset={register.reset_value:08X}")

    # 5) Iterate fields in each register
    for f in register.fields or []:
            bit_off  = getattr(f, "bit_offset", None)
            bit_wid  = getattr(f, "bit_width",  None)

            # (Some SVDs may use lsb/msb; fallback)
            if bit_off is None and hasattr(f, "lsb") and hasattr(f, "msb"):
                bit_off = f.lsb
                bit_wid = f.msb - f.lsb + 1
            print(f"    {f.name:<20} bit offset={bit_off}  bit width={bit_wid}  access={f.access}")

def show_device_infor(device):
    for p in device.peripherals:
        print(f"{p.name}  base=0x{p.base_address:08X}  desc={p.description}")
        print("-"*60)
        for r in p.registers:
            show_register_infor(r, p.base_address)

        print("-"*60)

def show_peripheral_infor(device, peripheral_name):
    peripheral = get_peripheral(device, peripheral_name)
    print(f"{peripheral.name}  base=0x{peripheral.base_address:08X}  desc={peripheral.description}")
    print("-"*60)

    for r in peripheral.registers:
        show_register_infor(r, peripheral.base_address)

    print("-"*60)

if __name__ == "__main__":

    argument_parser = argparse.ArgumentParser()
    argument_parser.add_argument("--device", type=str, help="Generate Device (ex: STM32H743)")
    argument_parser.add_argument("--core", type=str, help="information core (ex: cortex-M)")
    infor_device = argument_parser.parse_args()

    svd_file = f"{infor_device.device}.svd"
    svd_path = f"{infor_device.device}/"
    core = infor_device.core

    if os.path.exists(svd_path+svd_file):
        print(f"generate IO define: {svd_file}")
    else:
        print(f"Not found file: {svd_file}")
        sys.exit(1)
    
    with open(svd_path + "modify_struct_register.yml", "r") as f:
        ymlconfig = yaml.safe_load(f)
    
    struct_modify = yaml_cfg_register(ymlconfig)
    #print(struct_modify.peripheral_names[0]['DMA$'].type['array'].structs)
    # print(struct_modify.peripheral_names[0]['length'])


    parser = SVDParser.for_xml_file(svd_path+svd_file)
    device = parser.get_device()

    iodefine_gen = struct_device(device, core, struct_modify)

    wrapper = ""
        
    with open(f"{svd_path}/{device.name}_io.h", "w") as f:
        f.write(iodefine_gen.generate_macro_header())
        f.write(iodefine_gen.generate_cpu_config_infor())
        f.write(iodefine_gen.generate_interrupt_event_enumerate())
        f.write(iodefine_gen.generate_struct_type())
        f.write(iodefine_gen.generate_struct())
        f.write(iodefine_gen.generate_macro_define())
        f.write("\n\n#endif")
    
    print("Generated successfully")
