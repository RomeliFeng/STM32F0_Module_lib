/*
 * EC11.cpp
 *
 *  Created on: 2016��6��28��
 *      Author: Romeli
 */
#include "EC11.h"
#include "Delay.h"

uint8_t EC11_Flag = 0;	//0:Clockwise	1:AntiClockwise

void EC11_Init() {
	EC11_RCC_Config();
	EC11_GPIO_Config();
	EC11_EXTI_Config();
	EC11_NVIC_Config();
	SysTick_Init();
}
void EC11_RCC_Config() {
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

void EC11_GPIO_Config() {
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void EC11_EXTI_Config() {
	EXTI_InitTypeDef EXTI_InitStructure;
	//�����������ж�
	EXTI_InitStructure.EXTI_Line = EXTI_Line8;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;

	EXTI_Init(&EXTI_InitStructure);
	//��������λ�ж�
	EXTI_InitStructure.EXTI_Line = EXTI_Line9;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStructure);

}

void EC11_NVIC_Config() {
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

}

extern "C" void EXTI4_15_IRQHandler(void) {
	uint8_t Flag;
	if (EXTI_GetITStatus(EXTI_Line8) == SET) {
		uint32_t last = millis();
		while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == Bit_RESET) {
			if (millis() - last >= 5000) {
				EC11_Key_Press();
				EXTI_ClearITPendingBit(EXTI_Line8);
				return;
			}
		}
		EC11_Key_Click();
		EXTI_ClearITPendingBit(EXTI_Line8);
	} else if (EXTI_GetITStatus(EXTI_Line9) == SET) {
		Flag = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)
				^ GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10);
		if (Flag == EC11_Flag) {
			if (EC11_Flag == 1)
				EC11_Anticlockwise();
			else
				EC11_Clockwise();
		}
		EC11_Flag = Flag;
		EXTI_ClearITPendingBit(EXTI_Line9);
	}
}

void __attribute__((weak)) EC11_Key_Click() {
	return;
}

void __attribute__((weak)) EC11_Key_Press() {
	return;
}

void __attribute__((weak)) EC11_Clockwise() {
	return;
}

void __attribute__((weak)) EC11_Anticlockwise() {
	return;
}
