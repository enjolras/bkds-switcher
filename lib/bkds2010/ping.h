#ifndef PING_H
#define PING_H

#include "command.h"

class connectionHandler;
class effect;

class ping : public command {
public:
	ping(connectionHandler*, effect*);
	void exec(unsigned char*);
};

#endif
