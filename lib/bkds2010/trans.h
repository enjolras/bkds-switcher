#ifndef TRANS_H
#define TRANS_H

#include "command.h"

class connectionHandler;
class effect;

class trans : public command {
public:
    trans(connectionHandler*, effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
