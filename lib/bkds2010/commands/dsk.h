#ifndef DSK_H
#define DSK_H

#include "command.h"

class effect;

class dsk : public command {
public:
    dsk(std::shared_ptr<effect>);
    void exec(unsigned char*);
};

#endif
