#ifndef EFF00_13_H
#define EFF00_13_H

#include "command.h"

class effect;

class eff00_13 : public command {
public:
    eff00_13(std::shared_ptr<effect>);
    void exec(unsigned char*);
};

#endif
