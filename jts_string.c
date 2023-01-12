#include "jts_string.h"

char* jts_strrev(const char *restrict s)
{
	const size_t length = strlen(s);

//	The caller must free me.
	char *r = calloc(1, length + 1);

	r[length] = '\0';

	if (r == NULL) goto tag_return;

	size_t c = 0;

	for (size_t i = length; i >= 0; i--) {

		if (s[i] == '\0') continue;

		r[c] = s[i];

		c++;

		if (i == 0) break;
	}

	tag_return:

	return r;
}

bool jts_ispalendrome(const char *restrict s)
{
	bool ispalendrome = false;

	char *r = jts_strrev(s);

	if (s == NULL || r == NULL) {

		goto tag_return;
	}

	if (strcmp(s, r) == 0) {

		ispalendrome = true;
	}

	tag_return:

	free(r);

	return ispalendrome;
}

intmax_t jts_numinstances(const char *restrict s, const char c)
{
	intmax_t instances = 0;

	if (s == NULL) {

		instances = -1;

		goto err;
	}

	size_t length = strlen(s);

	for (size_t i = 0; i < length; i++) {

		if (s[i] == c) {

			instances++;
		}
	}

	err:

	return instances;
}
