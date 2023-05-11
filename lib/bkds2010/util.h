#ifndef UTIL_H
#define UTIL_H

#include "command.h"

class connectionHandler;
class effect;

class util : public command {
public:
    util(connectionHandler*, effect*);
    void exec(unsigned char*);

private:
	unsigned char data;
};

#endif
