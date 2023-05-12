#ifndef EFF2E_86_H
#define EFF2E_86_H

#include "command.h"


class effect;

class eff2e_86 : public command {
public:
	eff2e_86(std::shared_ptr<effect>);
	void exec(unsigned char*);
};

#endif 
