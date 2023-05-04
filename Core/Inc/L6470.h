/*
 * L6470.h
 *
 *  Created on: May 3, 2023
 *      Author: iroen
 */

#ifndef INC_L6470_H_
#define INC_L6470_H_

#include<main.h>
#include<map>
#include<string>
#include<vector>

class L6470 {
public:
	L6470();
    L6470(SPI_HandleTypeDef* hspi);
    virtual ~L6470();

   // void sendCommand(uint8_t command, const uint8_t* data, uint16_t size);
    void receiveData(uint8_t* data, uint16_t size);

//L6470 commands (With argument)
    uint8_t* SETPARAM(uint8_t* PARAM, uint8_t data);
    uint8_t RUN(uint8_t DIR);
    uint8_t STEPCLOCK(uint8_t DIR);
    uint8_t MOVE(uint8_t DIR);
    uint8_t GOTO_DIR(uint8_t DIR);
    uint8_t GOUNTILL(uint8_t ACT, uint8_t DIR);
    uint8_t RELEASESW(uint8_t ACT, uint8_t DIR);
    void sendComandComplete();
    std::vector<uint8_t> sendCommand(uint8_t command, const uint8_t* data, uint16_t size);

    

//L6470 commands (No argument)
    static const uint8_t NOP = 0x00;        // 何もしない   Do nothing
    static const uint8_t GOTO = 0x60;       // 指定位置へ移動   Go to position
    static const uint8_t GOHOME = 0x70;     // ホーム位置へ移動   Go home
    static const uint8_t GOMARK = 0x78;     // マーク位置へ移動   Go to mark position
    static const uint8_t RESETPOS = 0xD8;   // 現在位置を0にする   Reset position
    static const uint8_t RESETDEVICE = 0xC0;    // デバイスをリセットする   Reset device
    static const uint8_t SOFTSTOP = 0xB0;   // ソフトストップ   Soft stop
    static const uint8_t HARDSTOP = 0xB8;   // ハードストップ   Hard stop
    static const uint8_t SOFTHIZ = 0xA0;    // ソフトハイインピーダンス   Soft High impedance
    static const uint8_t HARDHIZ = 0xA8;    // ハードハイインピーダンス   Hard High impedance
    static const uint8_t GETSTATUS = 0xD0;  // ステータス取得   Get status
    static const uint8_t RESERVED1 = 0xEB;  // 予約   Reserved
    static const uint8_t RESERVED2 = 0xF8;  // 予約   Reserved
private:
    SPI_HandleTypeDef* hspi_; // SPIハンドル

        // Send data buffer
    uint8_t sendData[5];    //HAL_SPI_Transmit()の第二引数に渡すためのバッファ

    // レジスタアドレス
        std::map<std::string, uint8_t> RegisterAddress = {
        {"ABS_POS", 0x01},
        {"EL_POS", 0x02},
        {"MARK", 0x03},
        {"SPEED", 0x04},
        {"ACC", 0x05},
        {"DEC", 0x06},
        {"MAX_SPEED", 0x07},
        {"MIN_SPEED", 0x08},
        {"FS_SPD", 0x15},
        {"KVAL_HOLD", 0x09},
        {"KVAL_RUN", 0x0A},
        {"KVAL_ACC", 0x0B},
        {"KVAL_DEC", 0x0C},
        {"INT_SPEED", 0x0D},
        {"ST_SLP", 0x0E},
        {"FN_SLP_ACC", 0x0F},
        {"FN_SLP_DEC", 0x10},
        {"K_THERM", 0x11},
        {"ADC_OUT", 0x12},
        {"OCD_TH", 0x13},
        {"STALL_TH", 0x14},
        {"STEP_MODE", 0x16},
        {"ALARM_EN", 0x17},
        {"CONFIG", 0x18},
        {"STATUS", 0x19}
    };
};

#endif /* INC_L6470_H_ */
