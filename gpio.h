/*
 * gpio.h
 *
 *  Created on: 21 sie 2024
 *      Author: asmnop
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32l4xx_ll_gpio.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
	uint32_t enable_periph;
	uint32_t pull;
	uint32_t speed;
	uint32_t mode;
	uint32_t output_type;
	uint32_t AF;
	uint8_t number;
}LINE_t;


void GPIO_set_pin(LINE_t *line);
void GPIO_reset_pin(LINE_t *line);
void GPIO_set_pin_as_input(LINE_t *pLINE);
void GPIO_set_pin_as_output(LINE_t *line);


#endif /* GPIO_H_ */




