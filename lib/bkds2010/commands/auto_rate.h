#ifndef AUTO_RATE_H
#define AUTO_RATE_H

#include "command.h"

class auto_rate : public command {
public:
    auto_rate(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
