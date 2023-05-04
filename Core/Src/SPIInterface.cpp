/*
 * SPIInterface.cpp
 *
 *  Created on: May 4, 2023
 *      Author: iroen
 */

#include <SPIInterface.h>

//L6470インスタンス化
L6470 l6470;

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
void SPI_Interface::sendNOP(){
	uint8_t sendData = l6470.ADDR_NOP;
	sendSPI(&sendData, 1);
}
void SPI_Interface::sendRUN(uint32_t SPD, moterDirection DIR){
	uint8_t *sendData = l6470.RUN(DIR, SPD);
	sendSPI(sendData, 4);
}
void SPI_Interface::sendSTEP_CLOCK(moterDirection DIR){
	uint8_t *sendData = l6470.STEPCLOCK(DIR);
	sendSPI(sendData, 1);
}
void SPI_Interface::sendMOVE(moterDirection DIR,uint32_t N_STEP){
	uint8_t *sendData = l6470.MOVE(DIR, N_STEP);
	sendSPI(sendData, 4);
}
void SPI_Interface::sendGOTO(uint32_t ABS_POS){
	uint8_t *sendData = l6470.GOTO(ABS_POS);
	sendSPI(sendData, 4);
}
void SPI_Interface::sendGOTO_DIR(moterDirection DIR, uint32_t ABS_POS){
	uint8_t *sendData = l6470.GOTO_DIR(DIR, ABS_POS);
	sendSPI(sendData, 4);
}
void SPI_Interface::sendGO_UNTIL(moterAction ACT, moterDirection DIR, uint32_t SPD){
	uint8_t *sendData = l6470.GOUNTIL(ACT, DIR, SPD);
	sendSPI(sendData, 4);
}
void SPI_Interface::sendRELEASE_SW(moterAction ACT, moterDirection DIR){
	uint8_t *sendData = l6470.RELEASESW(ACT, DIR);
	sendSPI(sendData, 4);
}
void SPI_Interface::sendGO_HOME(){
	uint8_t *sendData = l6470.GOHOME();
	sendSPI(sendData, 4);
}
void SPI_Interface::sendGO_MARK(){
	uint8_t *sendData = l6470.GOMARK();
	sendSPI(sendData, 4);
}
void SPI_Interface::sendRESET_POS(){
	uint8_t *sendData = l6470.RESETPOS();
	sendSPI(sendData, 4);
}
void SPI_Interface::sendRESET_DEVICE(){
	uint8_t *sendData = l6470.RESETDEVICE();
	sendSPI(sendData, 4);
}
void SPI_Interface::sendSOFT_STOP(){
	uint8_t *sendData = l6470.SOFTSTOP();
	sendSPI(sendData, 4);
}
void SPI_Interface::sendHARD_STOP(){
	uint8_t *sendData = l6470.HARDSTOP();
	sendSPI(sendData, 4);
}
void SPI_Interface::sendSOFT_HIZ(){
	uint8_t *sendData = l6470.SOFTHIZ();
	sendSPI(sendData, 4);
}
void SPI_Interface::sendHARD_HIZ(){
	uint8_t *sendData = l6470.HARDHIZ();
	sendSPI(sendData, 4);
}
void SPI_Interface::sendGET_STATUS(){
	uint8_t *sendData = l6470.GETSTATUS();
	sendSPI(sendData, 4);
}

//set Register parameter functions //レジスタマップに基づいたレジスタに値を書き込む関数
void SPI_Interface::setABS_POS(uint32_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_ABS_POS, PARAM, 22), 4);
}
void SPI_Interface::setEL_POS(uint32_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_EL_POS, PARAM, 9), 4);
}
void SPI_Interface::setMARK(uint32_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_MARK, PARAM, 22), 4);
}
void SPI_Interface::setACC(uint16_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_ACC, PARAM, 12), 4);
}
void SPI_Interface::setDEC(uint16_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_DEC, PARAM, 12), 4);
}
void SPI_Interface::setMAX_SPEED(uint16_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_MAX_SPEED, PARAM, 10), 4);
}
void SPI_Interface::setMIN_SPEED(uint16_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_MIN_SPEED, PARAM, 13), 4);
}
void SPI_Interface::setFS_SPD(uint16_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_FS_SPD, PARAM, 10), 4);
}
void SPI_Interface::setKVAL_HOLD(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_KVAL_HOLD, PARAM, 8), 4);
}
void SPI_Interface::setKVAL_RUN(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_KVAL_RUN, PARAM, 8), 4);
}
void SPI_Interface::setKVAL_ACC(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_KVAL_ACC, PARAM, 8), 4);
}
void SPI_Interface::setKVAL_DEC(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_KVAL_DEC, PARAM, 8), 4);
}
void SPI_Interface::setINT_SPD(uint16_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_INT_SPEED, PARAM, 14), 4);
}
void SPI_Interface::setST_SLP(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_ST_SLP, PARAM, 8), 4);
}
void SPI_Interface::setFN_SLP_ACC(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_FN_SLP_ACC, PARAM, 8), 4);
}
void SPI_Interface::setFN_SLP_DEC(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_FN_SLP_DEC, PARAM, 8), 4);
}
void SPI_Interface::setK_THERM(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_K_THERM, PARAM, 4), 4);
}
void SPI_Interface::setOCD_TH(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_OCD_TH, PARAM, 4), 4);
}
void SPI_Interface::setSTALL_TH(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_STALL_TH, PARAM, 7), 4);
}
void SPI_Interface::setSTEP_MODE(uint8_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_STEP_MODE, PARAM, 8), 4);
}
void SPI_Interface::setALARM_EN(uint16_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_ALARM_EN, PARAM, 8), 4);
}
void SPI_Interface::setCONFIG(uint16_t PARAM){
	sendSPI(l6470.SETPARAM(L6470_CONFIG, PARAM, 16), 4);
}
