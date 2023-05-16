#ifndef MIXPARAMS_H
#define MIXPARAMS_H

#include "command.h"

class mixparams : public command {
public:
    mixparams(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256][2];
};

#endif
