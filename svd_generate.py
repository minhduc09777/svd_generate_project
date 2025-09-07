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
    
    def generate_struct(self):
        if not self.fields:
            gen_content = f"{{ uint{{self.device_bit_with}}_t {{self.register_name}}; }};"
            print(gen_content)
            return
        
        gen_content = f"typedef struct {self.register_name.lower()}_t {{\n"
        for f in self.fields:
            bit_off  = getattr(f, "bit_offset", None)
            bit_wid  = getattr(f, "bit_width",  None)

            # (Some SVDs may use lsb/msb; fallback)
            if bit_off is None and hasattr(f, "lsb") and hasattr(f, "msb"):
                bit_off = f.lsb
                bit_wid = f.msb - f.lsb + 1
            
            bit_width_list = [8, 16, 32]
            register_bit_width = bit_width_list[int(bit_wid/8)]
            gen_content += f"    uint{register_bit_width}_t {f.name.lower()}_bit : {bit_wid}; // bit offset={bit_off}  bit width={bit_wid}  access={f.access}\n"

        gen_content += f"}} {self.register_name.lower()}_reg;\n"
        print(gen_content)
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

    PLLCFGR = struct_register(device, "RCC", "PLLCFGR")
    with open(f"{device.name}_io.h", "w") as f:
        f.write(PLLCFGR.generate_struct())
