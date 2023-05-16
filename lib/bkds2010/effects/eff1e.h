#ifndef EFF1E_H
#define EFF1E_H

#include "effect.h"

class eff1e : public effect {
public:
	eff1e(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
