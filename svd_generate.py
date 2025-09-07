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
            return (r, peripheral.base_address, r.address_offset, r.reset_value)
    raise ValueError(f"register {register_name} not found")

class struct_register:
    def __init__(self, device, peripheral_name, register_name):
        self.peripheral_name = peripheral_name
        self.register_name = register_name
        self.device_bit_width = device.width
        peri_infor=get_register(device, peripheral_name, register_name)
        self.fields = peri_infor[0].fields
    
    def generate_struct(self, indent=0, only_fields=False):
        if not self.fields or len(self.fields) == 1 or only_fields:
            gen_content = indent * " " + f"uint{self.device_bit_width}_t {self.register_name.lower()}_reg;\n"
            print(gen_content)
            return gen_content

        gen_content = indent * " " + f"typedef struct {self.register_name.lower()}_reg_t {{\n"
        gen_content += indent * " " + f"    union {{\n"
        gen_content += indent * " " + f"        uint{self.device_bit_width}_t {self.register_name.lower()}_reg;\n\n"
        gen_content += indent * " " + f"        // bit fields\n"
        gen_content += indent * " " + f"        struct {{\n"

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
                gen_content += indent * " " + f"            uint{self.device_bit_width}_t reserved{count_reserved}: {bit_off - list_tracking_length_offset};\n"
                list_tracking_length_offset = bit_off
                count_reserved += 1
            gen_content += indent * " " + f"            uint{self.device_bit_width}_t {f.name.lower()}_bit : {bit_wid}; // bit offset={bit_off}  bit width={bit_wid}  access={f.access}\n"
            list_tracking_length_offset += 1
        
        if list_tracking_length_offset < self.device_bit_width:
            gen_content += indent * " " + f"            uint{self.device_bit_width}_t reserved{count_reserved} : {self.device_bit_width - list_tracking_length_offset};\n"
            list_tracking_length_offset = self.device_bit_width

        gen_content += indent * " " + f"        }} {self.register_name.lower()}_bits;\n"
        gen_content += indent * " " + f"    }};\n"

        gen_content += indent * " " + f"}} {self.register_name.lower()}_reg;\n"
        print(gen_content)
        return gen_content

class struct_periheral:
    def __init__(self, device, peripheral_name):
        self.peripheral_name = peripheral_name
        self.peripheral = get_peripheral(device, peripheral_name)
        self.registers = [struct_register(device, peripheral_name, r.name) for r in self.peripheral.registers]
    
    def generate_struct(self):
        gen_content = f"typedef struct {self.peripheral_name.lower()}_t {{\n\n"
        for r in self.registers:
            gen_content += r.generate_struct(indent=4, only_fields=False) + "\n"
        gen_content += f"}} {self.peripheral_name.lower()}_t;\n"
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
    with open(f"{device.name}_io.h", "w") as f:
        f.write(RCC_reg.generate_struct())
