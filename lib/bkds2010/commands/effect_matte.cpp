#include "effect_matte.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

effect_matte::effect_matte(effect* eff) : command(eff) {

	config_[0x00] = 0x00;
	config_[0x01] = 0x00;
	config_[0x02] = 0x00;
}

void effect_matte::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	if(nextCommand[2] >= 0x80) {
		config_[nextCommand[3]] = nextCommand[4];
	}
	tmpResp.addByte(config_[nextCommand[3]]);

	eff()->addResponse(tmpResp);
}
