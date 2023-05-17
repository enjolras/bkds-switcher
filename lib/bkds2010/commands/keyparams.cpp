#include "keyparams.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

keyparams::keyparams(effect* eff) : command(eff) {

    config_[0x80][0] = 0x00;
    config_[0x80][1] = 0x00;
    config_[0x81][0] = 0x00;
    config_[0x81][1] = 0x00;
    config_[0x82][0] = 0x00;
    config_[0x82][1] = 0x00;
    config_[0x83][0] = 0x00;
    config_[0x83][1] = 0x00;
    config_[0x84][0] = 0x00;
    config_[0x84][1] = 0x00;
    config_[0x85][0] = 0x00;
    config_[0x85][1] = 0x00;
    config_[0x94][0] = 0x00;
    config_[0x94][1] = 0x00;
    config_[0x95][0] = 0x00;
    config_[0x95][1] = 0x00;
    config_[0xa0][0] = 0x00;
    config_[0xa0][1] = 0x00;
    config_[0xa1][0] = 0x00;
    config_[0xa1][1] = 0x00;
    config_[0xa2][0] = 0x00;
    config_[0xa2][1] = 0x00;
    config_[0xa3][0] = 0x00;
    config_[0xa3][1] = 0x00;
    config_[0xa4][0] = 0x00;
    config_[0xa4][1] = 0x00;
    config_[0xa5][0] = 0x00;
    config_[0xa5][1] = 0x00;
    config_[0xb4][0] = 0x00;
    config_[0xb4][1] = 0x00;
    config_[0xb5][0] = 0x00;
    config_[0xb5][1] = 0x00;

}

void keyparams::exec(unsigned char *nextCommand) {

	for(int i=0;i<=nextCommand[0];i++) {
		printf("%02x ",nextCommand[i]);
	}
	printf("\n");

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

	eff()->addResponse(tmpResp);

}
