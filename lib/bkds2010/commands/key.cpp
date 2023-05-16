#include "key.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

key::key(effect* eff) : command(eff) {

	switch(eff->whoAmI()) {
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
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(0xda);
			tmpResp.addByte(nextCommand[3]);
			break;
		default:
			return;
	}

	switch(nextCommand[3]) {
		case KEY1_FILL:
		case KEY2_FILL:
			tmpResp.addByte(0x00);
			break;
	}

	eff()->addResponse(tmpResp);
}
