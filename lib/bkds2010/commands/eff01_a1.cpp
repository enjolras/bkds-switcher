#include "eff01_a1.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

eff01_a1::eff01_a1(effect* eff) : command(eff) {

	config_[0] = 0x00;
	config_[1] = 0x00;
}

void eff01_a1::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	if(nextCommand[2] >= 0x80) {
		config_[0] = nextCommand[3];
		config_[1] = nextCommand[4];
	}
	tmpResp.addByte(config_[0]);
	tmpResp.addByte(config_[1]);

	eff()->addResponse(tmpResp);
}
