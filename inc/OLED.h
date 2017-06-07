/*
 * OLED.h
 *
 *  Created on: 2016��5��22��
 *      Author: Romeli
 *  Depend on: "Delay.h" & "SPI.h"
 */

#ifndef OLED_H_
#define OLED_H_

#include "cmsis_device.h"
#include "Parse.h"

//#define I2C_Intface
#define SPI_Intface

#ifdef I2C_Intface
#define OLED_Address 0x78
#endif
#ifdef SPI_Intface

// Port numbers: 0=A, 1=B, 2=C, 3=D, 4=E, 5=F, 6=G, ...
#define OLED_DC_PORT_NUMBER               (0)
#define OLED_DC_PIN_NUMBER                (4)
#define OLED_RESET_PORT_NUMBER            (0)
#define OLED_RESET_PIN_NUMBER             (6)
#define OLED_CS_PORT_NUMBER            (0)
#define OLED_CS_PIN_NUMBER             (3)

#define OLED_GPIOx(_N)                 ((GPIO_TypeDef *)(GPIOA_BASE + (GPIOB_BASE-GPIOA_BASE)*(_N)))
#define OLED_PIN_MASK(_N)              (1 << (_N))
#define OLED_RCC_MASKx(_N)             (RCC_AHBPeriph_GPIOA << (_N))

void OLED_GPIO_Init();
#endif

typedef enum _WriteMode_Typedef {
	Cmd_Mode = 0, Data_Mode = 1
} WriteMode_Typedef;

typedef enum _CharMode_Typedef {
	C6x8 = 6, C8x16 = 8, C16x16 = 16
} CharMode_Typedef;

typedef enum _AlignTypedef {
	Align_Left, Align_Right
} AlignTypedef;

class OLED: Parse {
public:
	static void Init();
	static void Write(uint8_t data, WriteMode_Typedef mode);
	static void SetPos(uint8_t x, uint8_t y);
	static void Fill(uint8_t bmp);
	static void print_c(uint8_t x, uint8_t y, uint8_t c, CharMode_Typedef mode);
	static void print(uint8_t x, uint8_t y, uint8_t *str,
			CharMode_Typedef mode);
	static inline void print(uint8_t x, uint8_t y, int8_t *str,
			CharMode_Typedef mode) {
		print(x, y, (uint8_t *) str, mode);
	}
	static inline void print(uint8_t x, uint8_t y, const char *str,
			CharMode_Typedef mode) {
		print(x, y, (uint8_t *) str, mode);
	}

	static void print(uint8_t x, uint8_t y, int32_t num, CharMode_Typedef mode);

	static inline void print(uint8_t x, uint8_t y, uint32_t num,
			CharMode_Typedef mode) {
		print(x, y, (int32_t) num, mode);
	}
	static inline void print(uint8_t x, uint8_t y, uint16_t num,
			CharMode_Typedef mode) {
		print(x, y, (int32_t) num, mode);
	}
	static inline void print(uint8_t x, uint8_t y, uint8_t num,
			CharMode_Typedef mode) {
		print(x, y, (int32_t) num, mode);
	}
	static inline void print(uint8_t x, uint8_t y, int16_t num,
			CharMode_Typedef mode) {
		print(x, y, (int32_t) num, mode);
	}
	static inline void print(uint8_t x, uint8_t y, int8_t num,
			CharMode_Typedef mode) {
		print(x, y, (int32_t) num, mode);
	}

	static void print(uint8_t x, uint8_t y, float f, uint8_t ndigit,
			CharMode_Typedef mode);
	void print(uint8_t x, uint8_t y, double lf, uint8_t ndigit,
			CharMode_Typedef mode);
private:
	static void GPIOInit();
};

#endif /* OLED_H_ */
