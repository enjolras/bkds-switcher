#ifndef WIPEPOS_H
#define WIPEPOS_H

#include "command.h"

class connectionHandler;
class effect;

class wipepos : public command {
public:
    wipepos(connectionHandler*, effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
