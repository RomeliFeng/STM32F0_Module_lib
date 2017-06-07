/*
 * EC11.h
 *
 *  Created on: 2016��6��28��
 *      Author: Romeli
 */

#ifndef EC11_H_
#define EC11_H_

#include "cmsis_device.h"

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
