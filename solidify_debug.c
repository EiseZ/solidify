/*
// Solidify
// A base header file to include in every C project.
//
// Eise Zimmerman
//
// Licensed under the MIT license (https://opensource.org/licenses/MIT)
*/

#define SOLIDIFY_NO_DEBUG
#include "solidify.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct
{
    uint32 allocations;
    uint32 frees;
} memoryState = { 0, 0 };

void
solidify_debug_print_memory_state(void)
{
    printf("[Solidify] Memory state: allocations: %u; frees: %u\n",
           memoryState.allocations, memoryState.frees);
    return;
}

void *
solidify_debug_malloc(uint size, char *file, uint line)
{
    void *p = malloc(size);

    if (p == NULL) {
        printf
            ("[Solidify] Memory error: malloc call of %u bytes failed in file %s on line %u\n",
             size, file, line);
        solidify_debug_print_memory_state();
        exit(1);
    }

    memoryState.allocations++;

    return p;
}

void *
solidify_debug_realloc(void *pointer, uint size, char *file, uint line)
{
    if (pointer == NULL)
        return solidify_debug_malloc(size, file, line);

    void *p = realloc(pointer, size);

    if (p == NULL) {
        printf
            ("[Solidify] Memory error: realloc call of %u bytes failed in file %s on line %u\n",
             size, file, line);
        solidify_debug_print_memory_state();
        exit(1);
    }

    return p;
}

void
solidify_debug_free(void *pointer, char *file, uint line)
{
    free(pointer);
    memoryState.frees++;
    return;
}
