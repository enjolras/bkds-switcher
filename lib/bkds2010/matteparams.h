#ifndef MATTEPARAMS_H
#define MATTEPARAMS_H

#include "command.h"

class connectionHandler;
class effect;

class matteparams : public command {
public:
    matteparams(connectionHandler*, effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256][2];
};

#endif
