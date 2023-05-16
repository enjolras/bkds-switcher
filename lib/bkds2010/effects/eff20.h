#ifndef EFF20_H
#define EFF20_H

#include "effect.h"

class eff20 : public effect {
public:
	eff20(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
