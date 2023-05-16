#ifndef WIPE_H
#define WIPE_H

#include "command.h"

#define WIPE_TYPE   0x00
#define WIPE_ROT    0x03
#define WIPE_DIR    0x04
#define WIPE_10     0x10
#define WIPE_11     0x11
#define WIPE_POSON  0x15
#define WIPE_ATCTR  0x16
#define WIPE_ASPECT 0x17
#define WIPE_BORD   0x19
#define WIPE_SOFT   0x1a
#define WIPE_MULTI1 0x22
#define WIPE_MULTI2 0x23
#define WIPE_USER   0x41

class wipe : public command {
public:
    wipe(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
