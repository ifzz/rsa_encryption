#include "rand.h"

/**
 * rand
 * File: rand.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 07 2014
 */


/* Rand Range
 * Gives a rancom number within a range
 */
unsigned int rand_range(unsigned int start, unsigned int end)
{
	int base_random = rand();
	if (RAND_MAX == base_random) return rand_range(start, end);
	int range = end - start,
	    remainder = RAND_MAX % range,
	    bucket = RAND_MAX / range;
	if (base_random < RAND_MAX - remainder)
	{
		return start + base_random/bucket;
	}
	else
	{
		return rand_range(start, end);
	}
}

/* Random Prime
 * Returns a random prime number bounded by n and 0
 */
unsigned int rand_prime(unsigned int n)
{
	int p = 1;
	while (!is_prime(p, 30)) p = rand_range(1, n);
	return p;
}
