#ifndef __ARC_BENCHMARK_H__
#define __ARC_BENCHMARK_H__

#include "private.h"

#define ARC_BENCHMARK_MAX 128

struct arc_benchmark_s {
    uint8_t    name[64];
    void       *opaque;
    arc_func_t func;
    uint64_t   iter;
    uint64_t   cycle_total;
    uint64_t   cycle_per_iter;
    uint64_t   ns_total;
    uint64_t   ns_per_iter;
};

void arc_benchmark_run(arc_benchmark_t *benchmark);
void arc_benchmark_report(arc_benchmark_t *benchmark);


#endif // __ARC_BENCHMARK_H__
