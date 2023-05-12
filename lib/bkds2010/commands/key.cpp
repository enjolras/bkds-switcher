#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "key.h"

using namespace std;

#define KEY1_FILL	0x00
#define KEY1_SOURCE 0x01
#define KEY1_TYPE	0x05
#define KEY1_EDGE	0x06
#define KEY1_TRANS	0x10
#define KEY1_INV	0x11
#define KEY1_MAIN	0x12
#define KEY1_SUB	0x13
#define KEY1_15		0x15
#define KEY1_FINE	0x90
#define KEY1_DEPTH	0x91
#define KEY1_PROC	0x93
#define KEY2_FILL	0x20
#define KEY2_SOURCE 0x21
#define KEY2_TYPE	0x25
#define KEY2_EDGE	0x26
#define KEY2_TRANS	0x30
#define KEY2_INV	0x31
#define KEY2_MAIN	0x32
#define KEY2_SUB	0x33
#define KEY2_35		0x35
#define KEY2_FINE	0xb0
#define KEY2_DEPTH	0xb1
#define KEY2_PROC	0xb3

#define EFF_PP		0x00
#define EFF_ME1		0x01

key::key(std::shared_ptr<effect> eff) : command(eff) {

	switch(eff->myId()) {
		case 0x00:
		    config_[0x05] = 0x01;
   			config_[0x25] = 0x01;
			config_[0x11] = false;
			config_[0x12] = false;
			config_[0x13] = false;
			config_[0x90] = false;
			config_[0x91] = false;
			config_[0x93] = false;
			break;
		case 0x01:
			config_[0x14] = false;
			config_[0x34] = false;
			config_[0x00] = 0x01;
			config_[0x01] = 0x00;
			config_[0x05] = 0x01;
			config_[0x06] = 0x00;
			config_[0x20] = 0x01;
			config_[0x21] = 0x00;
			config_[0x25] = 0x01;
			config_[0x26] = 0x00;
			break;
	}

}

void key::exec(unsigned char *nextCommand) {

	response tmpResp;

	switch(nextCommand[3]) {
		case KEY1_INV:
		case KEY1_MAIN:
		case KEY1_SUB:
		case KEY1_FINE:
		case KEY1_DEPTH:
		case KEY1_PROC:
		case KEY2_INV:
		case KEY2_MAIN:
		case KEY2_SUB:
		case KEY2_FINE:
		case KEY2_DEPTH:
		case KEY2_PROC:
			tmpResp.addByte(nextCommand[1]);
			if(nextCommand[2] > 0x80) {
				config_[nextCommand[3]] = (nextCommand[2] == 0xda ? true : false);
			}
			tmpResp.addByte((config_[nextCommand[3]] ? 0xda : 0x9a));
			tmpResp.addByte(nextCommand[3]);
			break;
		case KEY1_TRANS:
		case KEY2_TRANS:
/*		case 0x02:
		case 0x03:
		case 0x14:
		case 0x16:
		case 0x17:
		case 0x18:
		case 0x19:
		case 0x92:
		case 0x96:
		case 0x22:
		case 0x23:
		case 0x34:
		case 0x36:
		case 0x37:
		case 0x38:
		case 0x39:
		case 0xb2:
		case 0xb6:*/
/*		case KEY1_11:
		case KEY1_15:
		case KEY2_31:
		case KEY2_35:*/
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2] | 0x80);
			tmpResp.addByte(nextCommand[3]);
			break;
		case KEY1_TYPE:
		case KEY2_TYPE:
		case KEY1_EDGE:
		case KEY2_EDGE:
		case KEY1_FILL:
		case KEY2_FILL:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2] | 0x80);
			if(nextCommand[2] >= 0x80) {
				config_[nextCommand[3]] = nextCommand[4];
			}
			tmpResp.addByte(nextCommand[3]);
			tmpResp.addByte(config_[nextCommand[3]]);
			break;
		case KEY1_SOURCE:
		case KEY2_SOURCE:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2] | 0x80);
			tmpResp.addByte(nextCommand[3]);
			if(nextCommand[2] < 0x80) {
				tmpResp.addByte(0x01);
				tmpResp.addByte(0x00);
			} else {
				tmpResp.addByte(nextCommand[4]);
				tmpResp.addByte(nextCommand[5]);
			}
			break;
		case 0x14:		// KEY1 EDGE SOFT ON
		case 0x34:		// KEY2 EDGE SOFT ON
			tmpResp.addByte(nextCommand[1]);
			if(nextCommand[2] >= 0x80) {
				config_[nextCommand[3]] = (nextCommand[2] == 0xda ? true : false);
			}
			tmpResp.addByte(config_[nextCommand[3]] ? 0xda : 0x9a);
			tmpResp.addByte(nextCommand[3]);
			break;
//		case 0x15:		// KEY1 OVER
		case 0x35:		// KEY2 OVER
//		case 0x03:		// UNK
//		case 0x23:		// UNK
//		case 0x92:		// UNK
//		case 0xb2:		// UNK
//		case 0x96:		// KEY1 EDGE?
//		case 0xb6:		// KEY2 EDGE?
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(0xda);
			tmpResp.addByte(nextCommand[3]);
			break;
		default:
/*			printf("UNKNOWN KEY COMMAND %02x DATA ",nextCommand[3]);
			for(int i=0;i<=nextCommand[0];i++) {
				printf("%02x ",nextCommand[i]);
			}
			printf("\n");*/
			return;
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(0xda);
			tmpResp.addByte(nextCommand[3]);
			break;
	}

	switch(nextCommand[3]) {
		case KEY1_FILL:
		case KEY2_FILL:
			tmpResp.addByte(0x00);
			break;
	}

	conn()->addResponse(tmpResp);
}
