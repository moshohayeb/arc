#ifndef __ARC_CYCLE_H__
#define __ARC_CYCLE_H__

#include "private.h"

extern uint64_t arc_host_frequency;

static inline __attribute__ ((always_inline))  uint64_t
arc_rdtsc(void)
{
    uint64_t low, high;

    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));

    return (high << 32) | low;
}

#endif // __ARC_CYCLE_H__
