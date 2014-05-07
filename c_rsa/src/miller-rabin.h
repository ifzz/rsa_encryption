#include <stdlib.h>

/**
 * miller-rabin
 * File: miller-rabin.h
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 06 2014
 */

/*mulmod
 *
 * Multiplies with a modulus
 */
long long mulmod(long long a, long long b, long long c);

/*modulo
  *
  */
long long modulo(long long a, long long b, long long c);
/* uses the miller-rabin algorithm to determine if 
 * a number is prime
 */
int miller (long long n, int a);

