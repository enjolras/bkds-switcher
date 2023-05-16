#ifndef ENABLE_H
#define ENABLE_H

#include "command.h"

class enable : public command {
public:
	enable(effect*);
	void exec(unsigned char*);
};

#endif 
