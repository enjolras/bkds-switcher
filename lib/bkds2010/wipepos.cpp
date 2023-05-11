#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "wipepos.h"

using namespace std;

#define EFF_PP		0x00
#define EFF_ME1		0x01

wipepos::wipepos(connectionHandler *conn, effect *eff) : command(conn, eff) {

    config_[0] = 0x80;
    config_[1] = 0x00;
    config_[2] = 0x80;
    config_[3] = 0x00;

}

void wipepos::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	if(nextCommand[2] >= 0x80) {
		config_[0] = nextCommand[3];
		config_[1] = nextCommand[4];
		config_[2] = nextCommand[5];
		config_[3] = nextCommand[6];
	}
	tmpResp.addByte(config_[0]);
	tmpResp.addByte(config_[1]);
	tmpResp.addByte(config_[2]);
	tmpResp.addByte(config_[3]);

	conn()->addResponse(tmpResp);

}
