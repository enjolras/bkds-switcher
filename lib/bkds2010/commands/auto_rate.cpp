#include <stdio.h>
#include <iostream>
#include "effect.h"
#include "../effectDispatcher.h"
#include "auto_rate.h"

using namespace std;

auto_rate::auto_rate(std::shared_ptr<effect> eff) : command(eff) {

	switch(eff->myId()) {
		case 0x00:
		    config_[0] = 0x00;
		    config_[1] = 0x25;
			config_[2] = 0x80;
			config_[3] = 0x25;
			break;
		case 0x01:
		    config_[0] = 0x00;
			config_[1] = 0x25;
			break;
	}

}

void auto_rate::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);


	if(nextCommand[2] < 0x80) {
		if(nextCommand[3] >= 0x80) {
			tmpResp.addByte(config_[2]);
			tmpResp.addByte(config_[3]);
		} else {
			tmpResp.addByte(config_[0]);
			tmpResp.addByte(config_[1]);
		}
	} else {
		if(nextCommand[3] >= 0x80) {
			config_[2] = nextCommand[3];
			config_[3] = nextCommand[4];
		} else {
			config_[0] = nextCommand[3];
			config_[1] = nextCommand[4];
		}
		tmpResp.addByte(nextCommand[3]);
		tmpResp.addByte(nextCommand[4]);
	}

	conn()->addResponse(tmpResp);
}
