#ifndef EFF01_A1_H
#define EFF01_A1_H

#include "command.h"

class eff01_a1 : public command {
public:
    eff01_a1(effect*);
    void exec(unsigned char*);

private:
	unsigned char config_[2];
};

#endif
