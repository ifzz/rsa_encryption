#include <assert.h>
/**
 * mathx
 * File: mathx.h
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 07 2014
 *
 * Extended math functionality
 */

/* Power
 * 
 * b ** e
 *
 * b is the base
 * e is the exponent
 */
int power(int b, int e);

/* power_mod
 *
 * (b ** e) % m
 *
 * b is the base
 * e is the exponent
 * m is the modulus
 */
int pow_mod(int b, int e, int m);

/* Is prime
 * 
 * Determines if an integer n is prime
 * Iterates k times
 */
char is_prime(long int n, int k);

/* Multiplicative Inverse
 * Calculates the multiplicative inverse
 */
long int multinv(long int modulus, long int value);

/* Greatest Common Denominator
 *
 * GCD calculator
 */
long int gcd(long int a, long int b);
