#include <stdio.h>
#include <iostream>
#include <cstring>
#include "connectionHandler.h"
#include "effectDispatcher.h"
#include "matteparams.h"

using namespace std;

#define CMD_30		0x30
#define CMD_B0		0xb0

#define CMD_BKGD_R	0x2a
#define CMD_BKGD_W	0xaa
#define CMD_KEY1F_R	0x31
#define CMD_KEY1F_W	0xb1
#define CMD_KEY1E_R	0x32
#define CMD_KEY1E_W	0xb2
#define CMD_WIPEB_R	0x37
#define CMD_WIPEB_W	0xb7
#define CMD_KEY2F_R	0x39
#define CMD_KEY2F_W	0xb9
#define CMD_KEY2E_R	0x3a
#define CMD_KEY2E_W	0xba

#define PARAM_BKGD_MAT1_LUM	0x00
#define PARAM_BKGD_MAT1_SAT	0x01
#define PARAM_BKGD_MAT1_HUE	0x02
#define PARAM_BKGD_MAT2_LUM	0x03
#define PARAM_BKGD_MAT2_SAT	0x04
#define PARAM_BKGD_MAT2_HUE	0x05
#define PARAM_COLOR_MIX	0x08
#define PARAM_MAT1_LUM	0x88
#define PARAM_MAT1_SAT	0x89
#define PARAM_MAT1_HUE	0x8a
#define PARAM_MAT2_LUM	0x8b
#define PARAM_MAT2_SAT	0x8c
#define PARAM_MAT2_HUE	0x8d

#define EFF_PP		0x00
#define EFF_ME1		0x01
#define EFF_MATTE	0x18

matteparams::matteparams(connectionHandler *conn, effect *eff) : command(conn, eff) {

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

	conn()->addResponse(tmpResp);

}
