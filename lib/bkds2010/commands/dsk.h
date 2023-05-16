#ifndef DSK_H
#define DSK_H

#include "command.h"

class dsk : public command {
public:
    dsk(effect*);
    void exec(unsigned char*);
};

#endif
