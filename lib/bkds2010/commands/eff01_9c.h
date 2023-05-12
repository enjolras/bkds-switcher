#ifndef EFF01_9C_H
#define EFF01_9C_H

#include "command.h"


class effect;

class eff01_9c : public command {
public:
    eff01_9c(std::shared_ptr<effect>);
    void exec(unsigned char*);
};

#endif
