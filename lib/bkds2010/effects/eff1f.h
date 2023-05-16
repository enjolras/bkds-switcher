#ifndef EFF1F_H
#define EFF1F_H

#include "effect.h"

class eff1f : public effect {
public:
	eff1f(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
