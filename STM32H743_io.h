typedef struct rcc_t {

    typedef struct cr_reg_t {
        union {
            uint32_t cr_reg;

            // bit fields
            struct {
                uint32_t hsion_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hsikeron_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hsirdy_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hsidiv_bit : 2; // bit offset=3  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 1;
                uint32_t hsidivf_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t csion_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t csirdy_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t csikeron_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t rc48on_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t rc48rdy_bit : 1; // bit offset=13  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t d1ckrdy_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t d2ckrdy_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t hseon_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t hserdy_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t hsebyp_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 1;
                uint32_t hsecsson_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 5;
                uint32_t pll1on_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13: 1;
                uint32_t pll1rdy_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved14: 1;
                uint32_t pll2on_bit : 1; // bit offset=26  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved15: 1;
                uint32_t pll2rdy_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved16: 1;
                uint32_t pll3on_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved17: 1;
                uint32_t pll3rdy_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved18 : 3;
            } cr_bits;
        };
    } cr_reg;

    typedef struct icscr_reg_t {
        union {
            uint32_t icscr_reg;

            // bit fields
            struct {
                uint32_t hsical_bit : 12; // bit offset=0  bit width=12  access=SVDAccessType.READ_ONLY
                uint32_t reserved0: 11;
                uint32_t hsitrim_bit : 6; // bit offset=12  bit width=6  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 6;
                uint32_t csical_bit : 8; // bit offset=18  bit width=8  access=SVDAccessType.READ_ONLY
                uint32_t reserved2: 8;
                uint32_t csitrim_bit : 5; // bit offset=26  bit width=5  access=SVDAccessType.READ_WRITE
                uint32_t reserved3 : 6;
            } icscr_bits;
        };
    } icscr_reg;

    typedef struct hsicfgr_reg_t {
        union {
            uint32_t hsicfgr_reg;

            // bit fields
            struct {
                uint32_t hsical_bit : 12; // bit offset=0  bit width=12  access=SVDAccessType.READ_ONLY
                uint32_t reserved0: 23;
                uint32_t hsitrim_bit : 7; // bit offset=24  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved1 : 8;
            } hsicfgr_bits;
        };
    } hsicfgr_reg;

    uint32_t crrcr_reg;

    typedef struct cfgr_reg_t {
        union {
            uint32_t cfgr_reg;

            // bit fields
            struct {
                uint32_t sw_bit : 3; // bit offset=0  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 2;
                uint32_t sws_bit : 3; // bit offset=3  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 3;
                uint32_t stopwuck_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t stopkerwuck_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t rtcpre_bit : 6; // bit offset=8  bit width=6  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 6;
                uint32_t hrtimsel_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t timpre_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 3;
                uint32_t mco1pre_bit : 4; // bit offset=18  bit width=4  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 4;
                uint32_t mco1sel_bit : 3; // bit offset=22  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 3;
                uint32_t mco2pre_bit : 4; // bit offset=25  bit width=4  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 4;
                uint32_t mco2sel_bit : 3; // bit offset=29  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved10 : 3;
            } cfgr_bits;
        };
    } cfgr_reg;

    typedef struct d1cfgr_reg_t {
        union {
            uint32_t d1cfgr_reg;

            // bit fields
            struct {
                uint32_t hpre_bit : 4; // bit offset=0  bit width=4  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t d1ppre_bit : 3; // bit offset=4  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 4;
                uint32_t d1cpre_bit : 4; // bit offset=8  bit width=4  access=SVDAccessType.READ_WRITE
                uint32_t reserved2 : 24;
            } d1cfgr_bits;
        };
    } d1cfgr_reg;

    typedef struct d2cfgr_reg_t {
        union {
            uint32_t d2cfgr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 4;
                uint32_t d2ppre1_bit : 3; // bit offset=4  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 4;
                uint32_t d2ppre2_bit : 3; // bit offset=8  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved2 : 24;
            } d2cfgr_bits;
        };
    } d2cfgr_reg;

    uint32_t d3cfgr_reg;

    typedef struct pllckselr_reg_t {
        union {
            uint32_t pllckselr_reg;

            // bit fields
            struct {
                uint32_t pllsrc_bit : 2; // bit offset=0  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t divm1_bit : 6; // bit offset=4  bit width=6  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 8;
                uint32_t divm2_bit : 6; // bit offset=12  bit width=6  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 8;
                uint32_t divm3_bit : 6; // bit offset=20  bit width=6  access=SVDAccessType.READ_WRITE
                uint32_t reserved3 : 12;
            } pllckselr_bits;
        };
    } pllckselr_reg;

    typedef struct pllcfgr_reg_t {
        union {
            uint32_t pllcfgr_reg;

            // bit fields
            struct {
                uint32_t pll1fracen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll1vcosel_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll1rge_bit : 2; // bit offset=2  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 1;
                uint32_t pll2fracen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t pll2vcosel_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t pll2rge_bit : 2; // bit offset=6  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t pll3fracen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t pll3vcosel_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t pll3rge_bit : 2; // bit offset=10  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 6;
                uint32_t divp1en_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t divq1en_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t divr1en_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t divp2en_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t divq2en_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 1;
                uint32_t divr2en_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t divp3en_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13: 1;
                uint32_t divq3en_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved14: 1;
                uint32_t divr3en_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved15 : 8;
            } pllcfgr_bits;
        };
    } pllcfgr_reg;

    typedef struct pll1divr_reg_t {
        union {
            uint32_t pll1divr_reg;

            // bit fields
            struct {
                uint32_t divn1_bit : 9; // bit offset=0  bit width=9  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 8;
                uint32_t divp1_bit : 7; // bit offset=9  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 7;
                uint32_t divq1_bit : 7; // bit offset=16  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 8;
                uint32_t divr1_bit : 7; // bit offset=24  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved3 : 8;
            } pll1divr_bits;
        };
    } pll1divr_reg;

    uint32_t pll1fracr_reg;

    typedef struct pll2divr_reg_t {
        union {
            uint32_t pll2divr_reg;

            // bit fields
            struct {
                uint32_t divn2_bit : 9; // bit offset=0  bit width=9  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 8;
                uint32_t divp2_bit : 7; // bit offset=9  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 7;
                uint32_t divq2_bit : 7; // bit offset=16  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 8;
                uint32_t divr2_bit : 7; // bit offset=24  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved3 : 8;
            } pll2divr_bits;
        };
    } pll2divr_reg;

    uint32_t pll2fracr_reg;

    typedef struct pll3divr_reg_t {
        union {
            uint32_t pll3divr_reg;

            // bit fields
            struct {
                uint32_t divn3_bit : 9; // bit offset=0  bit width=9  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 8;
                uint32_t divp3_bit : 7; // bit offset=9  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 7;
                uint32_t divq3_bit : 7; // bit offset=16  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 8;
                uint32_t divr3_bit : 7; // bit offset=24  bit width=7  access=SVDAccessType.READ_WRITE
                uint32_t reserved3 : 8;
            } pll3divr_bits;
        };
    } pll3divr_reg;

    uint32_t pll3fracr_reg;

    typedef struct d1ccipr_reg_t {
        union {
            uint32_t d1ccipr_reg;

            // bit fields
            struct {
                uint32_t fmcsel_bit : 2; // bit offset=0  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t qspisel_bit : 2; // bit offset=4  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 12;
                uint32_t sdmmcsel_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 12;
                uint32_t ckpersel_bit : 2; // bit offset=28  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved3 : 4;
            } d1ccipr_bits;
        };
    } d1ccipr_reg;

    typedef struct d2ccip1r_reg_t {
        union {
            uint32_t d2ccip1r_reg;

            // bit fields
            struct {
                uint32_t sai1sel_bit : 3; // bit offset=0  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 5;
                uint32_t sai23sel_bit : 3; // bit offset=6  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 6;
                uint32_t spi123sel_bit : 3; // bit offset=12  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 4;
                uint32_t spi45sel_bit : 3; // bit offset=16  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 4;
                uint32_t spdifsel_bit : 2; // bit offset=20  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 4;
                uint32_t dfsdm1sel_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 4;
                uint32_t fdcansel_bit : 2; // bit offset=28  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 3;
                uint32_t swpsel_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7 : 1;
            } d2ccip1r_bits;
        };
    } d2ccip1r_reg;

    typedef struct d2ccip2r_reg_t {
        union {
            uint32_t d2ccip2r_reg;

            // bit fields
            struct {
                uint32_t usart234578sel_bit : 3; // bit offset=0  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 2;
                uint32_t usart16sel_bit : 3; // bit offset=3  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 5;
                uint32_t rngsel_bit : 2; // bit offset=8  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 4;
                uint32_t i2c123sel_bit : 2; // bit offset=12  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 8;
                uint32_t usbsel_bit : 2; // bit offset=20  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t cecsel_bit : 2; // bit offset=22  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 6;
                uint32_t lptim1sel_bit : 3; // bit offset=28  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved6 : 4;
            } d2ccip2r_bits;
        };
    } d2ccip2r_reg;

    typedef struct d3ccipr_reg_t {
        union {
            uint32_t d3ccipr_reg;

            // bit fields
            struct {
                uint32_t lpuart1sel_bit : 3; // bit offset=0  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 7;
                uint32_t i2c4sel_bit : 2; // bit offset=8  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t lptim2sel_bit : 3; // bit offset=10  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 3;
                uint32_t lptim345sel_bit : 3; // bit offset=13  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 3;
                uint32_t adcsel_bit : 2; // bit offset=16  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 5;
                uint32_t sai4asel_bit : 3; // bit offset=21  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 3;
                uint32_t sai4bsel_bit : 3; // bit offset=24  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 4;
                uint32_t spi6sel_bit : 3; // bit offset=28  bit width=3  access=SVDAccessType.READ_WRITE
                uint32_t reserved7 : 4;
            } d3ccipr_bits;
        };
    } d3ccipr_reg;

    typedef struct cier_reg_t {
        union {
            uint32_t cier_reg;

            // bit fields
            struct {
                uint32_t lsirdyie_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lserdyie_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hsirdyie_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hserdyie_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t csirdyie_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t rc48rdyie_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll1rdyie_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll2rdyie_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll3rdyie_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lsecssie_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0 : 22;
            } cier_bits;
        };
    } cier_reg;

    typedef struct cifr_reg_t {
        union {
            uint32_t cifr_reg;

            // bit fields
            struct {
                uint32_t lsirdyf_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lserdyf_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hsirdyf_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hserdyf_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t csirdy_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t rc48rdyf_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll1rdyf_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll2rdyf_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll3rdyf_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lsecssf_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hsecssf_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0 : 21;
            } cifr_bits;
        };
    } cifr_reg;

    typedef struct cicr_reg_t {
        union {
            uint32_t cicr_reg;

            // bit fields
            struct {
                uint32_t lsirdyc_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lserdyc_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hsirdyc_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hserdyc_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hse_ready_interrupt_clear_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t rc48rdyc_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll1rdyc_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll2rdyc_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t pll3rdyc_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lsecssc_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t hsecssc_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0 : 21;
            } cicr_bits;
        };
    } cicr_reg;

    typedef struct bdcr_reg_t {
        union {
            uint32_t bdcr_reg;

            // bit fields
            struct {
                uint32_t lseon_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lserdy_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lsebyp_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lsedrv_bit : 2; // bit offset=3  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 1;
                uint32_t lsecsson_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t lsecssd_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t rtcsrc_bit : 2; // bit offset=8  bit width=2  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 7;
                uint32_t rtcen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t vswrst_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 16;
            } bdcr_bits;
        };
    } bdcr_reg;

    typedef struct csr_reg_t {
        union {
            uint32_t csr_reg;

            // bit fields
            struct {
                uint32_t lsion_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lsirdy_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0 : 30;
            } csr_bits;
        };
    } csr_reg;

    typedef struct ahb3rstr_reg_t {
        union {
            uint32_t ahb3rstr_reg;

            // bit fields
            struct {
                uint32_t mdmarst_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t dma2drst_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t jpgdecrst_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 7;
                uint32_t fmcrst_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t qspirst_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t sdmmc1rst_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 15;
                uint32_t cpurst_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6 : 1;
            } ahb3rstr_bits;
        };
    } ahb3rstr_reg;

    typedef struct ahb1rstr_reg_t {
        union {
            uint32_t ahb1rstr_reg;

            // bit fields
            struct {
                uint32_t dma1rst_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t dma2rst_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t adc12rst_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 10;
                uint32_t eth1macrst_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 10;
                uint32_t usb1otgrst_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t usb2otgrst_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4 : 5;
            } ahb1rstr_bits;
        };
    } ahb1rstr_reg;

    typedef struct ahb2rstr_reg_t {
        union {
            uint32_t ahb2rstr_reg;

            // bit fields
            struct {
                uint32_t camitfrst_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t cryptrst_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t hashrst_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t rngrst_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 3;
                uint32_t sdmmc2rst_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4 : 23;
            } ahb2rstr_bits;
        };
    } ahb2rstr_reg;

    typedef struct ahb4rstr_reg_t {
        union {
            uint32_t ahb4rstr_reg;

            // bit fields
            struct {
                uint32_t gpioarst_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiobrst_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiocrst_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiodrst_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioerst_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiofrst_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiogrst_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiohrst_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioirst_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiojrst_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiokrst_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 8;
                uint32_t crcrst_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t bdmarst_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 3;
                uint32_t adc3rst_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t hsemrst_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4 : 7;
            } ahb4rstr_bits;
        };
    } ahb4rstr_reg;

    uint32_t apb3rstr_reg;

    typedef struct apb1lrstr_reg_t {
        union {
            uint32_t apb1lrstr_reg;

            // bit fields
            struct {
                uint32_t tim2rst_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim3rst_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim4rst_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim5rst_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim6rst_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim7rst_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim12rst_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim13rst_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim14rst_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lptim1rst_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 4;
                uint32_t spi2rst_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t spi3rst_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t spdifrxrst_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t usart2rst_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t usart3rst_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t uart4rst_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t uart5rst_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t i2c1rst_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t i2c2rst_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t i2c3rst_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 4;
                uint32_t cecrst_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 2;
                uint32_t dac12rst_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t usart7rst_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13: 1;
                uint32_t usart8rst_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved14 : 1;
            } apb1lrstr_bits;
        };
    } apb1lrstr_reg;

    typedef struct apb1hrstr_reg_t {
        union {
            uint32_t apb1hrstr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t crsrst_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t swprst_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t opamprst_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t mdiosrst_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t fdcanrst_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 24;
            } apb1hrstr_bits;
        };
    } apb1hrstr_reg;

    typedef struct apb2rstr_reg_t {
        union {
            uint32_t apb2rstr_reg;

            // bit fields
            struct {
                uint32_t tim1rst_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim8rst_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 2;
                uint32_t usart1rst_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t usart6rst_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 7;
                uint32_t spi1rst_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t spi4rst_bit : 1; // bit offset=13  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t tim15rst_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t tim16rst_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t tim17rst_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 2;
                uint32_t spi5rst_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t sai1rst_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t sai2rst_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t sai3rst_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 4;
                uint32_t dfsdm1rst_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t hrtimrst_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13 : 3;
            } apb2rstr_bits;
        };
    } apb2rstr_reg;

    typedef struct apb4rstr_reg_t {
        union {
            uint32_t apb4rstr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t syscfgrst_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t lpuart1rst_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t spi6rst_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t i2c4rst_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t lptim2rst_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t lptim3rst_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t lptim4rst_bit : 1; // bit offset=11  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t lptim5rst_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t comp12rst_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t vrefrst_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 6;
                uint32_t sai4rst_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11 : 11;
            } apb4rstr_bits;
        };
    } apb4rstr_reg;

    uint32_t gcr_reg;

    typedef struct d3amr_reg_t {
        union {
            uint32_t d3amr_reg;

            // bit fields
            struct {
                uint32_t bdmaamen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 2;
                uint32_t lpuart1amen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t spi6amen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t i2c4amen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t lptim2amen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t lptim3amen_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t lptim4amen_bit : 1; // bit offset=11  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t lptim5amen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 2;
                uint32_t comp12amen_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t vrefamen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t rtcamen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 3;
                uint32_t crcamen_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 2;
                uint32_t sai4amen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 3;
                uint32_t adc3amen_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13: 4;
                uint32_t bkpramamen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved14: 1;
                uint32_t sram4amen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved15 : 3;
            } d3amr_bits;
        };
    } d3amr_reg;

    typedef struct rsr_reg_t {
        union {
            uint32_t rsr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 16;
                uint32_t rmvf_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t cpurstf_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t d1rstf_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t d2rstf_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t borrstf_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t pinrstf_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t porrstf_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t sftrstf_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t iwdg1rstf_bit : 1; // bit offset=26  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 2;
                uint32_t wwdg1rstf_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 2;
                uint32_t lpwrrstf_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11 : 2;
            } rsr_bits;
        };
    } rsr_reg;

    typedef struct c1_rsr_reg_t {
        union {
            uint32_t c1_rsr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 16;
                uint32_t rmvf_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t cpurstf_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t d1rstf_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t d2rstf_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t borrstf_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t pinrstf_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t porrstf_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t sftrstf_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t iwdg1rstf_bit : 1; // bit offset=26  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 2;
                uint32_t wwdg1rstf_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 2;
                uint32_t lpwrrstf_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11 : 2;
            } c1_rsr_bits;
        };
    } c1_rsr_reg;

    typedef struct c1_ahb3enr_reg_t {
        union {
            uint32_t c1_ahb3enr_reg;

            // bit fields
            struct {
                uint32_t mdmaen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t dma2den_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t jpgdecen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 7;
                uint32_t fmcen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t qspien_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t sdmmc1en_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 16;
            } c1_ahb3enr_bits;
        };
    } c1_ahb3enr_reg;

    typedef struct ahb3enr_reg_t {
        union {
            uint32_t ahb3enr_reg;

            // bit fields
            struct {
                uint32_t mdmaen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t dma2den_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t jpgdecen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 7;
                uint32_t fmcen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t qspien_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t sdmmc1en_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 16;
            } ahb3enr_bits;
        };
    } ahb3enr_reg;

    typedef struct ahb1enr_reg_t {
        union {
            uint32_t ahb1enr_reg;

            // bit fields
            struct {
                uint32_t dma1en_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t dma2en_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t adc12en_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 10;
                uint32_t eth1macen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t eth1txen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t eth1rxen_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 8;
                uint32_t usb1otghsen_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t usb1otghsulpien_bit : 1; // bit offset=26  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t usb2otghsen_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t usb2otghsulpien_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8 : 4;
            } ahb1enr_bits;
        };
    } ahb1enr_reg;

    typedef struct c1_ahb1enr_reg_t {
        union {
            uint32_t c1_ahb1enr_reg;

            // bit fields
            struct {
                uint32_t dma1en_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t dma2en_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t adc12en_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 10;
                uint32_t eth1macen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t eth1txen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t eth1rxen_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 8;
                uint32_t usb1otghsen_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t usb1otghsulpien_bit : 1; // bit offset=26  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t usb2otghsen_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t usb2otghsulpien_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8 : 4;
            } c1_ahb1enr_bits;
        };
    } c1_ahb1enr_reg;

    typedef struct c1_ahb2enr_reg_t {
        union {
            uint32_t c1_ahb2enr_reg;

            // bit fields
            struct {
                uint32_t dcmien_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t crypten_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t hashen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t rngen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 3;
                uint32_t sdmmc2en_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 20;
                uint32_t sram1en_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t sram2en_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t sram3en_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7 : 1;
            } c1_ahb2enr_bits;
        };
    } c1_ahb2enr_reg;

    typedef struct ahb2enr_reg_t {
        union {
            uint32_t ahb2enr_reg;

            // bit fields
            struct {
                uint32_t dcmien_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t crypten_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t hashen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t rngen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 3;
                uint32_t sdmmc2en_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 20;
                uint32_t sram1en_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t sram2en_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t sram3en_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7 : 1;
            } ahb2enr_bits;
        };
    } ahb2enr_reg;

    typedef struct ahb4enr_reg_t {
        union {
            uint32_t ahb4enr_reg;

            // bit fields
            struct {
                uint32_t gpioaen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioben_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiocen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioden_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioeen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiofen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiogen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiohen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioien_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiojen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioken_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 8;
                uint32_t crcen_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t bdmaen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 3;
                uint32_t adc3en_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t hsemen_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t bkpramen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 4;
            } ahb4enr_bits;
        };
    } ahb4enr_reg;

    typedef struct c1_ahb4enr_reg_t {
        union {
            uint32_t c1_ahb4enr_reg;

            // bit fields
            struct {
                uint32_t gpioaen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioben_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiocen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioden_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioeen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiofen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiogen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiohen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioien_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiojen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioken_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 8;
                uint32_t crcen_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t bdmaen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 3;
                uint32_t adc3en_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t hsemen_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t bkpramen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 4;
            } c1_ahb4enr_bits;
        };
    } c1_ahb4enr_reg;

    typedef struct c1_apb3enr_reg_t {
        union {
            uint32_t c1_apb3enr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 3;
                uint32_t ltdcen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 3;
                uint32_t wwdg1en_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2 : 26;
            } c1_apb3enr_bits;
        };
    } c1_apb3enr_reg;

    typedef struct apb3enr_reg_t {
        union {
            uint32_t apb3enr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 3;
                uint32_t ltdcen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 3;
                uint32_t wwdg1en_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2 : 26;
            } apb3enr_bits;
        };
    } apb3enr_reg;

    typedef struct apb1lenr_reg_t {
        union {
            uint32_t apb1lenr_reg;

            // bit fields
            struct {
                uint32_t tim2en_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim3en_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim4en_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim5en_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim6en_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim7en_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim12en_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim13en_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim14en_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lptim1en_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 4;
                uint32_t spi2en_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t spi3en_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t spdifrxen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t usart2en_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t usart3en_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t uart4en_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t uart5en_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t i2c1en_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t i2c2en_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t i2c3en_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 4;
                uint32_t cecen_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 2;
                uint32_t dac12en_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t usart7en_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13: 1;
                uint32_t usart8en_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved14 : 1;
            } apb1lenr_bits;
        };
    } apb1lenr_reg;

    typedef struct c1_apb1lenr_reg_t {
        union {
            uint32_t c1_apb1lenr_reg;

            // bit fields
            struct {
                uint32_t tim2en_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim3en_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim4en_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim5en_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim6en_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim7en_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim12en_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim13en_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim14en_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lptim1en_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 4;
                uint32_t spi2en_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t spi3en_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t spdifrxen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t usart2en_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t usart3en_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t uart4en_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t uart5en_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t i2c1en_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t i2c2en_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t i2c3en_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 4;
                uint32_t hdmicecen_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 2;
                uint32_t dac12en_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t usart7en_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13: 1;
                uint32_t usart8en_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved14 : 1;
            } c1_apb1lenr_bits;
        };
    } c1_apb1lenr_reg;

    typedef struct apb1henr_reg_t {
        union {
            uint32_t apb1henr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t crsen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t swpen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t opampen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t mdiosen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t fdcanen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 24;
            } apb1henr_bits;
        };
    } apb1henr_reg;

    typedef struct c1_apb1henr_reg_t {
        union {
            uint32_t c1_apb1henr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t crsen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t swpen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t opampen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t mdiosen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t fdcanen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 24;
            } c1_apb1henr_bits;
        };
    } c1_apb1henr_reg;

    typedef struct c1_apb2enr_reg_t {
        union {
            uint32_t c1_apb2enr_reg;

            // bit fields
            struct {
                uint32_t tim1en_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim8en_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 2;
                uint32_t usart1en_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t usart6en_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 7;
                uint32_t spi1en_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t spi4en_bit : 1; // bit offset=13  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 4;
                uint32_t tim16en_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim15en_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim17en_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t spi5en_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 2;
                uint32_t sai1en_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t sai2en_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t sai3en_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 4;
                uint32_t dfsdm1en_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t hrtimen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11 : 3;
            } c1_apb2enr_bits;
        };
    } c1_apb2enr_reg;

    typedef struct apb2enr_reg_t {
        union {
            uint32_t apb2enr_reg;

            // bit fields
            struct {
                uint32_t tim1en_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim8en_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 2;
                uint32_t usart1en_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t usart6en_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 7;
                uint32_t spi1en_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t spi4en_bit : 1; // bit offset=13  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 4;
                uint32_t tim16en_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim15en_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim17en_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t spi5en_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 2;
                uint32_t sai1en_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t sai2en_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t sai3en_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 4;
                uint32_t dfsdm1en_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t hrtimen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11 : 3;
            } apb2enr_bits;
        };
    } apb2enr_reg;

    typedef struct apb4enr_reg_t {
        union {
            uint32_t apb4enr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t syscfgen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t lpuart1en_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t spi6en_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t i2c4en_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t lptim2en_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t lptim3en_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t lptim4en_bit : 1; // bit offset=11  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t lptim5en_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t comp12en_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t vrefen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t rtcapben_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 5;
                uint32_t sai4en_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12 : 11;
            } apb4enr_bits;
        };
    } apb4enr_reg;

    typedef struct c1_apb4enr_reg_t {
        union {
            uint32_t c1_apb4enr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t syscfgen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t lpuart1en_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t spi6en_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t i2c4en_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t lptim2en_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t lptim3en_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t lptim4en_bit : 1; // bit offset=11  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t lptim5en_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t comp12en_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t vrefen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t rtcapben_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 5;
                uint32_t sai4en_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12 : 11;
            } c1_apb4enr_bits;
        };
    } c1_apb4enr_reg;

    typedef struct c1_ahb3lpenr_reg_t {
        union {
            uint32_t c1_ahb3lpenr_reg;

            // bit fields
            struct {
                uint32_t mdmalpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t dma2dlpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t jpgdeclpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 3;
                uint32_t flitflpen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 4;
                uint32_t fmclpen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t qspilpen_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 2;
                uint32_t sdmmc1lpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 12;
                uint32_t d1dtcm1lpen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t dtcm2lpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t itcmlpen_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t axisramlpen_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10 : 1;
            } c1_ahb3lpenr_bits;
        };
    } c1_ahb3lpenr_reg;

    typedef struct ahb3lpenr_reg_t {
        union {
            uint32_t ahb3lpenr_reg;

            // bit fields
            struct {
                uint32_t mdmalpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t dma2dlpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t jpgdeclpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 3;
                uint32_t flashlpen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 4;
                uint32_t fmclpen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t qspilpen_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 2;
                uint32_t sdmmc1lpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 12;
                uint32_t d1dtcm1lpen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t dtcm2lpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t itcmlpen_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t axisramlpen_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10 : 1;
            } ahb3lpenr_bits;
        };
    } ahb3lpenr_reg;

    typedef struct ahb1lpenr_reg_t {
        union {
            uint32_t ahb1lpenr_reg;

            // bit fields
            struct {
                uint32_t dma1lpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t dma2lpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t adc12lpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 10;
                uint32_t eth1maclpen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t eth1txlpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t eth1rxlpen_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 8;
                uint32_t usb1otghslpen_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t usb1otghsulpilpen_bit : 1; // bit offset=26  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t usb2otghslpen_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t usb2otghsulpilpen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8 : 4;
            } ahb1lpenr_bits;
        };
    } ahb1lpenr_reg;

    typedef struct c1_ahb1lpenr_reg_t {
        union {
            uint32_t c1_ahb1lpenr_reg;

            // bit fields
            struct {
                uint32_t dma1lpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t dma2lpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t adc12lpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 10;
                uint32_t eth1maclpen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t eth1txlpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t eth1rxlpen_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 8;
                uint32_t usb1otglpen_bit : 1; // bit offset=25  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t usb1ulpilpen_bit : 1; // bit offset=26  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t usb2otglpen_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t usb2ulpilpen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8 : 4;
            } c1_ahb1lpenr_bits;
        };
    } c1_ahb1lpenr_reg;

    typedef struct c1_ahb2lpenr_reg_t {
        union {
            uint32_t c1_ahb2lpenr_reg;

            // bit fields
            struct {
                uint32_t camitflpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t cryptlpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t hashlpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 4;
                uint32_t sdmmc2lpen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t rnglpen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 19;
                uint32_t sram1lpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t sram2lpen_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t sram3lpen_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6 : 1;
            } c1_ahb2lpenr_bits;
        };
    } c1_ahb2lpenr_reg;

    typedef struct ahb2lpenr_reg_t {
        union {
            uint32_t ahb2lpenr_reg;

            // bit fields
            struct {
                uint32_t camitflpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 3;
                uint32_t cryptlpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t hashlpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 4;
                uint32_t sdmmc2lpen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t rnglpen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 19;
                uint32_t sram1lpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t sram2lpen_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t sram3lpen_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6 : 1;
            } ahb2lpenr_bits;
        };
    } ahb2lpenr_reg;

    typedef struct ahb4lpenr_reg_t {
        union {
            uint32_t ahb4lpenr_reg;

            // bit fields
            struct {
                uint32_t gpioalpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioblpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioclpen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiodlpen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioelpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioflpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioglpen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiohlpen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioilpen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiojlpen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioklpen_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 8;
                uint32_t crclpen_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t bdmalpen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 3;
                uint32_t adc3lpen_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 4;
                uint32_t bkpramlpen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t sram4lpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 3;
            } ahb4lpenr_bits;
        };
    } ahb4lpenr_reg;

    typedef struct c1_ahb4lpenr_reg_t {
        union {
            uint32_t c1_ahb4lpenr_reg;

            // bit fields
            struct {
                uint32_t gpioalpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioblpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioclpen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiodlpen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioelpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioflpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioglpen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiohlpen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioilpen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpiojlpen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t gpioklpen_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 8;
                uint32_t crclpen_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t bdmalpen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 3;
                uint32_t adc3lpen_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 4;
                uint32_t bkpramlpen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t sram4lpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 3;
            } c1_ahb4lpenr_bits;
        };
    } c1_ahb4lpenr_reg;

    typedef struct c1_apb3lpenr_reg_t {
        union {
            uint32_t c1_apb3lpenr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 3;
                uint32_t ltdclpen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 3;
                uint32_t wwdg1lpen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2 : 26;
            } c1_apb3lpenr_bits;
        };
    } c1_apb3lpenr_reg;

    typedef struct apb3lpenr_reg_t {
        union {
            uint32_t apb3lpenr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 3;
                uint32_t ltdclpen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 3;
                uint32_t wwdg1lpen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2 : 26;
            } apb3lpenr_bits;
        };
    } apb3lpenr_reg;

    typedef struct apb1llpenr_reg_t {
        union {
            uint32_t apb1llpenr_reg;

            // bit fields
            struct {
                uint32_t tim2lpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim3lpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim4lpen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim5lpen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim6lpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim7lpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim12lpen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim13lpen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim14lpen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lptim1lpen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 4;
                uint32_t spi2lpen_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t spi3lpen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t spdifrxlpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t usart2lpen_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t usart3lpen_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t uart4lpen_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t uart5lpen_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t i2c1lpen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t i2c2lpen_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t i2c3lpen_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 4;
                uint32_t hdmiceclpen_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 2;
                uint32_t dac12lpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t usart7lpen_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13: 1;
                uint32_t usart8lpen_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved14 : 1;
            } apb1llpenr_bits;
        };
    } apb1llpenr_reg;

    typedef struct c1_apb1llpenr_reg_t {
        union {
            uint32_t c1_apb1llpenr_reg;

            // bit fields
            struct {
                uint32_t tim2lpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim3lpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim4lpen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim5lpen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim6lpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim7lpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim12lpen_bit : 1; // bit offset=6  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim13lpen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim14lpen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t lptim1lpen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 4;
                uint32_t spi2lpen_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t spi3lpen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 1;
                uint32_t spdifrxlpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t usart2lpen_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 1;
                uint32_t usart3lpen_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t uart4lpen_bit : 1; // bit offset=19  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t uart5lpen_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t i2c1lpen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 1;
                uint32_t i2c2lpen_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t i2c3lpen_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 4;
                uint32_t hdmiceclpen_bit : 1; // bit offset=27  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 2;
                uint32_t dac12lpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t usart7lpen_bit : 1; // bit offset=30  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13: 1;
                uint32_t usart8lpen_bit : 1; // bit offset=31  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved14 : 1;
            } c1_apb1llpenr_bits;
        };
    } c1_apb1llpenr_reg;

    typedef struct c1_apb1hlpenr_reg_t {
        union {
            uint32_t c1_apb1hlpenr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t crslpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t swplpen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t opamplpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t mdioslpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t fdcanlpen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 24;
            } c1_apb1hlpenr_bits;
        };
    } c1_apb1hlpenr_reg;

    typedef struct apb1hlpenr_reg_t {
        union {
            uint32_t apb1hlpenr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t crslpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t swplpen_bit : 1; // bit offset=2  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t opamplpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t mdioslpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t fdcanlpen_bit : 1; // bit offset=8  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5 : 24;
            } apb1hlpenr_bits;
        };
    } apb1hlpenr_reg;

    typedef struct apb2lpenr_reg_t {
        union {
            uint32_t apb2lpenr_reg;

            // bit fields
            struct {
                uint32_t tim1lpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim8lpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 2;
                uint32_t usart1lpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t usart6lpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 7;
                uint32_t spi1lpen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t spi4lpen_bit : 1; // bit offset=13  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t tim15lpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t tim16lpen_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t tim17lpen_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 2;
                uint32_t spi5lpen_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t sai1lpen_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t sai2lpen_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t sai3lpen_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 4;
                uint32_t dfsdm1lpen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t hrtimlpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13 : 3;
            } apb2lpenr_bits;
        };
    } apb2lpenr_reg;

    typedef struct c1_apb2lpenr_reg_t {
        union {
            uint32_t c1_apb2lpenr_reg;

            // bit fields
            struct {
                uint32_t tim1lpen_bit : 1; // bit offset=0  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t tim8lpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved0: 2;
                uint32_t usart1lpen_bit : 1; // bit offset=4  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 1;
                uint32_t usart6lpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 7;
                uint32_t spi1lpen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 1;
                uint32_t spi4lpen_bit : 1; // bit offset=13  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 3;
                uint32_t tim15lpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t tim16lpen_bit : 1; // bit offset=17  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t tim17lpen_bit : 1; // bit offset=18  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 2;
                uint32_t spi5lpen_bit : 1; // bit offset=20  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t sai1lpen_bit : 1; // bit offset=22  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t sai2lpen_bit : 1; // bit offset=23  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t sai3lpen_bit : 1; // bit offset=24  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 4;
                uint32_t dfsdm1lpen_bit : 1; // bit offset=28  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12: 1;
                uint32_t hrtimlpen_bit : 1; // bit offset=29  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved13 : 3;
            } c1_apb2lpenr_bits;
        };
    } c1_apb2lpenr_reg;

    typedef struct c1_apb4lpenr_reg_t {
        union {
            uint32_t c1_apb4lpenr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t syscfglpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t lpuart1lpen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t spi6lpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t i2c4lpen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t lptim2lpen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t lptim3lpen_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t lptim4lpen_bit : 1; // bit offset=11  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t lptim5lpen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t comp12lpen_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t vreflpen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t rtcapblpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 5;
                uint32_t sai4lpen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12 : 11;
            } c1_apb4lpenr_bits;
        };
    } c1_apb4lpenr_reg;

    typedef struct apb4lpenr_reg_t {
        union {
            uint32_t apb4lpenr_reg;

            // bit fields
            struct {
                uint32_t reserved0: 1;
                uint32_t syscfglpen_bit : 1; // bit offset=1  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved1: 2;
                uint32_t lpuart1lpen_bit : 1; // bit offset=3  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved2: 2;
                uint32_t spi6lpen_bit : 1; // bit offset=5  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved3: 2;
                uint32_t i2c4lpen_bit : 1; // bit offset=7  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved4: 2;
                uint32_t lptim2lpen_bit : 1; // bit offset=9  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved5: 1;
                uint32_t lptim3lpen_bit : 1; // bit offset=10  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved6: 1;
                uint32_t lptim4lpen_bit : 1; // bit offset=11  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved7: 1;
                uint32_t lptim5lpen_bit : 1; // bit offset=12  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved8: 2;
                uint32_t comp12lpen_bit : 1; // bit offset=14  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved9: 1;
                uint32_t vreflpen_bit : 1; // bit offset=15  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved10: 1;
                uint32_t rtcapblpen_bit : 1; // bit offset=16  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved11: 5;
                uint32_t sai4lpen_bit : 1; // bit offset=21  bit width=1  access=SVDAccessType.READ_WRITE
                uint32_t reserved12 : 11;
            } apb4lpenr_bits;
        };
    } apb4lpenr_reg;

} rcc_t;
