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
#include <array>

//Register address define //レジスタアドレスの名前とアドレスの紐づけ。
#define L6470_ABS_POS      0x01
#define L6470_EL_POS       0x02
#define L6470_MARK         0x03
#define L6470_SPEED        0x04
#define L6470_ACC          0x05
#define L6470_DEC          0x06
#define L6470_MAX_SPEED    0x07
#define L6470_MIN_SPEED    0x08
#define L6470_FS_SPD       0x15
#define L6470_KVAL_HOLD    0x09
#define L6470_KVAL_RUN     0x0A
#define L6470_KVAL_ACC     0x0B
#define L6470_KVAL_DEC     0x0C
#define L6470_INT_SPEED    0x0D
#define L6470_ST_SLP       0x0E
#define L6470_FN_SLP_ACC   0x0F
#define L6470_FN_SLP_DEC   0x10
#define L6470_K_THERM      0x11
#define L6470_ADC_OUT      0x12
#define L6470_OCD_TH       0x13
#define L6470_STALL_TH     0x14
#define L6470_STEP_MODE    0x16
#define L6470_ALARM_EN     0x17
#define L6470_CONFIG       0x18
#define L6470_STATUS       0x19


enum moterDirection {
    REVERSE = 0,
    FORWARD = 1
};
enum moterAction{
	ACT_UNSET = 0,
	ACT_SET = 1
};


class L6470 {
public:
	L6470();
    virtual ~L6470();
    uint8_t sendBuffer[4] = {0};	//SPI通信プログラムに送る値を格納する
    uint8_t reciveBuffer[4] = {0};	//SPI通信プログラムから受け取る値を格納する
   // void sendCommand(uint8_t command, const uint8_t* data, uint16_t size);
    void receiveData(uint8_t* data, uint16_t size);
//L6470 commands
    uint8_t* NOP();
    uint8_t* SETPARAM(uint8_t addr, uint32_t VALUE, uint16_t size);
    uint8_t* GETPARAM(uint8_t addr);
    uint8_t* RUN(moterDirection DIR, uint32_t SPD);
    uint8_t* STEPCLOCK(moterDirection DIR);
    uint8_t* MOVE(moterDirection DIR, uint32_t N_STEP);
    uint8_t* GOTO(uint32_t ABS_POS);
    uint8_t* GOTO_DIR(moterDirection DIR, uint32_t ABS_POS);
    uint8_t* GOUNTIL(uint8_t ACT, moterDirection DIR, uint32_t SPD);
    uint8_t* RELEASESW(uint8_t ACT, moterDirection DIR);
    uint8_t* GOHOME();
    uint8_t* GOMARK();
    uint8_t* RESETPOS();
    uint8_t* RESETDEVICE();
    uint8_t* SOFTSTOP();
    uint8_t* HARDSTOP();
    uint8_t* SOFTHIZ();
    uint8_t* HARDHIZ();
    uint8_t* GETSTATUS();
    uint8_t* RESERVED1();
    uint8_t* RESERVED2();


    

//L6470 commands (No argument)
    static const uint8_t ADDR_NOP = 0x00;        // 何もしない   Do nothing
    static const uint8_t ADDR_GOTO = 0x60;       // 指定位置へ移動   Go to position
    static const uint8_t ADDR_GOHOME = 0x70;     // ホーム位置へ移動   Go home
    static const uint8_t ADDR_GOMARK = 0x78;     // マーク位置へ移動   Go to mark position
    static const uint8_t ADDR_RESETPOS = 0xD8;   // 現在位置を0にする   Reset position
    static const uint8_t ADDR_RESETDEVICE = 0xC0;    // デバイスをリセットする   Reset device
    static const uint8_t ADDR_SOFTSTOP = 0xB0;   // ソフトストップ   Soft stop
    static const uint8_t ADDR_HARDSTOP = 0xB8;   // ハードストップ   Hard stop
    static const uint8_t ADDR_SOFTHIZ = 0xA0;    // ソフトハイインピーダンス   Soft High impedance
    static const uint8_t ADDR_HARDHIZ = 0xA8;    // ハードハイインピーダンス   Hard High impedance
    static const uint8_t ADDR_GETSTATUS = 0xD0;  // ステータス取得   Get status
    static const uint8_t ADDR_RESERVED1 = 0xEB;  // 予約   Reserved
    static const uint8_t ADDR_RESERVED2 = 0xF8;  // 予約   Reserved
private:
};

#endif /* INC_L6470_H_ */
