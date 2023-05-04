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
std::vector<uint8_t> L6470::sendCommand(uint8_t command, const uint8_t* data, uint16_t size) {
    std::vector<uint8_t> sendData;
    sendData.push_back(command);
    sendData.insert(sendData.end(), data, data + size);
    return sendData;
}

uint8_t* L6470::SETPARAM(uint8_t* addr, uint8_t data) {
    sendData[0] = *addr;
    sendData[1] = data;

    return sendData;
}


//******L6470 commands (With argument)
uint8_t* L6470::RUN(moterDirection DIR, uint32_t SPD) {
	sendBuffer[0] = (DIR << 0) | 0x50;
    sendBuffer[1] = (uint8_t)(SPD >> 16);
    sendBuffer[2] = (uint8_t)(SPD >> 8);
    sendBuffer[3] = (uint8_t)(SPD >> 0);
    return sendBuffer;
}
uint8_t L6470::STEPCLOCK(moterDirection DIR) {
    return (DIR << 0) | 0x58;
}
uint8_t L6470::MOVE(moterDirection DIR) {
    return (DIR << 0) | 0x40;
}
uint8_t L6470::GOTO_DIR(moterDirection DIR) {
    return (DIR << 0) | 0x68;
}
uint8_t L6470::GOUNTILL(uint8_t ACT, moterDirection DIR) {
    return (ACT << 3) | (DIR << 0) | 0x82;
}
uint8_t L6470::RELEASESW(uint8_t ACT, moterDirection DIR) {
    return (ACT << 3) | (DIR << 0) | 0x92;
}
//******end of L6470 commands (With argument)
