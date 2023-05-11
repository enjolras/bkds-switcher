#ifndef EFF01_8A_H
#define EFF01_8A_H

#include "command.h"

class connectionHandler;
class effect;

class eff01_8a : public command {
public:
    eff01_8a(connectionHandler*, effect*);
    void exec(unsigned char*);
};

#endif
