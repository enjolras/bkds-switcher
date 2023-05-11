#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "mixparams.h"

using namespace std;

#define EFF_PP		0x00
#define EFF_ME1		0x01

mixparams::mixparams(connectionHandler *conn, effect *eff) : command(conn, eff) {

    config_[0x00][0] = 0x00;
    config_[0x00][1] = 0x00;
    config_[0x01][0] = 0x00;
    config_[0x01][1] = 0x00;
    config_[0x02][0] = 0x00;
    config_[0x02][1] = 0x00;

}

void mixparams::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	if(nextCommand[2] >= 0x80) {
		config_[nextCommand[3]][0] = nextCommand[4];
		config_[nextCommand[3]][1] = nextCommand[5];
	}
	tmpResp.addByte(config_[nextCommand[3]][0]);
	tmpResp.addByte(config_[nextCommand[3]][1]);

	conn()->addResponse(tmpResp);

}