/*  =========================================================================
    string_ext - extension of string type

    Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
    =========================================================================
*/

#ifndef __STRING_EXT_H_INCLUDED__
#define __STRING_EXT_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#define streq(s1,s2)    (!strcmp ((s1), (s2)))
#define strneq(s1,s2)   (strcmp ((s1), (s2)))

#define UUID_STR_LEN 32

// Hash function
size_t string_hash (const char *string);

// Comparator
int string_compare (const char *str1, const char *str2);

// Matcher
bool string_equal (const char *str1, const char *str2);

// Destructor
void string_free (char **string_p);

// Duplicator
char *string_duplicate (const char *string);

// Printer
void string_print (const char *string);

// Generate a random string consisting of alpha-numeric characters with
// specific length range.
// Provide your rng or set it to NULL to use a inner one.
char *string_new_random_alphanum (size_t min_length, size_t max_length, rng_t *rng);

// String Levenshtein distance.
// Modified from:
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
size_t string_levenshtein_distance (const char *str1, const char *str2);

// String cut and splice crossover
// str1:   +++++++|++++++++++++
// str2:   **********|*************
// ======>
// child1: +++++++|*************
// child2: **********|++++++++++++
listx_t *string_cut_and_splice (const char *str1, const char *str2, rng_t *rng);

#ifdef __cplusplus
}
#endif

#endif
