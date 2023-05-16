#ifndef EFF00_13_H
#define EFF00_13_H

#include "command.h"

class eff00_13 : public command {
public:
    eff00_13(effect*);
    void exec(unsigned char*);
};

#endif
