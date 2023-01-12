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
/* It's sometimes useful...
 *
 */

intmax_t jts_numinstances(const char *restrict, const char);
/* return number of instances of a char in a string
 * Returns -1 on error
 */
