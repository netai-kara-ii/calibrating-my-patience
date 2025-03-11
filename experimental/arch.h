#ifndef __ARCH_H_
#define __ARCH_H_


#if defined(__x86_64__) || defined(_M_X64)
#define X86_ARCH
#elif defined(__aarch64__) || defined(_M_ARM64)
#define ARCH_ARM 
#else
#error " Computer architecture unsupported "
#endif


#endif
