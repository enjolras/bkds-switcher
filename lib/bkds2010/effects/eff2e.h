#ifndef EFF2E_H
#define EFF2E_H

#include "effect.h"

class eff2e : public effect {
public:
	eff2e(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
