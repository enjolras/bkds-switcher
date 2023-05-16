#include "matteparams.h"
#include "../response.h"
#include "../effects/effect.h"

using namespace std;

matteparams::matteparams(effect* eff) : command(eff) {

	config_[0x08][0] = 0x00;
	config_[0x0a][0] = 0x00;
	config_[0x0a][1] = 0x00;
    config_[0x88][0] = 0x00;
    config_[0x88][1] = 0x00;
    config_[0x89][0] = 0x00;
    config_[0x89][1] = 0x00;
    config_[0x8a][0] = 0x00;
    config_[0x8a][1] = 0x00;
    config_[0x8b][0] = 0x00;
    config_[0x8b][1] = 0x00;
    config_[0x8c][0] = 0x00;
    config_[0x8c][1] = 0x00;
    config_[0x8d][0] = 0x00;
    config_[0x8d][1] = 0x00;
	config_[0x00][0] = 0x00;
	config_[0x00][1] = 0x00;
	config_[0x01][0] = 0x00;
	config_[0x01][1] = 0x00;
	config_[0x02][0] = 0x00;
	config_[0x02][1] = 0x00;
	config_[0x03][0] = 0x00;
	config_[0x03][1] = 0x00;
	config_[0x04][0] = 0x00;
	config_[0x04][1] = 0x00;
	config_[0x05][0] = 0x00;
	config_[0x05][1] = 0x00;

}

void matteparams::exec(unsigned char *nextCommand) {

	response tmpResp;

	tmpResp.addByte(nextCommand[1]);
	tmpResp.addByte(nextCommand[2] | 0x80);
	tmpResp.addByte(nextCommand[3]);
	switch(nextCommand[2]) {
		case 0x30:
		case 0xb0:
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
					if(nextCommand[2] >= 0x80) {
						config_[nextCommand[3]][0] = nextCommand[4];
						config_[nextCommand[3]][1] = nextCommand[5];
					}
					tmpResp.addByte(config_[nextCommand[3]][0]);
					tmpResp.addByte(config_[nextCommand[3]][1]);
					break;
				default:
					return;
			}
			break;
	}

	eff()->addResponse(tmpResp);

}
