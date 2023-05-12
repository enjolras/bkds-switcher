#ifndef EVENTMEM_H
#define EVENTMEM_H

#include "command.h"


class effect;

class eventmem : public command {
public:
	eventmem(std::shared_ptr<effect>);
	void exec(unsigned char*);
};

#endif
