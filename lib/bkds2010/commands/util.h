#ifndef UTIL_H
#define UTIL_H

#include "command.h"

class util : public command {
public:
    util(effect*);
    void exec(unsigned char*);

private:
	unsigned char data;
};

#endif
