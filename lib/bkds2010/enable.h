#ifndef ENABLE_H
#define ENABLE_H

#include "command.h"

class connectionHandler;
class effect;

class enable : public command {
public:
	enable(connectionHandler*, effect*);
	void exec(unsigned char*);
};

#endif 
