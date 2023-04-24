/*
 * RCC_register.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Al-Hasan Ameer
 */

#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_

/*RCC BASE ADDRESS*/
#define RCC_BASEADD    0x40021000UL

/*RCC registers Structure definition*/
typedef struct
{
	uint32_t CR;				/*Clock control register*/
	uint32_t CFGR;				/*Clock configuration register*/
	uint32_t CIR;				/*Clock interrupt register*/
	uint32_t APB2RSTR;			/*APB2 peripheral reset register*/
	uint32_t APB1RSTR;			/*APB1 peripheral reset register*/
	uint32_t AHBENR;			/*AHB peripheral clock enable register*/
	uint32_t APB2ENR;			/*APB2 peripheral clock enable register*/
	uint32_t APB1ENR;			/*APB1 peripheral clock enable register*/
	uint32_t BDCR;				/*Backup domain control register*/
	uint32_t CSR;				/*Control/status register */

}RCC_Reg_t;



/*CR Register bits definition*/
#define CR_PLLRDY              25
#define CR_PLLON               24
#define CR_CSSON               19
#define CR_HSEBYP              18
#define CR_HSERDY              17
#define CR_HSEON               16
#define CR_HSICAL7             15
#define CR_HSICAL6             14
#define CR_HSICAL5             13
#define CR_HSICAL4             12
#define CR_HSICAL3             11
#define CR_HSICAL2             10
#define CR_HSICAL1              9
#define CR_HSICAL0              8
#define CR_HSITRM4              7
#define CR_HSITRM3              6
#define CR_HSITRM2              5
#define CR_HSITRM1              4
#define CR_HSITRM0              3
#define CR_HSIRDY               1
#define CR_HSION                0


/*CFGR Register bits definition*/
#define CFGR_MCO2              26
#define CFGR_MCO1              25
#define CFGR_MCO0              23
#define CFGR_USBPRE            22
#define CFGR_PLLMUL3           21
#define CFGR_PLLMUL2           20
#define CFGR_PLLMUL1           19
#define CFGR_PLLMUL0           18
#define CFGR_PLLXTPRE          17
#define CFGR_PLLSRC            16
#define CFGR_ADCPRE1           15
#define CFGR_ADCPRE0           14
#define CFGR_PPRE22            13
#define CFGR_PPRE21            12
#define CFGR_PPRE20            11
#define CFGR_PPRE12            10
#define CFGR_PPRE11             9
#define CFGR_PPRE10             8
#define CFGR_HPRE3              7
#define CFGR_HPRE2              6
#define CFGR_HPRE1              5
#define CFGR_HPRE0              4
#define CFGR_SWS1               3
#define CFGR_SWS0               2
#define CFGR_SW1                1
#define CFGR_SW0                0


/*CIR Register bits definition*/
#define CIR_CSSC               22
#define CIR_PLLRDYC            20
#define CIR_HSERDYC            19
#define CIR_HSIRDYC            18
#define CIR_LSERDYC            17
#define CIR_LSIRDYC            16
#define CIR_PLLRDYIE           12
#define CIR_HSERDYIE           11
#define CIR_HSIRDYIE           10
#define CIR_LSERDYIE            9
#define CIR_LSIRDYIE            8
#define CIR_CSSF                7
#define CIR_PLLRDYF             4
#define CIR_HSERDYF             3
#define CIR_HSIRDYF             2
#define CIR_LSERDYF             1
#define CIR_LSIRDYF             0


/*APB2RSTR Register bits definition*/
#define APB2RSTR_TIM11RST      21
#define APB2RSTR_TIM10RST      20
#define APB2RSTR_TIM9RST       19
#define APB2RSTR_ADC3RST       15
#define APB2RSTR_USART1RST     14
#define APB2RSTR_TIM8RST       13
#define APB2RSTR_SPI1RST       12
#define APB2RSTR_TIM1RST       11
#define APB2RSTR_ADC2RST       10
#define APB2RSTR_ADC1RST        9
#define APB2RSTR_I0PGRST        8
#define APB2RSTR_IOPFRST        7
#define APB2RSTR_IOPERST        6
#define APB2RSTR_TOPDRST        5
#define APB2RSTR_IOPCRST        4
#define APB2RSTR_IOPBRST        3
#define APB2RSTR_IOPARST        2
#define APB2RSTR_AFIORST        0


/*APB1RSTR Register bits definition*/
#define APB1RSTR_DACRST         29
#define APB1RSTR_PWRRST         28
#define APB1RSTR_BKPRST         27
#define APB1RSTR_CANRST         25
#define APB1RSTR_USBRST         23
#define APB1RSTR_I2C2RST        22
#define APB1RSTR_I2C1RST        21
#define APB1RSTR_UART5RST       20
#define APB1RSTR_UART4RST       19
#define APB1RSTR_USART3RST      18
#define APB1RSTR_USART2RST      17
#define APB1RSTR_SPI3RST        15
#define APB1RSTR_SPI2RST        14
#define APB1RSTR_WWDGRST        11
#define APB1RSTR_TIM14RST        8
#define APB1RSTR_TIM13RST        7
#define APB1RSTR_TIM12RST        6
#define APB1RSTR_TIM7RST         5
#define APB1RSTR_TIM6RST         4
#define APB1RSTR_TIM5RST         3
#define APB1RSTR_TIM4RST         2
#define APB1RSTR_TIM3RST         1
#define APB1RSTR_TIM2RST         0


