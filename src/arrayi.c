/*  =========================================================================
    arrayi - implementation

    Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
    =========================================================================
*/

#include "classes.h"


int *arrayi_new (int length) {
    int *array = (int *) malloc (sizeof (int) * length);
    assert (array);
    return array;
}


int *arrayi_new_shuffle_range (int a, int b, rng_t *rng) {
    assert (a < b);

    bool own_rng = false;
    if (rng == NULL) {
        rng = rng_new ();
        own_rng = true;
    }

    int *array = arrayi_new (b - a);
    arrayi_shuffle_range_to (array, a, b, rng);

    if (own_rng)
        rng_free (&rng);
    return array;
}


int *arrayi_dup (const int *array, size_t length) {
    assert (array);
    assert (length > 0);
    int *copy = (int *) malloc (sizeof (int) * length);
    assert (copy);
    memcpy (copy, array, sizeof (int) * length);
    return copy;
}


void arrayi_shuffle (int *array, size_t length, rng_t *rng) {
    assert (array);
    bool own_rng = false;
    if (rng == NULL) {
        rng = rng_new ();
        own_rng = true;
    }

    if (length <= 1)
        return;

    size_t i, j;
    int tmp;
    for (i = 0; i < length - 1; i++) {
        j = (size_t) rng_random_int (rng, i, length); // [0, length-1]
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }

    if (own_rng)
        rng_free (&rng);
}


int *arrayi_dup_shuffle (const int *array, size_t length, rng_t *rng) {
    assert (array);
    bool own_rng = false;
    if (rng == NULL) {
        rng = rng_new ();
        own_rng = true;
    }

    int *copy = arrayi_dup (array, length);
    arrayi_shuffle (copy, length, rng);

    if (own_rng)
        rng_free (&rng);
    return copy;
}


void arrayi_shuffle_to (int *dest, const int *src, size_t length, rng_t *rng) {
    assert (src);
    assert (dest);
    bool own_rng = false;
    if (rng == NULL) {
        rng = rng_new ();
        own_rng = true;
    }

    size_t i, j;
    for (i = 0; i < length - 1; i++) {
        j = (size_t) rng_random_int (rng, 0, i+1); // [0, i]
        if (j != i) dest[i] = dest[j];
        dest[j] = src[i];
    }

    if (own_rng)
        rng_free (&rng);
}


void arrayi_shuffle_range_to (int *array, int a, int b, rng_t *rng) {
    assert (array);
    assert (a < b);
    bool own_rng = false;
    if (rng == NULL) {
        rng = rng_new ();
        own_rng = true;
    }

    size_t i, j;
    for (i = 0; i < b - a; i++) {
        j = (size_t) rng_random_int (rng, 0, i + 1); // [0, i]
        if (j != i) array[i] = array[j];
        array[j] = a + i;
    }

    if (own_rng)
        rng_free (&rng);
}

