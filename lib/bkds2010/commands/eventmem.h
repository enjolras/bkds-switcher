#ifndef EVENTMEM_H
#define EVENTMEM_H

#include "command.h"

class connectionHandler;
class effect;

class eventmem : public command {
public:
	eventmem(connectionHandler*, effect*);
	void exec(unsigned char*);
};

#endif
