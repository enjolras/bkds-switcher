#ifndef EVENTMEM_H
#define EVENTMEM_H

#include "command.h"

class eventmem : public command {
public:
	eventmem(effect*);
	void exec(unsigned char*);
};

#endif
