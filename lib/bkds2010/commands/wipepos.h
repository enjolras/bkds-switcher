#ifndef WIPEPOS_H
#define WIPEPOS_H

#include "command.h"

class wipepos : public command {
public:
    wipepos(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
