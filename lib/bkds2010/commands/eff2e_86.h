#ifndef EFF2E_86_H
#define EFF2E_86_H

#include "command.h"

class eff2e_86 : public command {
public:
	eff2e_86(effect*);
	void exec(unsigned char*);
};

#endif 
