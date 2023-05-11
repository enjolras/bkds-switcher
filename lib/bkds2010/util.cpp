#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "util.h"

using namespace std;

#define EFF_PP		0x00
#define EFF_ME1		0x01

util::util(connectionHandler *conn, effect *eff) : command(conn, eff) {

	data = 0x58;

}

void util::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	if(nextCommand[2] >= 0x80) {
		data = nextCommand[3];
	}
	tmpResp.addByte(data);

	conn()->addResponse(tmpResp);

}
