#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "eff01_9c.h"

using namespace std;

#define EFF_PP		0x00
#define EFF_ME1		0x01

eff01_9c::eff01_9c(connectionHandler *conn, effect *eff) : command(conn, eff) {

}

void eff01_9c::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	tmpResp.addByte(0x01);

	conn()->addResponse(tmpResp);
}
