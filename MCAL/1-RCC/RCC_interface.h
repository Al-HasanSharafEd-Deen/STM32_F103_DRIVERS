/*
 * RCC_interface.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Al-Hasan Ameer
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* CLOCK SOURCE TYPE ENUM*/
typedef enum{
	RCC_HSI,
	RCC_HSE,
	RCC_PLL
}RCC_CLKTYPE_t;
/*******************************************************************************************************/
/*clock status ENUM*/
typedef enum{
	RCC_ON,
	RCC_OFF
}RCC_CLKSTATE_t;
/*******************************************************************************************************/
/*HSE Divide ENUM*/
typedef enum{
	HSE_DIVIDED_1,
	HSE_DIVIDED_2
}HSE_DIVIDE_t;
/*******************************************************************************************************/
/*HSE PYPASS State ENUM*/
typedef enum{
	HSE_NOTBYPASSED,
	HSE_BYPASSED
}HSE_PYPASS_t;
/*******************************************************************************************************/
/*PLL CLK Source ENUM*/
typedef enum{
	PLLSRC_HSI_2,
	PLLSRC_HSE
}PLLSRC_t;
/*******************************************************************************************************/
/*Peripheral Enable-Disable ENUM*/
typedef enum{
	PERIPH_ENABLE,
	PERIPH_DISABLE
}PERIPH_STATE_t;
/*******************************************************************************************************/

/*RCC Set Clock Status Function*
 * Brief: by this function we can set the RCC clock Source status (ON or OFF)*
 * input:  Copy_RCCState ( RCC_ON,
	                       RCC_OFF).
 * output: Local_u8ErrorState
 */
uint8_t RCC_u8CLKStateSync(RCC_CLKSTATE_t Copy_RCCState);
/*******************************************************************************************************/

/*RCC Set System Clock Function*
 * Brief: by this function we can set the RCC clock Source*
 * input:  void
 * output: void
 */
void RCC_voidSetSYSCLK(void);
/*******************************************************************************************************/

/*RCC Set HSE Configuration Function*
 * Brief: by this function we can set the HSE Configuration (divide and bypass) and set HSE as a PLL CLK Source*
 * input: 1- Copy_HSEDivider (HSE_DIVIDED_1,
	                          HSE_DIVIDED_2).

	      2- Copy_HSEBypass  (HSE_NOTBYPASSED,
	                          HSE_BYPASSED).
 * output: Local_u8ErrorState
 */
uint8_t RCC_u8HSEConfig(HSE_DIVIDE_t Copy_HSEDivide, HSE_PYPASS_t Copy_HSEBypass);
/*******************************************************************************************************/

/*RCC Set PLL Configuration Function*
 * Brief: by this function we can set the PLL Configuration (multiplication Factor and PLLCLK Source)
 * input: 1- Copy_u8PLLMULL  ( PLLMUL_2,
                               PLLMUL_3,
                               PLLMUL_4,
                               PLLMUL_5,
                               PLLMUL_6,
                               PLLMUL_7,
                               PLLMUL_8,
                               PLLMUL_9,
                               PLLMUL_10,
                               PLLMUL_11,
                               PLLMUL_12,
                               PLLMUL_13,
                               PLLMUL_14,
                               PLLMUL_15,
                               PLLMUL_16,
                               PLLMUL_16_).

	      2- Copy_PLLSRCType ( PLLSRC_HSI_2,
							   PLLSRC_HSE).
 * output: Local_u8ErrorState
 */
uint8_t RCC_u8PLLConfig(uint8_t Copy_u8PLLMULL, PLLSRC_t Copy_PLLSRCType);
/*******************************************************************************************************/

/*RCC Set AHB Peripheral State*
 * Brief: by this function we can set AHB Peripheral State (Enable or Disable)
 * input: 1- Copy_u8AHBPeripheral (AHBENR_SDIOEN,
                                   AHBENR_FSMCEN,
                                   AHBENR_CRCEN,
                                   AHBENR_FLITFEN,
                                   AHBENR_SRAMEN,
                                   AHBENR_DMA2EN,
                                   AHBENR_DMA1EN).

	      2- Copy_AHBPeriphState  (PERIPH_ENABLE,
                         		   PERIPH_DISABLE).
 * output: Local_u8ErrorState
 */
uint8_t RCC_u8AHBPeriphCLKState(uint8_t Copy_u8AHBPeripheral, PERIPH_STATE_t Copy_AHBPeriphState);
/*******************************************************************************************************/

/*RCC Set APB1 Peripheral State*
 * Brief: by this function we can set APB1 Peripheral State (Enable or Disable)
 * input: 1- Copy_u8APB1Peripheral (APB1ENR_DACEN,
                                   APB1ENR_PWREN,
                                   APB1ENR_BKPEN,
                                   APB1ENR_CANEN,
                                   APB1ENR_USBEN,
                                   APB1ENR_I2C2EN,
                                   APB1ENR_I2C1EN,
                                   APB1ENR_UART5EN,
                                   APB1ENR_UART4EN,
                                   APB1ENR_USART3EN,
                                   APB1ENR_USART2EN,
                                   APB1ENR_SPI3EN,
                                   APB1ENR_SPI2EN,
                                   APB1ENR_WWDGEN,
                                   APB1ENR_TIM14EN,
                                   APB1ENR_TIM13EN,
                                   APB1ENR_TIM12EN,
                                   APB1ENR_TIM7EN,
                                   APB1ENR_TIM6EN,
                                   APB1ENR_TIM5EN,
                                   APB1ENR_TIM4EN,
                                   APB1ENR_TIM3EN,
                                   APB1ENR_TIM2EN  ).

	      2- Copy_APB1PeriphState  (PERIPH_ENABLE,
                         		   PERIPH_DISABLE).
 * output: Local_u8ErrorState
 */
uint8_t RCC_u8APB1PeriphCLKState(uint8_t Copy_u8APB1Peripheral, PERIPH_STATE_t Copy_APB1PeriphState);
/*******************************************************************************************************/

/*RCC Set APB1 Peripheral State*
 * Brief: by this function we can set APB1 Peripheral State (Enable or Disable)
 * input: 1- Copy_u8APB2Peripheral (APB2ENR_TIM11EN
                                    APB2ENR_TIM10EN
                                    APB2ENR_TIM9EN
                                    APB2ENR_ADC3EN
                                    APB2ENR_USART1EN
                                    APB2ENR_TIM8EN
                                    APB2ENR_SPI1EN
                                    APB2ENR_TIM1EN
                                    APB2ENR_ADC2EN
                                    APB2ENR_ADC1EN
                                    APB2ENR_I0PGEN
                                    APB2ENR_IOPFEN
                                    APB2ENR_IOPEEN
                                    APB2ENR_TOPDEN
                                    APB2ENR_IOPCEN
                                    APB2ENR_IOPBEN
                                    APB2ENR_IOPAEN
                                    APB2ENR_AFIOEN    ).

	      2- Copy_APB2PeriphState  (PERIPH_ENABLE,
                         		   PERIPH_DISABLE).
 * output: Local_u8ErrorState
 */
uint8_t RCC_u8APB2PeriphCLKState(uint8_t Copy_u8APB2Peripheral, PERIPH_STATE_t Copy_APB2PeriphState);
/*******************************************************************************************************/

#endif /* RCC_INTERFACE_H_ */
