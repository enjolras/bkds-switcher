#ifndef ENABLE_H
#define ENABLE_H

#include "command.h"


class effect;

class enable : public command {
public:
	enable(std::shared_ptr<effect>);
	void exec(unsigned char*);
};

#endif 
