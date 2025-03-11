#ifndef CPU_CYCLES_H
#define CPU_CYCLES_H

#include <stdint.h>

#include "arch.h"


class CycleCounter {
    public:
        uint64_t start(void);
        uint64_t stop(void);
};


#endif
