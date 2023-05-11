#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "eff00_13.h"

using namespace std;

#define EFF_PP		0x00
#define EFF_ME1		0x01

eff00_13::eff00_13(connectionHandler *conn, effect *eff) : command(conn, eff) {

}

void eff00_13::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(0x01);

	conn()->addResponse(tmpResp);
}
