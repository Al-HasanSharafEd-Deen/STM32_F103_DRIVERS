/*
 * RCC_private.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Al-Hasan Ameer
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


/*REG. Masks*/
#define PLLMUL_MASK    0b1111


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


#endif /* RCC_PRIVATE_H_ */
