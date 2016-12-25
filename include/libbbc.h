/*  =========================================================================
    libbbc - public header

    Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
    =========================================================================
*/

#ifndef __LIBBBC_H_INCLUDED__
#define __LIBBBC_H_INCLUDED__

// External dependencies

// Standard ANSI include files. Not necessary if czmq.h is included.
#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <float.h>
#include <math.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if (defined (_MSC_VER))
#   if (!defined (__cplusplus) && (!defined (true)))
#       define true 1
#       define false 0
        typedef char bool;
#   endif
#else
#   include <stdbool.h>
#endif

// version macros for compile-time API detection
#define LIBBBC_VERSION_MAJOR 0
#define LIBBBC_VERSION_MINOR 1
#define LIBBBC_VERSION_PATCH 0

#define ER_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define LIBBBC_VERSION \
    LIBBBC_MAKE_VERSION(LIBBBC_VERSION_MAJOR, \
    LIBBBC_VERSION_MINOR, \
    LIBBBC_VERSION_PATCH)

// Common function types

typedef void (*destructor_t) (void **obj_p);
typedef int (*comparator_t) (const void *obj1, const void *obj2);
typedef bool (*matcher_t) (const void *obj1, const void *obj2);
typedef void *(*duplicator_t) (const void *obj);
typedef void (*copier_t) (void *dest, const void *src);
typedef void (*printer_t) (const void *obj);
typedef size_t (*hashfunc_t) (const void *obj);

// Public class structures

typedef struct _arrayset_t arrayset_t;
typedef struct _hash_t hash_t;
typedef struct _listu_t listu_t;
typedef struct _listx_t listx_t;
typedef struct _matrixd_t matrixd_t;
typedef struct _matrixu_t matrixu_t;
typedef struct _queue_t queue_t;
typedef struct _rng_t rng_t;
typedef struct _timer_t timer_t;

// Genome representation
typedef void *genome_t;

// Heuristic callback for generating genomes from context.
// Return a list of genome_t.
// This function is used to initialize population before evolution.
typedef listx_t *(*evol_heuristic_t) (void *context, size_t max_expected);

// Fitness assessment callback
typedef double (*evol_fitness_assessor_t) (void *context, genome_t genome);

// Feasibility assessment callback
typedef bool (*evol_feasiblity_assessor_t) (void *context, genome_t genome);

// Function of computing distance between individuals
typedef double (*evol_distance_assessor_t) (void *context,
                                            genome_t genome1,
                                            genome_t genome2);

// Crossover callback: generating child from parents
// Return a list of children's genomes
// Note that if you do not set genome duplicator for evol, leave the list's
// destructor as NULL, so that evol can use the genomes and freeing them after
// use.
typedef listx_t *(*evol_crossover_t) (void *context,
                                      genome_t parent1,
                                      genome_t parent2);

// Mutation callback
typedef genome_t (*evol_mutator_t) (void *context, genome_t genome);

// Local improving callback (genome is improved in place)
typedef void (*evol_educator_t) (void *context, genome_t genome);

// Callback to check whether renewer should be called to update the population.
// This is mostly due to variation of context
typedef bool (*evol_should_renew_t) (void *context);

// Genome renew callback (genome is updated in place)
// When context varies during evolution, you can use this callback to update
// current individuals accordingly.
// Return 0 if genome should be keeped (modified or tansformed into a new one.)
// Return -1 if genome should be dropped.
typedef int (*evol_renewer_t) (void *context, genome_t genome);

// Outside stopper callback
typedef bool (*evol_stopper_t) (void *context);

typedef struct _evol_t evol_t;

// Public API headers
#include "arrayi.h"
#include "arrayset.h"
#include "arrayu.h"
#include "date_ext.h"
#include "evol.h"
#include "hash.h"
#include "listu.h"
#include "listx.h"
#include "matrixd.h"
#include "matrixu.h"
#include "numeric_ext.h"
#include "queue.h"
#include "rng.h"
#include "string_ext.h"
#include "timer.h"
#include "util.h"

#endif
