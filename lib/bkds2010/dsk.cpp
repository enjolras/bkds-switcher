#include <stdio.h>
#include <iostream>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "dsk.h"

using namespace std;

#define EFF_PP		0x00
#define EFF_ME1		0x01

dsk::dsk(connectionHandler *conn, effect *eff) : command(conn, eff) {

}

void dsk::exec(unsigned char *nextCommand) {

	response tmpResp;

	switch(nextCommand[2]) {
		case 0xd3:
		case 0x93:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2]);
			break;
		case 0x90:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2]);
			tmpResp.addByte(nextCommand[3]);
			break;
	}

	conn()->addResponse(tmpResp);
}
