#ifndef EFF_AUX_H
#define EFF_AUX_H

#include "effect.h"

class eff_aux : public effect {
public:
	eff_aux(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
