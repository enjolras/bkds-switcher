#ifndef FINEKEY_H
#define FINEKEY_H

#include "command.h"

class finekey : public command {
public:
    finekey(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256][2];
};

#endif
