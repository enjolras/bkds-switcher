#include "wipe.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

wipe::wipe(effect* eff) : command(eff) {

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

	eff()->addResponse(tmpResp);
}
