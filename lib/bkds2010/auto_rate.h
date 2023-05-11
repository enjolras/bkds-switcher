#ifndef AUTO_RATE_H
#define AUTO_RATE_H

#include "command.h"

class connectionHandler;
class effect;

class auto_rate : public command {
public:
    auto_rate(connectionHandler*, effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
