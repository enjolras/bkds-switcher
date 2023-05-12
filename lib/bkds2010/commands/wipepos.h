#ifndef WIPEPOS_H
#define WIPEPOS_H

#include "command.h"


class effect;

class wipepos : public command {
public:
    wipepos(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
