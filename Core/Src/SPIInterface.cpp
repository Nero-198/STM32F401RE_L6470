/*
 * SPIInterface.cpp
 *
 *  Created on: May 4, 2023
 *      Author: iroen
 */

#include <SPIInterface.h>


SPI_Interface::SPI_Interface(SPI_HandleTypeDef *hspi, GPIO_TypeDef* chipSelectGPIOx, uint16_t chipSelectGPIO_PIN)
	: hspi_(hspi), chipSelectGPIOx_(chipSelectGPIOx), chipSelectGPIO_PIN_(chipSelectGPIO_PIN) {
}

SPI_Interface::~SPI_Interface() {
	// TODO Auto-generated destructor stub
}

void SPI_Interface::sendSPI(uint8_t *sendData, uint8_t size) {
	for (uint8_t i = 0; i < size; ++i) {
		HAL_GPIO_WritePin(chipSelectGPIOx_, chipSelectGPIO_PIN_, GPIO_PIN_RESET);
		HAL_SPI_Transmit(hspi_, &sendData[i], 1, 1000);
		HAL_GPIO_WritePin(chipSelectGPIOx_, chipSelectGPIO_PIN_, GPIO_PIN_SET);
	}
}
