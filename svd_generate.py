from cmsis_svd.parser import SVDParser

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

class struct_register:
    def __init__(self, device, peripheral_name, register_name):
        self.peripheral_name = peripheral_name
        self.register_name = register_name
        peri_infor=get_register(device, peripheral_name, register_name)
        self.fields = peri_infor[0].fields
        self.address_offset = peri_infor[2]
        self.reset_value = peri_infor[3]
        self.device_bit_width = peri_infor[4]
    
    def generate_struct(self, indent=0, only_fields=False):
        if not self.fields or len(self.fields) == 1 or only_fields:
            gen_content = indent * " " + f"__IO uint{self.device_bit_width}_t {self.register_name.lower()}_reg;\n"
            print(gen_content)
            return gen_content

        hierachy_level=[0*" ", 4*" ", 8*" "]
        gen_content = indent * " " + f"union {{\n"
        gen_content += indent * " " + hierachy_level[1] + f"__IO uint{self.device_bit_width}_t {self.register_name.lower()}_reg;\n\n"
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
                gen_content += indent * " " + hierachy_level[2] + f"__IO uint{self.device_bit_width}_t reserved{count_reserved}: {bit_off - list_tracking_length_offset};\n"
                list_tracking_length_offset = bit_off
                count_reserved += 1
            gen_content += indent * " " + hierachy_level[2] + f"__IO uint{self.device_bit_width}_t {f.name.lower()}_bit : {bit_wid}; // bit offset={bit_off}  bit width={bit_wid}  access={f.access}\n"
            list_tracking_length_offset = bit_off + bit_wid
        
        if list_tracking_length_offset < self.device_bit_width:
            gen_content += indent * " " + hierachy_level[2] + f"__IO uint{self.device_bit_width}_t reserved{count_reserved} : {self.device_bit_width - list_tracking_length_offset};\n"
            list_tracking_length_offset = self.device_bit_width

        gen_content += indent * " " + hierachy_level[1] + f"}} {self.register_name.lower()}_bits;\n"
        gen_content += indent * " " + f"}};\n"

        print(gen_content)
        return gen_content

class struct_periheral:
    def __init__(self, device, peripheral_name):
        self.peripheral_name = peripheral_name
        self.peripheral = get_peripheral(device, peripheral_name)
        self.registers = [struct_register(device, peripheral_name, r.name) for r in self.peripheral.registers]
        self.registers.sort(key=lambda r: r.address_offset)
        self.registers_dict = {}
        for r in self.registers:
            if r.address_offset not in self.registers_dict:
                self.registers_dict[r.address_offset] = [r]
            else:
                self.registers_dict[r.address_offset].append(r)

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
                if list_tracking_length_offset < r.address_offset:
                    gen_content += f"    __IO uint8_t reserved{count_reserved}[{r.address_offset - list_tracking_length_offset}];\n\n"
                    list_tracking_length_offset = r.address_offset
                    count_reserved += 1
                gen_content += offset_indent * " " + f"    // {r.register_name} @ offset=0x{r.address_offset:08X}\n"
                gen_content += r.generate_struct(indent= 4 + offset_indent, only_fields=False) + "\n"
                list_tracking_length_offset = r.address_offset + r.device_bit_width // 8

            if len(self.registers_dict[key]) > 1:
                gen_content += f"    }};\n\n"

        gen_content += f"}} {self.peripheral_name.lower()}_t;\n\n"
        return gen_content

class struct_device:
    def __init__(self, device):
        self.device = device
        self.peripherals = [struct_periheral(device, p.name) for p in device.peripherals]
        self.peripherals.sort(key=lambda p: p.peripheral_name)
    
    def generate_struct(self):
        gen_content = f"// Device {self.device.name}\n\n"
        for p in self.peripherals:
            gen_content += p.generate_struct()
        return gen_content
    
    def generate_macro_define(self):
        gen_content = "/*------------------------ Device Macro Define ---------------------*/\n"
        gen_content += f"// Device {self.device.name}\n\n"
        indent = 20
        for p in self.peripherals:
            gen_content += f"#define PERI_{p.peripheral_name.upper()}" + (indent-len(p.peripheral_name))*" " + f"(({p.peripheral_name.lower()}_t *) 0x{p.peripheral.base_address:08X})\n"
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
    parser = SVDParser.for_xml_file("STM32H743.svd")
    device = parser.get_device()

    # PLLCFGR = struct_register(device, "RCC", "PLLCFGR")
    # with open(f"{device.name}_io.h", "w") as f:
    #     f.write(PLLCFGR.generate_struct())

    RCC_reg = struct_periheral(device, "RCC")
    GPIOA_reg = struct_periheral(device, "GPIOA")
    GPIOB_reg = struct_periheral(device, "GPIOB")
    GPIOE_reg = struct_periheral(device, "GPIOE")
    stm32h743 = struct_device(device)
    with open(f"{device.name}_io.h", "w") as f:
        f.write("#include <stdint.h>\n\n")
        f.write("#define __IO volatile\n\n")
        # f.write(RCC_reg.generate_struct())
        # f.write(GPIOB_reg.generate_struct())
        # f.write(GPIOE_reg.generate_struct())
        # f.write(GPIOA_reg.generate_struct())
        f.write(stm32h743.generate_struct())
        f.write(stm32h743.generate_macro_define())
