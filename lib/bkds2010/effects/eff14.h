#ifndef EFF14_H
#define EFF14_H

#include "effect.h"

class eff14 : public effect {
public:
	eff14(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
