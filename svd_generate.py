from cmsis_svd.parser import SVDParser


def show_device_infor(device):
    for p in device.peripherals:
        print(f"{p.name}  base=0x{p.base_address:08X}  desc={p.description}")
        print("-"*60)
        for r in p.registers:
            abs_addr = p.base_address + r.address_offset
            print(f"  {r.name:<24} @ +0x{r.address_offset:04X} = 0x{abs_addr:08X}  reset={r.reset_value:08X}")

            # 5) Iterate fields in each register
            for f in r.fields or []:
                    bit_off  = getattr(f, 'bit_offset', None)
                    bit_wid  = getattr(f, 'bit_width',  None)
    
                    # (Some SVDs may use lsb/msb; fallback)
                    if bit_off is None and hasattr(f, 'lsb') and hasattr(f, 'msb'):
                        bit_off = f.lsb
                        bit_wid = f.msb - f.lsb + 1
                    print(f"    {f.name:<20} bit offset={bit_off}  bit width={bit_wid}  access={f.access}")

        print("-"*60)

def get_peripheral(device, name):
    for p in device.peripherals:
          if p.name == name:
            return p
    raise ValueError(f"Peripheral {name} not found")

def show_peripheral_infor(device, peripheral_name):
    peripheral = get_peripheral(device, peripheral_name)
    print(f"{peripheral.name}  base=0x{peripheral.base_address:08X}  desc={peripheral.description}")
    print("-"*60)

    for r in peripheral.registers:
        abs_addr = peripheral.base_address + r.address_offset
        print(f"  {r.name:<24} @ +0x{r.address_offset:04X} = 0x{abs_addr:08X}  reset={r.reset_value:08X}")

        # 5) Iterate fields in each register
        for f in getattr(r, 'fields', []):
                bit_off  = getattr(f, 'bit_offset', None)
                bit_wid  = getattr(f, 'bit_width',  None)
                # (Some SVDs may use lsb/msb; fallback)
                if bit_off is None and hasattr(f, 'lsb') and hasattr(f, 'msb'):
                    bit_off = f.lsb
                    bit_wid = f.msb - f.lsb + 1

                print(f"    {f.name:<20} bit offset={bit_off}  bit width={bit_wid}  access={f.access}")

    print("-"*60)

if __name__ == "__main__":
    parser = SVDParser.for_xml_file("STM32H743.svd")

    device = parser.get_device()

    show_peripheral_infor(device, "RCC")
