#ifndef EFF01_9C_H
#define EFF01_9C_H

#include "command.h"

class eff01_9c : public command {
public:
    eff01_9c(effect*);
    void exec(unsigned char*);
};

#endif
