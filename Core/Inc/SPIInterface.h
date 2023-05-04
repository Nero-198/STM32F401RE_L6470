/*
 * SPIInterface.h
 *
 *  Created on: May 4, 2023
 *      Author: iroen
 */

#ifndef INC_SPIINTERFACE_H_
#define INC_SPIINTERFACE_H_

#include <main.h>
#include <L6470.h>

class SPI_Interface {
public:
	SPI_Interface(SPI_HandleTypeDef *hspi, GPIO_TypeDef* chipSelectGPIOx, uint16_t chipSelectGPIO_PIN);
	virtual ~SPI_Interface();
	void sendNOP();
	void sendSPI(uint8_t *sendData, uint8_t size);	//SPI通信テスト用、後でprivateに移動しても良いかも。
	void sendRUN(uint32_t SPD, moterDirection DIR);
	void sendSTEP_CLOCK(moterDirection DIR);
	void sendMOVE(moterDirection DIR, uint32_t N_STEP);
	void sendGOTO(uint32_t ABS_POS);
	void sendGOTO_DIR(moterDirection DIR, uint32_t ABS_POS);
	void sendGO_UNTIL(moterAction ACT, moterDirection DIR, uint32_t SPD);
	void sendRELEASE_SW(moterAction ACT, moterDirection DIR);
	void sendGO_HOME();
	void sendGO_MARK();
	void sendRESET_POS();
	void sendRESET_DEVICE();
	void sendSOFT_STOP();
	void sendHARD_STOP();
	void sendSOFT_HIZ();
	void sendHARD_HIZ();
	void sendGET_STATUS();

	//set Register parameter functions //レジスタマップに基づいたレジスタに値を書き込む関数
	void setABS_POS(uint32_t PARAM);
	void setEL_POS(uint32_t PARAM);
	void setMARK(uint32_t PARAM);
	void setACC(uint16_t PARAM);
	void setDEC(uint16_t PARAM);
	void setMAX_SPEED(uint16_t PARAM);
	void setMIN_SPEED(uint16_t PARAM);
	void setFS_SPD(uint16_t PARAM);
	void setKVAL_HOLD(uint8_t PARAM);
	void setKVAL_RUN(uint8_t PARAM);
	void setKVAL_ACC(uint8_t PARAM);
	void setKVAL_DEC(uint8_t PARAM);
	void setINT_SPD(uint16_t PARAM);
	void setST_SLP(uint8_t PARAM);
	void setFN_SLP_ACC(uint8_t PARAM);
	void setFN_SLP_DEC(uint8_t PARAM);
	void setK_THERM(uint8_t PARAM);
	void setOCD_TH(uint8_t PARAM);
	void setSTALL_TH(uint8_t PARAM);
	void setSTEP_MODE(uint8_t PARAM);
	void setALARM_EN(uint16_t PARAM);
	void setCONFIG(uint16_t PARAM);
	
private:
	SPI_HandleTypeDef *hspi_;
	GPIO_TypeDef* chipSelectGPIOx_;
	uint16_t chipSelectGPIO_PIN_;
};

#endif /* INC_SPIINTERFACE_H_ */
