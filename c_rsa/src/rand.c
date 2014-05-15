#include "rand.h"

/**
 * rand
 * File: rand.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 07 2014
 */


/* Rand Range
 * Gives a random number within a range
 */
unsigned int rand_range(unsigned int min, unsigned int max)
{
	double scaled = (double)rand()/RAND_MAX;
	unsigned int v = (max - min +1)*scaled + min;
	if (v < 0)
		v = v * -1;
	return v;
}


/*	-- Stack overflows when the else is executed since it must run for one second. 
 	-- Sleep for 1 second would work, but dramatically decrease performance
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
	} */


/* Random Prime
 * Returns a random prime number bounded by n and 0
 */
unsigned int rand_prime(unsigned int n)
{
	int p = 1;
	while (!is_prime(p, 30)) p = rand_range(1, n);
	return p;
}


