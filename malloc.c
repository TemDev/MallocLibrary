#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static int total = 0;
void *(*original_malloc)(size_t sz);


void *malloc(size_t sz) {
    if (!original_malloc) {
        original_malloc = dlsym(RTLD_NEXT, "malloc");
    }
    total += (int) sz;
    fprintf(stderr, "Total bytes allocated so far: %d\n", total);
    void *malloced = original_malloc(sz);

    return malloced;
}

