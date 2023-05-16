#include "wipeparams.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

wipeparams::wipeparams(effect* eff) : command(eff) {

    config_[0x00][0] = 0x00;
    config_[0x00][1] = 0x00;
    config_[0x06][0] = 0x00;
    config_[0x06][1] = 0x00;
    config_[0x07][0] = 0x00;
    config_[0x07][1] = 0x00;
    config_[0x09][0] = 0x80;
    config_[0x09][1] = 0x00;
    config_[0x0a][0] = 0x80;
    config_[0x0a][1] = 0x00;
    config_[0x0b][0] = 0x80;
    config_[0x0b][1] = 0x00;
    config_[0x0c][0] = 0x00;
    config_[0x0c][1] = 0x00;
    config_[0x1c][0] = 0x00;
    config_[0x1c][1] = 0x00;
    config_[0x1d][0] = 0x00;
    config_[0x1d][1] = 0x00;

}

void wipeparams::exec(unsigned char *nextCommand) {

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
