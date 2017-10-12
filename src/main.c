#include "private.h"

void
test_1(void *context)
{
    int s = rand() % 5;
    printf("sleeping for %d\n", s);
    sleep(s);
}

void
test_2(void *context)
{
    int s = rand() % 5;
    printf("sleeping for 2 %d\n", s);
    sleep(s);
}


int
main(int argc, char const *argv[])
{
    arc_t *arc;
    arc_benchmark_t *benchmark_1, *benchmark_2;
    srand(time(NULL));

    arc = arc_new(16);
    if (arc == NULL) {
        printf("Cannot initialize arc\n");
        exit(1);
    }


    benchmark_1 = arc_benchmark_new("test1", test_1, 5, NULL);
    benchmark_2 = arc_benchmark_new("test2", test_2, 5, NULL);
    arc_register(arc, benchmark_1);
    arc_register(arc, benchmark_2);

    arc_run(arc);
    arc_report(arc);

    // uint64_t ts1 = arc_rdtsc();
    // sleep(1);
    // uint64_t ts2 = arc_rdtsc();
    // printf("%lu\n", arc_host_frequency);
    // printf("%lu\n", ts2-ts1);


    test_1(NULL);
    return 0;
}
