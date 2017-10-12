#ifndef __ARC_H__
#define __ARC_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef void (*arc_func_t) (void *);

arc_t           *arc_new(uint32_t n);
arc_benchmark_t *arc_benchmark_new(const char *name, arc_func_t t, uint64_t iter, void *opaque);

void arc_register(arc_t *arc, arc_benchmark_t *t);
void arc_run(arc_t *arc);
void arc_report(arc_t *arc);

#endif // __ARC_H__
