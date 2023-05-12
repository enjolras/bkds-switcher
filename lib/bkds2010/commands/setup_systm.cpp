#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "effectDispatcher.h"
#include "setup_systm.h"

using namespace std;

setup_systm::setup_systm(std::shared_ptr<effect> eff) : command(eff) {

    config_[0x00] = 0x00;
    config_[0x0a] = 0x01;
    config_[0x0e] = 0x00;

}

void setup_systm::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	switch(nextCommand[3]) {
		case 0x00:			// TOGGLE - 0x00 = OFF - 0x01 = ON
			if(nextCommand[2] >= 0x80) {
				config_[0x00] = nextCommand[4];
			}
			tmpResp.addByte(config_[0x00]);
			break;
		case 0x05:			// PERPH AUXSS
			tmpResp.addByte(nextCommand[4]);
			tmpResp.addByte(nextCommand[5]);
			if(nextCommand[2] < 0x80) {
				tmpResp.addByte(0x01);
			} else {
				tmpResp.addByte(nextCommand[6]);
			}
			break;
		case 0x0a:			// SCREEN ASPECT RATIO - 0x00 = 4:3 - 0x01 = 16:9
			if(nextCommand[2] >= 0x80) {
				config_[0x0a] = nextCommand[4];
			}
			tmpResp.addByte(config_[0x0a]);
			break;
		case 0x0e:			// SWITCH - 0x00 = ANY - 0x01 = F1 - 0x02 = F2
			if(nextCommand[2] >= 0x80) {
				config_[0x0e] = nextCommand[4];
			}
			tmpResp.addByte(config_[0x0e]);
			break;
		case 0x10:			// INPUT XPT
			tmpResp.addByte(nextCommand[4]);
			tmpResp.addByte(0x01);
			break;
		case 0x11:			// INPUT AUTO
			tmpResp.addByte(nextCommand[4]);
			tmpResp.addByte(0x02);
			break;
		default:
			return;
	}

	conn()->addResponse(tmpResp);

}
