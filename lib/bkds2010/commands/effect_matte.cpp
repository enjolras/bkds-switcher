#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "effect_matte.h"

using namespace std;

effect_matte::effect_matte(connectionHandler *conn, effect *eff) : command(conn, eff) {

	config_[0x00] = 0x00;
	config_[0x01] = 0x00;
	config_[0x02] = 0x00;

}

void effect_matte::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	if(nextCommand[2] >= 0x80) {
		config_[nextCommand[3]] = nextCommand[4];
	}
	tmpResp.addByte(config_[nextCommand[3]]);

	conn()->addResponse(tmpResp);
}
