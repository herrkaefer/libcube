/*  =========================================================================
    evol - evolution algorithm framework

    Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
    =========================================================================
*/

#ifndef __EVOL_H_INCLUDED__
#define __EVOL_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

// Create evolution object.
// Set the context to which genome operations are refered (e.g. a model)
evol_t *evol_new (void *context);

// Destroy evolution object
void evol_free (evol_t **self_p);

// Set livings group size
// If this is not set, default value is used.
void evol_set_livings_group_size (evol_t *self, size_t max_livings);

// Set ancestors group size
// If this is not set, default value is used.
void evol_set_ancestors_group_size (evol_t *self, size_t max_ancestors);

// Set children group size
// If this is not set, default value is used.
void evol_set_children_group_size (evol_t *self, size_t max_children);

// Set genome free function
void evol_set_genome_destructor (evol_t *self, destructor_t fn);

// Set genome duplicate function
// If genome duplicator is set, genome destructor should be set as well.
void evol_set_genome_duplicator (evol_t *self, duplicator_t fn);

// Set genome print function
void evol_set_genome_printer (evol_t *self, printer_t fn);

// Set genome feasiblity assessment function
void evol_set_feasibility_assessor (evol_t *self,
                                    evol_feasiblity_assessor_t fn);

// Set genome fitness assessment function
void evol_set_fitness_assessor (evol_t *self, evol_fitness_assessor_t fn);

// Set genome distance computing function
void evol_set_distance_assessor (evol_t *self, evol_distance_assessor_t fn);

// Set should_renew callback and genome renewer callback
void evol_set_renewer (evol_t *self, evol_should_renew_t fn, evol_renewer_t gn);

// Set outside stopper callback
void evol_set_stopper (evol_t *self, evol_stopper_t fn);

// Register heuristic function.
// Call this multiple times to add multiple heuristics.
// is_random: if the function generates random genomes with different calling.
// max_num_expected: max number of genomes expected to get for every calling.
void evol_register_heuristic (evol_t *self,
                              evol_heuristic_t fn,
                              bool is_random,
                              size_t max_expected);

// Register crossover function
void evol_register_crossover (evol_t *self, evol_crossover_t fn);

// Set genome mutation function
void evol_register_mutator (evol_t *self, evol_mutator_t fn);

// Set genome local search function
void evol_register_educator (evol_t *self, evol_educator_t fn);

// Run evolution
void evol_run (evol_t *self);

// Get genome with best fitness
const genome_t evol_best_genome (evol_t *self);

void evol_test (bool verbose);

#ifdef __cplusplus
}
#endif

#endif
