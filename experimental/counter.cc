#include <iostream>


#include "cpu-cycles.h"


int main(void) {
    
    CycleCounter counter;

    uint64_t start = counter.start();
    for (volatile int i = 0; i < 1000000; i++);
    uint64_t stop = counter.stop();

    std::cout << stop - start << " elapsed cycles";
    return 0;
}
