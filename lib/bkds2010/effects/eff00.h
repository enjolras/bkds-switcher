#ifndef EFF00_H
#define EFF00_H

#include <memory>
#include "effect.h"

class eff00 : public effect {
public:
	eff00(unsigned char,std::shared_ptr<effectDispatcher> const&);
	void init();
	void exec(unsigned char*);
};

#endif
