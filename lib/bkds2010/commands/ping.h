#ifndef PING_H
#define PING_H

#include "command.h"


class effect;

class ping : public command {
public:
	ping(std::shared_ptr<effect>);
	void exec(unsigned char*);
};

#endif
