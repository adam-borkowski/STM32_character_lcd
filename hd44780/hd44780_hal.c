/*
 * hd44780_hal.c
 *
 *  Created on: 9 lis 2016
 *      Author: adam.borkowski
 */

#include "hd44780_hal.h"
#include "stm32f0xx_hal.h"


void configure_as_output(void)
{
	  GPIO_InitTypeDef GPIO_InitStruct;
	  /*Configure GPIO pins : CHAR_LCD_D4_Pin CHAR_LCD_D5_Pin CHAR_LCD_D6_Pin CHAR_LCD_D7_Pin */
	  GPIO_InitStruct.Pin = CHAR_LCD_D4_Pin|CHAR_LCD_D5_Pin|CHAR_LCD_D6_Pin|CHAR_LCD_D7_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void configure_as_input(void)
{
	  GPIO_InitTypeDef GPIO_InitStruct;
	  /*Configure GPIO pins : CHAR_LCD_D4_Pin CHAR_LCD_D5_Pin CHAR_LCD_D6_Pin CHAR_LCD_D7_Pin */
	  GPIO_InitStruct.Pin = CHAR_LCD_D4_Pin|CHAR_LCD_D5_Pin|CHAR_LCD_D6_Pin|CHAR_LCD_D7_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

uint8_t read_nibble(void)
{
	uint8_t nible = 0;
	nible |= HAL_GPIO_ReadPin(CHAR_LCD_D7_GPIO_Port, CHAR_LCD_D7_Pin);
	nible <<= 1;
	nible |= HAL_GPIO_ReadPin(CHAR_LCD_D6_GPIO_Port, CHAR_LCD_D6_Pin);
	nible <<= 1;
	nible |= HAL_GPIO_ReadPin(CHAR_LCD_D5_GPIO_Port, CHAR_LCD_D5_Pin);
	nible <<= 1;
	nible |= HAL_GPIO_ReadPin(CHAR_LCD_D4_GPIO_Port, CHAR_LCD_D4_Pin);
	return nible;
}

void write_nibble(uint8_t nible)
{
	HAL_GPIO_WritePin(CHAR_LCD_D4_GPIO_Port, CHAR_LCD_D4_Pin, (nible & 0x01));
	nible >>= 1;
	HAL_GPIO_WritePin(CHAR_LCD_D5_GPIO_Port, CHAR_LCD_D5_Pin, (nible & 0x01));
	nible >>= 1;
	HAL_GPIO_WritePin(CHAR_LCD_D6_GPIO_Port, CHAR_LCD_D6_Pin, (nible & 0x01));
	nible >>= 1;
	HAL_GPIO_WritePin(CHAR_LCD_D7_GPIO_Port, CHAR_LCD_D7_Pin, (nible & 0x01));
}
void set_enable_pin(uint8_t state)
{
	HAL_GPIO_WritePin(CHAR_LCD_En_GPIO_Port, CHAR_LCD_En_Pin, (GPIO_PinState)state);
}

void set_r_w_pin(uint8_t state)
{
	HAL_GPIO_WritePin(CHAR_LCD_RW_GPIO_Port, CHAR_LCD_RW_Pin, (GPIO_PinState)state);
}

void set_r_s_pin(uint8_t state)
{
	HAL_GPIO_WritePin(CHAR_LCD_RS_GPIO_Port, CHAR_LCD_RS_Pin, (GPIO_PinState)state);
}
