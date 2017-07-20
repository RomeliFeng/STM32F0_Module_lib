/*
 * EC11.h
 *
 *  Created on: 2016��6��28��
 *      Author: Romeli
 */

#ifndef EC11_H_
#define EC11_H_

#include "cmsis_device.h"

class EC11{
public:
	static uint8_t WiseFlag;
	static void Init();
private:
	static void GPIOInit();
	static void EXTIInit();
	static void NVICInit();
};

extern void EC11_Key_Click();
extern void EC11_Key_Press();
extern void EC11_Clockwise();
extern void EC11_Anticlockwise();

#endif /* EC11_H_ */
