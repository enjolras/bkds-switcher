#ifndef EFF15_H
#define EFF15_H

#include "effect.h"

class eff15 : public effect {
public:
	eff15(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
