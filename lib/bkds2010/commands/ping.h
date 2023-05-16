#ifndef PING_H
#define PING_H

#include "command.h"

class ping : public command {
public:
	ping(effect*);
    void exec(unsigned char*);
};

#endif
