/*
 * L6470.cpp
 *
 *  Created on: May 3, 2023
 *      Author: iroen
 */

#include <L6470.h>
#include <vector>

L6470::L6470() {
}
L6470::~L6470() {
}
//SETPARAMの引数は、レジスタのアドレス、値、値のビット数
//SETPARAで送られる値は、
//sendBuffer[0] = 0x00+アドレス
//sendBuffer[1] = VALUE(32bit)を16bit右シフトした値
//sendBuffer[2] = VALUE(32bit)を8bit右シフトした値
//sendBuffer[3] = VALUE(32bit)を0bit右シフトした値



//******L6470 commands
uint8_t* L6470::NOP() {
    sendBuffer[0] = ADDR_NOP;
    return sendBuffer;
}
uint8_t* L6470::RUN(moterDirection DIR, uint32_t SPD) {
	sendBuffer[0] = (DIR << 0) | 0x50;
    sendBuffer[1] = (uint8_t)(SPD >> 16);
    sendBuffer[2] = (uint8_t)(SPD >> 8);
    sendBuffer[3] = (uint8_t)(SPD >> 0);
    return sendBuffer;
}
uint8_t* L6470::SETPARAM(uint8_t addr, uint32_t VALUE, uint16_t VALUEsize) {
    uint8_t size = ((VALUEsize-1)/8)+1;
	sendBuffer[0] = (000 << 5) | addr;
    for (uint8_t i = 0; i < size-1; ++i) {
        sendBuffer[i+1] = (uint8_t)(VALUE >> (24-(8*(i+1))));
    }
    return sendBuffer;
}
uint8_t* L6470::GETPARAM(uint8_t addr) {
    sendBuffer[0] = (001 << 5) | addr;
    return sendBuffer;
}
uint8_t* L6470::STEPCLOCK(moterDirection DIR) {
    sendBuffer[0] = (DIR << 0) | 0x58;
    return sendBuffer;
}
uint8_t* L6470::MOVE(moterDirection DIR, uint32_t N_STEP) {
    sendBuffer[0] = (DIR << 0) | 0x40;
    sendBuffer[1] = (uint8_t)(N_STEP >> 16);
    sendBuffer[2] = (uint8_t)(N_STEP >> 8);
    sendBuffer[3] = (uint8_t)(N_STEP >> 0);
    return sendBuffer;
}
uint8_t* L6470::GOTO(uint32_t ABS_POS) {
    sendBuffer[0] = 0x60;
    sendBuffer[1] = (uint8_t)(ABS_POS >> 16);
    sendBuffer[2] = (uint8_t)(ABS_POS >> 8);
    sendBuffer[3] = (uint8_t)(ABS_POS >> 0);
    return sendBuffer;
}
uint8_t* L6470::GOTO_DIR(moterDirection DIR, uint32_t ABS_POS) {
    sendBuffer[0] = (DIR << 0) | 0x68;
    sendBuffer[1] = (uint8_t)(ABS_POS >> 16);
    sendBuffer[2] = (uint8_t)(ABS_POS >> 8);
    sendBuffer[3] = (uint8_t)(ABS_POS >> 0);
    return sendBuffer;
}
uint8_t* L6470::GOUNTIL(uint8_t ACT, moterDirection DIR, uint32_t SPD) {
    sendBuffer[0] = (DIR << 0) | 0x82;
    sendBuffer[1] = (uint8_t)(SPD >> 16);
    sendBuffer[2] = (uint8_t)(SPD >> 8);
    sendBuffer[3] = (uint8_t)(SPD >> 0);
    return sendBuffer;
}
uint8_t* L6470::RELEASESW(uint8_t ACT, moterDirection DIR) {
    sendBuffer[0] = (ACT << 3) | (DIR << 0) | 0x92;
    return sendBuffer;
}
uint8_t* L6470::GOHOME() {
    sendBuffer[0] = 0x70;
    return sendBuffer;
}
uint8_t* L6470::GOMARK() {
    sendBuffer[0] = 0x78;
    return sendBuffer;
}
uint8_t* L6470::RESETPOS() {
    sendBuffer[0] = 0xD8;
    return sendBuffer;
}
uint8_t* L6470::RESETDEVICE() {
    sendBuffer[0] = 0xC0;
    return sendBuffer;
}
uint8_t* L6470::SOFTSTOP() {
    sendBuffer[0] = 0xB0;
    return sendBuffer;
}
uint8_t* L6470::HARDSTOP() {
    sendBuffer[0] = 0xB8;
    return sendBuffer;
}
uint8_t* L6470::SOFTHIZ() {
    sendBuffer[0] = 0xA0;
    return sendBuffer;
}
uint8_t* L6470::HARDHIZ() {
    sendBuffer[0] = 0xA8;
    return sendBuffer;
}
uint8_t* L6470::GETSTATUS() {
    sendBuffer[0] = 0xD0;
    return sendBuffer;
}
//******end of L6470 commands (With argument)
