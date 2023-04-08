#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

char* jts_strrev(const char *restrict);
/* The returned string must me freed by the user
 *
 */

bool jts_ispalendrome(const char *restrict);
/* Returns true if the string argument is a palendrome.
 * Returns false otherwise.
 */

intmax_t jts_numinstances(const char *restrict, const char);
/* return number of instances of a char in a string
 * Returns -1 on error
 */

char **jts_copy_argv(int argc, char **argv);
/* Return dynamically allocated array of strings containing a copy argv.
 * User must free() the strings and the array itself.
 */
