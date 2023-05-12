#ifndef MIXPARAMS_H
#define MIXPARAMS_H

#include "command.h"


class effect;

class mixparams : public command {
public:
    mixparams(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char config_[256][2];
};

#endif
