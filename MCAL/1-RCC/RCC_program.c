/*
 * RCC_program.c
 *
 *  Created on: Apr 12, 2023
 *      Author: Al-Hasan Ameer
 */
/*******************************************************************************************************/
#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*******************************************************************************************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_register.h"
/*******************************************************************************************************/


/*RCC Set Clock Status Function*
 * Brief: by this function we can set the RCC clock Source status (ON or OFF)*
 * input:  Copy_RCCState ( RCC_ON,
	                       RCC_OFF)
 * output: Local_u8ErrorState
 */
uint8_t RCC_u8CLKStateSync(RCC_CLKSTATE_t Copy_RCCState)
{
	/*counter to  check if timeOut is reached*/
	uint32_t Local_u32Counter=0;
	/*return Error state*/
	uint8_t Local_u8ErrorState=OK;

	/*Check if the RCC Clock Source Type is HSI -High Speed Internal-*/
#if RCC_CLKTYPE == RCC_HSI
	/*Check if HSI CLK is ON*/
	if(Copy_RCCState == RCC_ON)
	{
		/*Set HSI BIT*/
		SETBIT(RCC->CR,CR_HSION);

		/*(polling) until the flag is set or counter reaching timeOut*/
		while((GETBIT(RCC->CR,CR_HSIRDY) == 0) && (Local_u32Counter < RCC_uint32TIMEOUT))
		{
			Local_u32Counter++;
		}
	}
	/*Check if HSI CLK is OFF*/
	else if(Copy_RCCState == RCC_OFF)
	{
		/*clear HSI BIT*/
		CLRBIT(RCC->CR,CR_HSION);
	}
	else {
		Local_u8ErrorState = NOK;
	}
	/*******************************************************************************************************/

	/*Check if the RCC Clock Source Type is HSE -High Speed External-*/
#elif RCC_CLKTYPE == RCC_HSE
	/*Check if HSE CLK is ON*/
	if(Copy_RCCState == RCC_ON)
	{
		/*Set HSE BIT*/
		SETBIT(RCC->CR,CR_HSEON);

		/*(polling) until the flag is set or counter reaching timeOut*/
		while((GETBIT(RCC->CR,CR_HSERDY) == 0) && (Local_u32Counter < RCC_uint32TIMEOUT))
		{
			Local_u32Counter++;
		}
	}
	/*Check if HSE CLK is OFF*/
	else if(Copy_RCCState == RCC_OFF)
	{
		/*clear HSE BIT*/
		CLRBIT(RCC->CR,CR_HSEON);
	}
	else {
		Local_ErrorState = NOK;
	}
	/*******************************************************************************************************/

	/*Check if the RCC Clock Source Type is PLL -Phase Looked Loop-*/
#elif RCC_CLKTYPE == RCC_PLL
	/*Check if PLL CLK is ON*/
	if(Copy_RCCState == RCC_ON)
	{
		/*Set PLL BIT*/
		SETBIT(RCC->CR,CR_PLLON);

		/*(polling) until the flag is set or counter reaching timeOut*/
		while((GETBIT(RCC->CR,CR_PLLRDY) == 0) && (Local_u32Counter < RCC_uint32TIMEOUT))
		{
			Local_u32Counter++;
		}
	}
	/*Check if PLL CLK is OFF*/
	else if(Copy_RCCState == RCC_OFF)
	{
		/*clear PLL BIT*/
		CLRBIT(RCC->CR,CR_PLLON);
	}
	else {
		Local_u8ErrorState = NOK;
	}
#else
#error "wrong RCC TYPE configuration option"
#endif
	/*******************************************************************************************************/

	/*Return Error State*/
	return Local_u8ErrorState;

}
/*******************************************************************************************************/

/*RCC Set System Clock Function*
 * Brief: by this function we can set the RCC clock Source*
 * input:  void
 * output: void
 */
