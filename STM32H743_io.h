typedef struct pllcfgr_t {
    uint8_t pll1fracen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t pll1vcosel_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t pll1rge_bit : 2; // bit offset=2  bit width=2  access=SVDAccessType.READ_WRITE
    uint8_t pll2fracen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t pll2vcosel_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t pll2rge_bit : 2; // bit offset=6  bit width=2  access=SVDAccessType.READ_WRITE
    uint8_t pll3fracen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t pll3vcosel_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t pll3rge_bit : 2; // bit offset=10  bit width=2  access=SVDAccessType.READ_WRITE
    uint8_t divp1en_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t divq1en_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t divr1en_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t divp2en_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t divq2en_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t divr2en_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t divp3en_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t divq3en_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
    uint8_t divr3en_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
} pllcfgr_reg;
