#include <stdio.h>
#include <iostream>
#include <cstring>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "gpiin.h"

using namespace std;

#define EFF_PP		0x00
#define EFF_ME1		0x01

gpiin::gpiin(connectionHandler *conn, effect *eff) : command(conn, eff) {

	memset(status00,0x00,sizeof(status00));
	status00[0x07][0] = 0x20;
	status00[0x07][1] = 0x07;
	status00[0x08][0] = 0x20;
	status00[0x08][1] = 0x08;

	memset(status03,0xff,sizeof(status03));

	memset(status08,0x00,sizeof(status08));

}

void gpiin::exec(unsigned char *nextCommand) {

	DEBUG_NC
	
	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	tmpResp.addByte(nextCommand[4]);

	switch(nextCommand[3]) {
		case 0x00:
			if(nextCommand[2] >= 0x80) {
				status00[nextCommand[4]][0] = nextCommand[5];
				status00[nextCommand[4]][1] = nextCommand[6];
			}
			tmpResp.addByte(status00[nextCommand[4]][0]);
			tmpResp.addByte(status00[nextCommand[4]][1]);
			break;
		case 0x03:
			if(nextCommand[2] >= 0x80) {
				status03[nextCommand[4]] = nextCommand[5];
			}
			tmpResp.addByte(status03[nextCommand[4]]);
			break;
		case 0x08:
			if(nextCommand[2] >= 0x80) {
				status08[nextCommand[4]][0] = nextCommand[5];
				status08[nextCommand[4]][1] = nextCommand[6];
				status08[nextCommand[4]][2] = nextCommand[7];
				if(status08[nextCommand[4]][0] == 0x01) {
					status08[nextCommand[4]][3] = nextCommand[8];
					status08[nextCommand[4]][4] = nextCommand[9];
					status08[nextCommand[4]][5] = nextCommand[10];
				}
			}
			tmpResp.addByte(status08[nextCommand[4]][0]);
			tmpResp.addByte(status08[nextCommand[4]][1]);
			tmpResp.addByte(status08[nextCommand[4]][2]);
			if(status08[nextCommand[4]][0] == 0x01) {
				tmpResp.addByte(status08[nextCommand[4]][3]);
				tmpResp.addByte(status08[nextCommand[4]][4]);
				tmpResp.addByte(status08[nextCommand[4]][5]);
			}
			break;
	}

	conn()->addResponse(tmpResp);

}
