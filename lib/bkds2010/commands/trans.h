#ifndef TRANS_H
#define TRANS_H

#include "command.h"


class effect;

class trans : public command {
public:
    trans(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char config_[256];
};

#endif
