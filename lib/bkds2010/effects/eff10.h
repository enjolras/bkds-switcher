#ifndef EFF10_H
#define EFF10_H

#include "effect.h"

class eff10 : public effect {
public:
	eff10(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
