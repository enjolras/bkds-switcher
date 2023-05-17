#ifndef KEYPARAMS_H
#define KEYPARAMS_H

#include "command.h"

class keyparams : public command {
public:
    keyparams(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256][2];
};

#endif
