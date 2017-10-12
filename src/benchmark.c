#include "private.h"


arc_benchmark_t *
arc_benchmark_new(const char *name, arc_func_t t, uint64_t iter, void *opaque)
{
    arc_benchmark_t *benchmark;

    benchmark = calloc(1, sizeof(arc_benchmark_t));
    if (benchmark == NULL) {
        return NULL;
    }

    strncpy(benchmark->name, name, 64);
    benchmark->func = t;
    benchmark->iter = iter;
    benchmark->opaque = opaque;
    return benchmark;
}


void
arc_benchmark_run(arc_benchmark_t *benchmark)
{
    uint64_t c1, c2;
    uint64_t i;

    for (i = 0; i < benchmark->iter; i++) {
        c1 = arc_rdtsc();
        benchmark->func(benchmark->opaque);
        c2 = arc_rdtsc();

        benchmark->cycle_total += c2 - c1;
    }

    benchmark->cycle_per_iter = (uint64_t) (benchmark->cycle_total / benchmark->iter);
    benchmark->ns_total = (benchmark->cycle_total / arc_host_frequency) * 1000000000;
    benchmark->ns_per_iter = (uint64_t) (benchmark->ns_total / benchmark->iter);

}

void
arc_benchmark_report(arc_benchmark_t *benchmark)
{
    double seconds;

    seconds = benchmark->ns_total / 1000000000;
    printf("Benchmark %s\n",            benchmark->name);
    printf("Total Time %lu (%0.2fs)\n", benchmark->ns_total, seconds);
}
