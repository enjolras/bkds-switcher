#ifndef TRANS_H
#define TRANS_H

#include "command.h"

class trans : public command {
public:
    trans(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
