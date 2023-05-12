#ifndef AUTO_RATE_H
#define AUTO_RATE_H

#include "command.h"

class effect;

class auto_rate : public command {
public:
    auto_rate(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
