/*  =========================================================================
    arrayi - array of int type values

    Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
    =========================================================================
*/

#ifndef __ARRAYI_H_INCLUDED__
#define __ARRAYI_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

// Create array with given length
int *arrayi_new (int length);

// Create array of random permutation of integers in [a, b).
// rng could be NULL.
int *arrayi_new_shuffle_range (int a, int b, rng_t *rng);

// Duplicator
int *arrayi_dup (const int *array, size_t length);

// Shuffle the n elements of array in place.
// rng could be NULL.
void arrayi_shuffle (int *array, size_t length, rng_t *rng);

// Get a shuffled copy of the n elements of array.
// rng could be NULL.
int *arrayi_dup_shuffle (const int *array, size_t length, rng_t *rng);

// Get a shuffled copy of the n elements of array.
// Return result in param dest.
// rng could be NULL.
void arrayi_shuffle_to (int *dest, const int *src, size_t length, rng_t *rng);

// Generate random permutation of integers in [a, b).
// Return result in param array.
// rng could be NULL.
void arrayi_shuffle_range_to (int *array, int a, int b, rng_t *rng);

#ifdef __cplusplus
}
#endif

#endif
