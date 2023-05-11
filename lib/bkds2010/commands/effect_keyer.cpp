#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "effect_keyer.h"

using namespace std;

effect_keyer::effect_keyer(connectionHandler *conn, effect *eff) : command(conn, eff) {

	config_[0x00][0x00] = 0x00;
	config_[0x03][0x01] = 0x00;
	config_[0x03][0x11] = 0x00;
	config_[0x03][0x12] = 0x00;

}

void effect_keyer::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	switch(nextCommand[3]) {
		case 0x00:
			if(nextCommand[2] >= 0x80) {
				config_[0x00][0] = nextCommand[4];
			}
			tmpResp.addByte(config_[0x00][0]);
			break;
		case 0x03:
			tmpResp.addByte(nextCommand[4]);
			if(nextCommand[2] >= 0x80) {
				config_[0x03][nextCommand[4]] = nextCommand[5];
			}
			tmpResp.addByte(config_[0x03][nextCommand[4]]);
			break;
		default:
			DEBUG_NC
			tmpResp.addByte(nextCommand[4]);
			tmpResp.debugResponse();
			break;
	}
			
	conn()->addResponse(tmpResp);
}