void RCC_voidSetSYSCLK(void)
{
	/*Check if the RCC Clock Source Type is HSI -High Speed Internal-*/
#if RCC_CLKTYPE == RCC_HSI
	CLRBIT(RCC->CFGR, CFGR_SW0);
	CLRBIT(RCC->CFGR, CFGR_SW1);

	/*Check if the RCC Clock Source Type is HSE -High Speed External-*/
#elif RCC_CLKTYPE == RCC_HSE
	SETBIT(RCC->CFGR,CFGR_SW0);
	CLRBIT(RCC->CFGR,CFGR_SW1);

	/*Check if the RCC Clock Source Type is PLL -Phase Looked Loop-*/
#elif RCC_CLKTYPE == RCC_PLL
	SETBIT(RCC->CFGR,CFGR_SW0);
	SETBIT(RCC->CFGR,CFGR_SW1);

#else
#error "wrong RCC TYPE configuration option"
#endif

}
/*******************************************************************************************************/

/*RCC Set HSE Configuration Function*
 * Brief: by this function we can set the HSE Configuration (divide and bypass) and set HSE as a PLL CLK Source*
 * input: 1- Copy_HSEDivider (HSE_DIVIDED_1,
	                          HSE_DIVIDED_2).

	      2- Copy_HSEBypass  (HSE_NOTBYPASSED,
	                          HSE_BYPASSED).
 * output: Local_u8ErrorState
 */
uint8_t RCC_u8HSEConfig(HSE_DIVIDE_t Copy_HSEDivide, HSE_PYPASS_t Copy_HSEBypass)
{
	/*return Error state*/
	uint8_t Local_u8ErrorState=OK;

	/*Set HSE as  a PLLCLK Source*/
	SETBIT(RCC->CFGR,CFGR_PLLSRC);

	/*Set bypass configuration*/
	/*Check if HSE Not Bypassed*/
	if(Copy_HSEBypass == HSE_NOTBYPASSED)
	{
		/*Make HSEBYP BIT = 0*/
		CLRBIT(RCC->CR, CR_HSEBYP);
	}
	else if(Copy_HSEBypass == HSE_BYPASSED)
	{
		/*Make HSEBYP BIT = 1*/
		SETBIT(RCC->CR, CR_HSEBYP);
	}
	else{
		Local_u8ErrorState = NOK;
	}
	/*******************************************************************************************************/

	/*Set Divide configuration*/
	/*Check if HSE Divided by 1 -Not Divided-*/
	if(Copy_u8HSEDivide == HSE_DIVIDED_1)
	{
		/*Make PLLXTPRE BIT = 0*/
		CLRBIT(RCC->CFGR,CFGR_PLLXTPRE);
	}
	/*Check if HSE Divided by 2*/
	else if(Copy_u8HSEDivide == HSE_DIVIDED_2)
	{
		/*Make PLLXTPRE BIT = 1*/
		SETBIT(RCC->CFGR,CFGR_PLLXTPRE);
	}
	else{
		Local_u8ErrorState = NOK;
	}
	/*******************************************************************************************************/

	/*return Error state*/
	return Local_u8ErrorState;
}
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
uint8_t RCC_u8PLLConfig(uint8_t Copy_u8PLLMULL, PLLSRC_t Copy_PLLSRCType)
{
	/*return Error state*/
	uint8_t Local_u8ErrorState=OK;

	/*Set PLL CLK Source*/
	/*Check if PLL CLK source is HSI Divided by 2*/
	if(Copy_PLLSRCType == PLLSRC_HSI_2)
	{
		/*Make PLLSRC BIT = 0*/
		CLRBIT(RCC->CFGR, CFGR_PLLSRC);
	}
	else if(Copy_PLLSRCType == PLLSRC_HSE)
	{
		/*Make PLLSRC BIT = 1*/
		SETBIT(RCC->CFGR, CFGR_PLLSRC);
	}
	else{
		Local_u8ErrorState = NOK;
	}
	/*******************************************************************************************************/

	/*Set PLL multiplication Factor*/
	if((Copy_u8PLLMULL >= PLLMUL_2) && (Copy_u8PLLMULL >= PLLMUL_16))
	{
		/*Clear PLL Multiplication Bits*/
		RCC->CFGR &= (~((PLLMUL_MASK)<<(CFGR_PLLMUL0)));
		/*Set PLL multiplication Factor*/
		RCC->CFGR |= ((Copy_u8PLLMULL - 2)<<(CFGR_PLLMUL0));
	}
	else{
		Local_u8ErrorState = NOK;
	}
	/*******************************************************************************************************/

	/*return Error state*/
	return Local_u8ErrorState;
}
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
uint8_t RCC_u8AHBPeriphCLKState(uint8_t Copy_u8AHBPeripheral, PERIPH_STATE_t Copy_AHBPeriphState)
{
	/*return Error state*/
	uint8_t Local_u8ErrorState=OK;

	/*Check if Peripheral in the range of AHB peripheral in the Register*/
	if((Copy_u8AHBPeripheral <= AHBENR_SDIOEN) && (Copy_u8AHBPeripheral >= AHBENR_DMA1EN))
	{
		/*Check if peripheral state is Enable*/
		if((Copy_AHBPeriphState) == (PERIPH_ENABLE))
		{
			/*Enable the Peripheral*/
			SETBIT(RCC->AHBENR, Copy_u8AHBPeripheral);
		}
		/*Check if peripheral state is Disable*/
		else if((Copy_AHBPeriphState) == (PERIPH_DISABLE))
		{
			/*Disable the Peripheral*/
			CLRBIT(RCC->AHBENR, Copy_u8AHBPeripheral);
		}
		else{
			/*return Error state*/
			Local_u8ErrorState = NOK;
		}
	}
	else{
		/*return Error state*/
		Local_u8ErrorState = NOK;
	}

	/*return Error state*/
	return Local_u8ErrorState;
}
/*******************************************************************************************************/

