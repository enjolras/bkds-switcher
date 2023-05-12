#include <stdio.h>
#include <iostream>
#include "effectDispatcher.h"
#include "wipe.h"

using namespace std;

#define WIPE_TYPE	0x00
#define WIPE_ROT	0x03
#define WIPE_DIR	0x04
#define WIPE_10		0x10
#define WIPE_11		0x11
#define WIPE_POSON	0x15
#define WIPE_ATCTR	0x16
#define WIPE_ASPECT	0x17
#define WIPE_BORD	0x19
#define WIPE_SOFT	0x1a
#define WIPE_MULTI1	0x22
#define WIPE_MULTI2	0x23
#define WIPE_USER	0x41

wipe::wipe(std::shared_ptr<effect> eff) : command(eff) {

    config_[0x00] = 0x00;
    config_[0x01] = 0x01;
    config_[0x04] = 0x02;
    config_[0x03] = 0x00;

}

void wipe::exec(unsigned char *nextCommand) {

	response tmpResp;

	switch(nextCommand[3]) {
		case WIPE_TYPE:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2] | 0x80);
			if(nextCommand[2] >= 0x80) {
				config_[nextCommand[3]] = nextCommand[4];
				config_[nextCommand[3]+1] = nextCommand[5];
			}
			tmpResp.addByte(nextCommand[3]);
			tmpResp.addByte(config_[nextCommand[3]]);
			tmpResp.addByte(config_[nextCommand[3]+1]);
			break;
		case WIPE_USER:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2]);
			tmpResp.addByte(nextCommand[3]);
			tmpResp.addByte(nextCommand[4]);
			break;
		case WIPE_DIR:
		case WIPE_ROT:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2] | 0x80);
			if(nextCommand[2] >= 0x80) {
				config_[nextCommand[3]] = nextCommand[4];
			}
			tmpResp.addByte(nextCommand[3]);
			tmpResp.addByte(config_[nextCommand[3]]);
			break;
		case WIPE_POSON:
		case WIPE_ASPECT:
		case WIPE_BORD:
		case WIPE_SOFT:
		case WIPE_MULTI1:
		case WIPE_MULTI2:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2] | 0x80);
			tmpResp.addByte(nextCommand[3]);
			break;
		case WIPE_ATCTR:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte((nextCommand[2] | 0x80)); // + 0x40);
			tmpResp.addByte(nextCommand[3]);
			break;
		default:
			printf("UNKNOWN WIPE COMMAND %02x DATA ",nextCommand[3]);
			for(int i=0;i<=nextCommand[0];i++) {
				printf("%02x ",nextCommand[i]);
			}
			printf("\n");
			break;
	}

	conn()->addResponse(tmpResp);
}
