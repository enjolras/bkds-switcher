#ifndef KEY_H
#define KEY_H

#include "command.h"

#define KEY1_FILL   0x00
#define KEY1_SOURCE 0x01
#define KEY1_TYPE   0x05
#define KEY1_EDGE   0x06
#define KEY1_TRANS  0x10
#define KEY1_INV    0x11
#define KEY1_MAIN   0x12
#define KEY1_SUB    0x13
#define KEY1_15     0x15
#define KEY1_FINE   0x90
#define KEY1_DEPTH  0x91
#define KEY1_PROC   0x93
#define KEY2_FILL   0x20
#define KEY2_SOURCE 0x21
#define KEY2_TYPE   0x25
#define KEY2_EDGE   0x26
#define KEY2_TRANS  0x30
#define KEY2_INV    0x31
#define KEY2_MAIN   0x32
#define KEY2_SUB    0x33
#define KEY2_35     0x35
#define KEY2_FINE   0xb0
#define KEY2_DEPTH  0xb1
#define KEY2_PROC   0xb3

class key : public command {
public:
    key(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
