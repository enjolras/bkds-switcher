#ifndef EFF_FRAMEMEM_H
#define EFF_FRAMEMEM_H

#include "effect.h"

class eff_framemem : public effect {
public:
	eff_framemem(unsigned char,effectDispatcher*);
	void init();
	void exec(unsigned char*);
};

#endif
