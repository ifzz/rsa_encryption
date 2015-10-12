/**
 * mathx
 * File: mathx.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 07 2014
 */

#include "mathx.h"

/* power_mod
 *
 * (b ** e) % m
 *
 * b is the base
 * e is the exponent
 * m is the modulus
 */
unsigned int pow_mod(unsigned int b, unsigned int e, unsigned int m)
{
	b %= m;
	unsigned int result = 1;
	while (e > 0)
	{
		if (e & 1) result = (result * b) %m;
		b = (b * b) % m;
		e >>= 1;
	}
	return result;
}

/* Is prime
 * 
 * Determines if an integer n is prime
 * Iterates k times
 */
char is_prime(long int n, int k)
{
	if (k <= 0)	k = 30;
	return miller(n, k);
}	

/* Multiplicative Inverse
 * Calculates the multiplicative inverse
 */
long int multinv(long int modulus, long int value)
{
	assert (modulus != 0);
	long int x = 0, a = modulus, b = value;
	long int last_x = 1, q, tmp_x, tmp_lx;
	long int tmp_a, tmp_b, tmp_q;
	while (b != 0)
	{
		// Create New Values
		tmp_a = b; tmp_b = a % b; tmp_q = a / b;
		// Update Values
		a = tmp_a; b = tmp_b; q = tmp_q;
		//Create New Values
		tmp_lx = x; tmp_x =	last_x - q * x;
		//Update Values
		x = tmp_x; last_x = tmp_lx;
	}
	long int result = (1 - last_x * modulus) / value;
	if (result < 0) result += modulus;
	assert(0 <= result < modulus && value * result % modulus == 1); 
	return result;
}

/* Greatest Common Denominator
 *
 * GCD calculator
 */
long int gcd(long int a, long int b)
{
	int c;
	while (a != 0)
	{
		c = a; a = b % a; b = c;
	}
	return b;
}

/* log with base
 * 
 * Calculates the log of a number
 * given a base
 */
// double logb(double x, double b)
// {
// 	return log(x) / log(b);
// }
