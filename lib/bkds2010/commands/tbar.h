#ifndef TBAR_H
#define TBAR_H

#include "command.h"


class effect;

class tbar : public command {
public:
	tbar(std::shared_ptr<effect>);
	void exec(unsigned char*);

private:
	connectionHandler* conn_;
};

#endif 
