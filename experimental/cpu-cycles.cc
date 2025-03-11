#include "cpu-cycles.h"

#ifdef X86_ARCH
#include <x86intrin.h>

uint64_t CycleCounter::start() {
    uint32_t lo, hi;
    asm volatile ("cpuid\n\t"
                  "rdtsc"
                  : "=a"(lo), "=d"(hi)
                  :: "rcx", "rbx");
    return (static_cast<uint64_t>(hi) << 32) | lo;
}

uint64_t CycleCounter::stop() {
    uint32_t lo, hi;
    asm volatile ("rdtscp\n\t"
                  "cpuid"
                  : "=a"(lo), "=d"(hi)
                  :: "rcx", "rbx");
    return (static_cast<uint64_t>(hi) << 32) | lo;
}

#elif defined(ARCH_ARM)

uint64_t read_pmccntr() {
    uint64_t cycles;
    asm volatile(
        "mrs %0, PMCCNTR_EL0" 
        : "=r" (cycles)
    );
    return cycles;
}

uint64_t CycleCounter::start() {
    return read_pmccntr();
}

uint64_t CycleCounter::stop() {
    return read_pmccntr();
}

#endif
