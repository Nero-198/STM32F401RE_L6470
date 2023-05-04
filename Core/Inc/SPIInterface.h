/*
 * SPIInterface.h
 *
 *  Created on: May 4, 2023
 *      Author: iroen
 */

#ifndef INC_SPIINTERFACE_H_
#define INC_SPIINTERFACE_H_

#include <main.h>

class SPI_Interface {
public:
	SPI_Interface(SPI_HandleTypeDef *hspi, GPIO_TypeDef* chipSelectGPIOx, uint16_t chipSelectGPIO_PIN);
	virtual ~SPI_Interface();
	void sendSPI(uint8_t *sendData, uint8_t size);	//SPI通信テスト用、後でprivateに移動しても良いかも。

private:
	SPI_HandleTypeDef *hspi_;
	GPIO_TypeDef* chipSelectGPIOx_;
	uint16_t chipSelectGPIO_PIN_;
};

#endif /* INC_SPIINTERFACE_H_ */
