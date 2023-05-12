#ifndef MATTEPARAMS_H
#define MATTEPARAMS_H

#include "command.h"


class effect;

class matteparams : public command {
public:
    matteparams(std::shared_ptr<effect>);
    void exec(unsigned char*);

private:
	unsigned char config_[256][2];
};

#endif
