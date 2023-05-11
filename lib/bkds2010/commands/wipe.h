#ifndef WIPE_H
#define WIPE_H

#include "command.h"

class connectionHandler;
class effect;

class wipe : public command {
public:
    wipe(connectionHandler*, effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
