/*
 * gpio.c
 *
 *  Created on: 21 sie 2024
 *      Author: asmnop
 */

#include <stdint.h>

#include "..\..\LIB\Inc\gpio.h"

#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_gpio.h"


//	////////////////////////////////////////////////////////////////////////////
void GPIO_set_pin(LINE_t *pLine)
{
	//	-ustawienie stanu wysokiego na pinie,

	LL_GPIO_SetOutputPin(pLine->port, pLine->pin);
}

void GPIO_reset_pin(LINE_t *pLine)
{
	//	-ustawienie stanu niskiego na pinie,

	LL_GPIO_ResetOutputPin(pLine->port, pLine->pin);
}

void GPIO_set_pin_as_input(LINE_t *pLine)
{
	//	-ustawienie pinu jako linia wejściowa,
	//	-poszczególne parametry są definiowane w strukturze 'LINE_t',
	//	-funkcja jednocześnie wykrywa czy linia ma sprawować funkcję alternatywną,

	LL_AHB2_GRP1_EnableClock(pLine->enable_periph);

	LL_GPIO_SetPinPull(pLine->port, pLine->pin, pLine->pull);
	LL_GPIO_SetPinSpeed(pLine->port, pLine->pin, pLine->speed);
	LL_GPIO_SetPinMode(pLine->port, pLine->pin, pLine->mode);

	if(pLine->mode == LL_GPIO_MODE_ALTERNATE)
	{
		if(pLine->pin <= LL_GPIO_PIN_7)	LL_GPIO_SetAFPin_0_7(pLine->port, pLine->pin, pLine->AF);
		if(pLine->pin >= LL_GPIO_PIN_8)	LL_GPIO_SetAFPin_8_15(pLine->port, pLine->pin, pLine->AF);
		LL_GPIO_SetPinMode(pLine->port, pLine->pin, pLine->mode);
	}
	else
	{
		LL_GPIO_SetPinMode(pLine->port, pLine->pin, pLine->mode);
	}
}

void GPIO_set_pin_as_output(LINE_t *pLine)
{
	//	-ustawienie pinu jako linia wyjściowa,
	//	-poszczególne parametry są definiowane w strukturze 'LINE_t',
	//	-funkcja jednocześnie wykrywa czy linia ma sprawować funkcję alternatywną,

	LL_AHB2_GRP1_EnableClock(pLine->enable_periph);

	LL_GPIO_SetPinOutputType(pLine->port, pLine->pin, pLine->output_type);
	LL_GPIO_SetPinPull(pLine->port, pLine->pin, pLine->pull);
	LL_GPIO_SetPinSpeed(pLine->port, pLine->pin, pLine->speed);
	LL_GPIO_SetPinMode(pLine->port, pLine->pin, pLine->mode);
	LL_GPIO_SetOutputPin(pLine->port, pLine->pin);

	if(pLine->mode == LL_GPIO_MODE_ALTERNATE)
	{

		if(pLine->pin <= LL_GPIO_PIN_7)	LL_GPIO_SetAFPin_0_7(pLine->port, pLine->pin, pLine->AF);
		if(pLine->pin >= LL_GPIO_PIN_8)	LL_GPIO_SetAFPin_8_15(pLine->port, pLine->pin, pLine->AF);
		LL_GPIO_SetPinMode(pLine->port, pLine->pin, pLine->mode);
	}
}









