#ifndef ARCH_BUILD_H
#define ARCH_BUILD_H


#if defined(__x86_64__) || defined(_M_IX86) || defined(_M_X64)
#define X86_ARCH_BUILD
#elif defined(__aarch64__) || defined(_M_ARM64)
#define ARM64_ARCH_BUILD
#else
#error "computer architecture unsupported"
#endif


#if defined(__linux__)
#define PLATFORM_LINUX_BUILD
#elif defined(__APPLE__) || defined(__MACH__)
#define PLATFORM_MACOS_BUILD
#elif defined(_WIN32) || defined(_WIN64)
#define PLATFORM_WINDOWS_BUILD
#else
#error "please use an actual OS?"
#endif


#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define LITTLE_ENDIAN_BUILD
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define BIG_ENDIAN_BUILD
#else
#error "cannot establish byte ordering"
#endif


#endif