/*AHBENR Register bits definition*/
#define AHBENR_SDIOEN           10
#define AHBENR_FSMCEN            8
#define AHBENR_CRCEN             6
#define AHBENR_FLITFEN           4
#define AHBENR_SRAMEN            2
#define AHBENR_DMA2EN            1
#define AHBENR_DMA1EN            0


/*APB2RENR Register bits definition*/
#define APB2ENR_TIM11EN         21
#define APB2ENR_TIM10EN         20
#define APB2ENR_TIM9EN          19
#define APB2ENR_ADC3EN          15
#define APB2ENR_USART1EN        14
#define APB2ENR_TIM8EN          13
#define APB2ENR_SPI1EN          12
#define APB2ENR_TIM1EN          11
#define APB2ENR_ADC2EN          10
#define APB2ENR_ADC1EN           9
#define APB2ENR_I0PGEN           8
#define APB2ENR_IOPFEN           7
#define APB2ENR_IOPEEN           6
#define APB2ENR_TOPDEN           5
#define APB2ENR_IOPCEN           4
#define APB2ENR_IOPBEN           3
#define APB2ENR_IOPAEN           2
#define APB2ENR_AFIOEN           0


/*APB1RENR Register bits definition*/
#define APB1ENR_DACEN           29
#define APB1ENR_PWREN           28
#define APB1ENR_BKPEN           27
#define APB1ENR_CANEN           25
#define APB1ENR_USBEN           23
#define APB1ENR_I2C2EN          22
#define APB1ENR_I2C1EN          21
#define APB1ENR_UART5EN         20
#define APB1ENR_UART4EN         19
#define APB1ENR_USART3EN        18
#define APB1ENR_USART2EN        17
#define APB1ENR_SPI3EN          15
#define APB1ENR_SPI2EN          14
#define APB1ENR_WWDGEN          11
#define APB1ENR_TIM14EN          8
#define APB1ENR_TIM13EN          7
#define APB1ENR_TIM12EN          6
#define APB1ENR_TIM7EN           5
#define APB1ENR_TIM6EN           4
#define APB1ENR_TIM5EN           3
#define APB1ENR_TIM4EN           2
#define APB1ENR_TIM3EN           1
#define APB1ENR_TIM2EN           0


/*BDCR Register bits definition*/
#define BDCR_BDRST              16
#define BDCR_RTCEN              15
#define BDCR_LSEBYP              2
#define BDCR_LSERDY              1
#define BDCR_LSEON               0


/*CSR Register bits definition*/
#define CSR_LPWRSTF             31
#define CSR_WWDGRSTF            30
#define CSR_WDGRSTF             29
#define CSR_SFTRSTF             28
#define CSR_PORRSTF             27
#define CSR_PINRSTF             26
#define CSR_RMVF                24
#define CSR_LSIRDY               1
#define CSR_LSION                0

/*MCO Definition*/
#define MCO_NOCLK       0b011
#define MCO_SYSCLK      0b100
#define MCO_HSICLK      0b101
#define MCO_HSECLK      0b110
#define MCO_PLLCLK      0b111

/*PLLMUL -PLL Multiplication factor- Definition*/
#define PLLMUL_2        0b0000
#define PLLMUL_3        0b0001
#define PLLMUL_4        0b0010
#define PLLMUL_5        0b0011
#define PLLMUL_6        0b0100
#define PLLMUL_7        0b0101
#define PLLMUL_8        0b0110
#define PLLMUL_9        0b0111
#define PLLMUL_10       0b1000
#define PLLMUL_11       0b1001
#define PLLMUL_12       0b1010
#define PLLMUL_13       0b1011
#define PLLMUL_14       0b1100
#define PLLMUL_15       0b1101
#define PLLMUL_16       0b1110
#define PLLMUL_16_      0b1111

/*ADCPRE -ADC preScaler- Definition*/
#define ADCPRE_2        0b00
#define ADCPRE_4        0b01
#define ADCPRE_6        0b10
#define ADCPRE_8	    0b11

/*PPRE2 -APB high-speed preScaler (APB2)- Definition*/
#define PPRE2_NO        0b011
#define PPRE2_2         0b100
#define PPRE2_4         0b101
#define PPRE2_8         0b110
#define PPRE2_16        0b111

/*PPRE1 -APB high-speed preScaler (APB1)- Definition*/
#define PPRE1_NOTDIV    0b011
#define PPRE1_DIV2      0b100
#define PPRE1_DIV4      0b101
#define PPRE1_DIV8      0b110
#define PPRE1_DIV16     0b111

/*HPRE -AHP PreScaler- Definition*/
#define HPRE_NOTDIV     0b0000
#define HPRE_DIV2       0b1000
#define HPRE_DIV4       0b1001
#define HPRE_DIV8       0b1010
#define HPRE_DIV16      0b1011
#define HPRE_DIV64      0b1100
#define HPRE_DIV128     0b1101
#define HPRE_DIV256     0b1110
#define HPRE_DIV512     0b1111

/*SWS -System clock switch status*/
#define SWS_HSI         0b00
#define SWS_HSE         0b01
#define SWS_PLL         0b10
#define SWS_NOT         0b11

/*SW -System clock switch*/
#define SW_HSI          0b00
#define SW_HSE          0b01
#define SW_PLL          0b10
#define SW_NOT          0b11

/*RTCSEL -RTC clock Source Selection*/
#define RTCSEL_NOCLK    0b00
#define RTCSEL_LSECLK   0b01
#define RTCSEL_LSICLK   0b10
#define RTCSEL_HSECLK   0b11



#endif /* RCC_REGISTER_H_ */
