#ifndef MATTEPARAMS_H
#define MATTEPARAMS_H

#include "command.h"

#define CMD_30      0x30
#define CMD_B0      0xb0

#define CMD_BKGD_R  0x2a
#define CMD_BKGD_W  0xaa
#define CMD_KEY1F_R 0x31
#define CMD_KEY1F_W 0xb1
#define CMD_KEY1E_R 0x32
#define CMD_KEY1E_W 0xb2
#define CMD_WIPEB_R 0x37
#define CMD_WIPEB_W 0xb7
#define CMD_KEY2F_R 0x39
#define CMD_KEY2F_W 0xb9
#define CMD_KEY2E_R 0x3a
#define CMD_KEY2E_W 0xba

#define PARAM_BKGD_MAT1_LUM 0x00
#define PARAM_BKGD_MAT1_SAT 0x01
#define PARAM_BKGD_MAT1_HUE 0x02
#define PARAM_BKGD_MAT2_LUM 0x03
#define PARAM_BKGD_MAT2_SAT 0x04
#define PARAM_BKGD_MAT2_HUE 0x05
#define PARAM_COLOR_MIX 0x08
#define PARAM_MAT1_LUM_KNOB 0x80
#define PARAM_MAT1_LUM  0x88
#define PARAM_MAT1_SAT_KNOB 0x81
#define PARAM_MAT1_SAT  0x89
#define PARAM_MAT1_HUE_KNOB 0x82
#define PARAM_MAT1_HUE  0x8a
#define PARAM_MAT2_LUM_KNOB 0x83
#define PARAM_MAT2_LUM  0x8b
#define PARAM_MAT2_SAT_KNOB 0x84
#define PARAM_MAT2_SAT  0x8c
#define PARAM_MAT2_HUE_KNOB 0x85
#define PARAM_MAT2_HUE  0x8d

class knobs;

class matteparams : public command {
public:
    matteparams(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256][2];
	knobs* knobs_;
};

#endif
