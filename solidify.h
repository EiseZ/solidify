/*
// Solidify
// A base header file to include in every C project.
//
// Eise Zimmerman
//
// Licensed under the MIT license (https://opensource.org/licenses/MIT)
*/

/* --- Types --- */
#if !defined(SOLIDIFY_NO_TYPES)
#define SOLIDIFY_NO_TYPES
#include <stdint.h>
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t   int8;
typedef int16_t  int16;
typedef int32_t  int32;
typedef int64_t  int64;

typedef unsigned int uint;
#endif

/* --- Memory debugging --- */
#if !defined(SOLIDIFY_NO_DEBUG)
#define SOLIDIFY_NO_DEBUG
extern void solidify_debug_print_memory_state(void);
extern void *solidify_debug_malloc(uint size, char *file, uint line);
extern void *solidify_debug_realloc(void *pointer, uint size, char *file, uint line);
extern void solidify_debug_free(void *pointer, char *file, uint line);

#define malloc(n) solidify_debug_malloc(n, __FILE__, __LINE__)
#define realloc(n, m) solidify_debug_realloc(n, m, __FILE__, __LINE__)
#define free(n) solidify_debug_free(n, __FILE__, __LINE__)
#endif

/* --- Constants --- */
#if !defined(SOLIDIFY_NO_CONSTANTS)
#define SOLIDIFY_NO_CONSTANTS
#define PI 3.1415926535
#define E  2.7182818284
#endif
