#ifndef TBAR_H
#define TBAR_H

#include "command.h"

class tbar : public command {
public:
	tbar(effect*);
	void exec(unsigned char*);
};

#endif 