/*RCC Set APB1 Peripheral State*
 * Brief: by this function we can set APB2 Peripheral State (Enable or Disable)
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
uint8_t RCC_u8APB1PeriphCLKState(uint8_t Copy_u8APB1Peripheral, PERIPH_STATE_t Copy_APB1PeriphState)
{
	/*return Error state*/
	uint8_t Local_u8ErrorState=OK;

	/*Check if Peripheral in the range of APB1 peripheral in the Register*/
	if((Copy_u8APB1Peripheral <= APB1ENR_DACEN) && (Copy_u8APB1Peripheral >= APB1ENR_TIM2EN))
	{
		/*Check if peripheral state is Enable*/
		if((Copy_APB1PeriphState) == (PERIPH_ENABLE))
		{
			/*Enable the Peripheral*/
			SETBIT(RCC->APB1ENR, Copy_u8APB1Peripheral);
		}
		/*Check if peripheral state is Disable*/
		else if((Copy_APB1PeriphState) == (PERIPH_DISABLE))
		{
			/*Disable the Peripheral*/
			CLRBIT(RCC->APB1ENR, Copy_u8APB1Peripheral);
		}
		else{
			/*return Error state*/
			Local_u8ErrorState = NOK;
		}
	}
	else{
		/*return Error state*/
		Local_u8ErrorState = NOK;
	}

	/*return Error state*/
	return Local_u8ErrorState;
}
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
uint8_t RCC_u8APB2PeriphCLKState(uint8_t Copy_u8APB2Peripheral, PERIPH_STATE_t Copy_APB2PeriphState)
{
	/*return Error state*/
	uint8_t Local_u8ErrorState=OK;

	/*Check if Peripheral in the range of APB2 peripheral in the Register*/
	if((Copy_u8APB2Peripheral <= APB2ENR_TIM11EN) && (Copy_u8APB2Peripheral >= APB2ENR_AFIOEN))
	{
		/*Check if peripheral state is Enable*/
		if((Copy_APB2PeriphState) == (PERIPH_ENABLE))
		{
			/*Enable the Peripheral*/
			SETBIT(RCC->APB2ENR, Copy_u8APB2Peripheral);
		}
		/*Check if peripheral state is Disable*/
		else if((Copy_APB2PeriphState) == (PERIPH_DISABLE))
		{
			/*Disable the Peripheral*/
			CLRBIT(RCC->APB2ENR, Copy_u8APB2Peripheral);
		}
		else{
			/*return Error state*/
			Local_u8ErrorState = NOK;
		}
	}
	else{
		/*return Error state*/
		Local_u8ErrorState = NOK;
	}

	/*return Error state*/
	return Local_u8ErrorState;
}
/*******************************************************************************************************/


