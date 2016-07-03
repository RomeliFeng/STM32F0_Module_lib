/*
 * EC11.h
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: Romeli
 */

#ifndef EC11_H_
#define EC11_H_

#include "stm32f0xx.h"

void EC11_Init();
void EC11_RCC_Config();
void EC11_GPIO_Config();
void EC11_EXTI_Config();
void EC11_NVIC_Config();
extern void EC11_Key_Click();
extern void EC11_Key_Press();
extern void EC11_Clockwise();
extern void EC11_Anticlockwise();

#endif /* EC11_H_ */
