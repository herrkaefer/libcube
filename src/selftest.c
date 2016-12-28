/*  =========================================================================
    selftest.c - self tests

    Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
    =========================================================================
*/

#include "classes.h"

typedef struct {
    const char *testname;
    void (*test) (bool);
} test_item_t;

static test_item_t
all_tests [] = {
// #ifdef WITH_DRAFTS
    { "arrayset", arrayset_test },
    { "hash", hash_test },
    { "listu", listu_test },
    { "listx", listx_test },
    { "matrixd", matrixd_test },
    { "matrixu", matrixu_test },
    { "queue", queue_test },
    { "rng", rng_test },
    { "timer", timer_test },
    { "evol", evol_test },
// #endif // WITH_DRAFTS
    {0, 0}          //  Sentinel
};


static void test_runall (bool verbose) {
    test_item_t *item;
    printf ("Running selftests...\n");
    for (item = all_tests; item->test; item++)
        item->test (verbose);
    printf ("Tests passed OK.\n");
}


int main (int argc, char **argv) {
    test_runall (true);
    return 0;
}
