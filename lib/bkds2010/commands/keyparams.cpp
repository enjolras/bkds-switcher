#include <cstring>
#include "keyparams.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

keyparams::keyparams(effect* eff) : command(eff) {

	memset(config_,0x00,sizeof(config_));
}

void keyparams::exec(unsigned char *nextCommand) {

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
