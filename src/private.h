#ifndef __ARC_PRIVATE_H__
#define __ARC_PRIVATE_H__

typedef struct arc_s           arc_t;
typedef struct arc_benchmark_s arc_benchmark_t;

#include "arc.h"
#include "cycle.h"
#include "benchmark.h"

struct arc_s {
    arc_benchmark_t **benchmarks;
    uint16_t        n_benchmarks;
    uint16_t        n;
};



#endif // __ARC_PRIVATE_H__
