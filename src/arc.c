#include "private.h"


arc_t *
arc_new(uint32_t n)
{
    arc_t *arc;

    arc = calloc(1, sizeof(arc_t));
    if (arc == NULL) {
        return NULL;
    }

    arc->benchmarks = calloc(n, sizeof(arc_benchmark_t));
    if (arc->benchmarks == NULL) {
        return NULL;
    }
    arc->n_benchmarks = n;
    arc->n = 0;

    return arc;
}


void
arc_register(arc_t *arc, arc_benchmark_t *bench)
{
    arc->benchmarks[arc->n++] = bench;
}


void
arc_run(arc_t *arc)
{
    uint32_t i;

    printf("Running %d benchmarks...\n", arc->n);

    for (i = 0; i < arc->n; i++) {
        arc_benchmark_run(arc->benchmarks[i]);
    }

    printf("Done....\n");

}


void
arc_report(arc_t *arc)
{
    uint32_t i;

    for (i = 0; i < arc->n; i++) {
        arc_benchmark_report(arc->benchmarks[i]);
    }

}
