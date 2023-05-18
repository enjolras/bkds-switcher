#include <cstring>
#include "keyparams.h"
#include "../response.h"
#include "../effects/effect.h"
#include "knobs.h"

using namespace std;

keyparams::keyparams(effect* eff) : command(eff) {

	knobs_ = new knobs();
	memset(config_,0x00,sizeof(config_));

}

void keyparams::exec(unsigned char *nextCommand) {

	response tmpResp;

	switch(nextCommand[2] | 0x80) {
		case 0xac:
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
			break;
		case 0xa4:
			knobs_->type1(config_[nextCommand[3]],nextCommand[4]);
			break;
	}
}
