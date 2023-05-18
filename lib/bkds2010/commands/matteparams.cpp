#include <cstring>
#include "matteparams.h"
#include "knobs.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

matteparams::matteparams(effect* eff) : command(eff) {

	knobs_ = new knobs();
	memset(config_,0x00,sizeof(config_));

}

void matteparams::exec(unsigned char *nextCommand) {

	response tmpResp;

	switch(nextCommand[2]) {
		case 0x30:
		case 0xb0:
			tmpResp.addByte(nextCommand[1]);
			tmpResp.addByte(nextCommand[2] | 0x80);
			tmpResp.addByte(nextCommand[3]);
			switch(nextCommand[3]) {
				case 0x00:
					tmpResp.addByte(0x01);
					break;
				default:
					return;
			}
			break;
		case CMD_KEY1F_R:
		case CMD_KEY1F_W:
		case CMD_KEY2F_R:
		case CMD_KEY2F_W:
		case CMD_KEY1E_R:
		case CMD_KEY1E_W:
		case CMD_KEY2E_R:
		case CMD_KEY2E_W:
		case CMD_WIPEB_R:
		case CMD_WIPEB_W:
		case CMD_BKGD_R:
		case CMD_BKGD_W:
			switch(nextCommand[3]) {
				case PARAM_COLOR_MIX:
					tmpResp.addByte(nextCommand[1]);
					tmpResp.addByte(nextCommand[2] | 0x80);
					tmpResp.addByte(nextCommand[3]);
					if(nextCommand[2] >= 0x80) {
						config_[nextCommand[3]][0] = nextCommand[4];
					}
					tmpResp.addByte(config_[nextCommand[3]][0]);
					break;
				case PARAM_MAT1_LUM:
				case PARAM_MAT1_SAT:
				case PARAM_MAT1_HUE:
				case PARAM_MAT2_LUM:
				case PARAM_MAT2_SAT:
				case PARAM_MAT2_HUE:
				case PARAM_BKGD_MAT1_LUM:
				case PARAM_BKGD_MAT1_SAT:
				case PARAM_BKGD_MAT1_HUE:
				case PARAM_BKGD_MAT2_LUM:
				case PARAM_BKGD_MAT2_SAT:
				case PARAM_BKGD_MAT2_HUE:
					tmpResp.addByte(nextCommand[1]);
					tmpResp.addByte(nextCommand[2] | 0x80);
					tmpResp.addByte(nextCommand[3]);
					if(nextCommand[2] >= 0x80) {
						config_[nextCommand[3]][0] = nextCommand[4];
						config_[nextCommand[3]][1] = nextCommand[5];
					}
					tmpResp.addByte(config_[nextCommand[3]][0]);
					tmpResp.addByte(config_[nextCommand[3]][1]);
					break;
				case PARAM_MAT1_LUM_KNOB:
				case PARAM_MAT1_SAT_KNOB:
				case PARAM_MAT2_LUM_KNOB:
				case PARAM_MAT2_SAT_KNOB:
					knobs_->type1(config_[nextCommand[3]+0x08],nextCommand[4]);
					break;
				case PARAM_MAT1_HUE_KNOB:
				case PARAM_MAT2_HUE_KNOB:
					knobs_->type2(config_[nextCommand[3]+0x08],nextCommand[4]);
					break;
				default:
					return;
			}
			break;
	}

	eff()->addResponse(tmpResp);

}
