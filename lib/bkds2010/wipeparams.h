#ifndef WIPEPARAMS_H
#define WIPEPARAMS_H

#include "command.h"

class connectionHandler;
class effect;

class wipeparams : public command {
public:
    wipeparams(connectionHandler*, effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256][2];
};

#endif
