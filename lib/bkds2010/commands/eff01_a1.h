#ifndef EFF01_A1_H
#define EFF01_A1_H

#include "command.h"


class effect;

class eff01_a1 : public command {
public:
    eff01_a1(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char config_[2];
};

#endif
