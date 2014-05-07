/**
 * mathx
 * File: mathx.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 07 2014
 */


#include "mathx.h"

/* Power
 * 
 * b ** e
 *
 * b is the base
 * e is the exponent
 */
int power(int b, int e)
{
	int result = 1;
	for (; e > 0; e--)
	{
		result *= b;
	}
	return result;
}

/* power_mod
 *
 * (b ** e) % m
 *
 * b is the base
 * e is the exponent
 * m is the modulus
 */
int pow_mod(int b, int e, int m)
{
	assert(m != 0);
	return power(b, e) % m;
}

/* Is prime
 * 
 * Determines if an integer n is prime
 * Iterates k times
 */
char is_prime(long int n, int k)
{
	if (k <= 0)
	{
		k = 30;
	}
	return miller(n, k);
}	

/* Multiplicative Inverse
 * Calculates the multiplicative inverse
 */
long int multinv(long int modulus, long int value)
{
	assert (modulus != 0);
	long int x = 0;
	long int a = modulus;
	long int b = value;
	long int last_x = 1; 
	long int q;
	long int tmp_x;
	long int tmp_lx;

	long int tmp_a, tmp_b, tmp_q;



	while (b != 0)
	{
		tmp_a = b;
		tmp_b = a % b;
		tmp_q = a / b;

		a = tmp_a;
		b = tmp_b;
		q = tmp_q;

		tmp_lx = x;
		tmp_x =	last_x - q * x;

		x = tmp_x;
		last_x = tmp_lx;

	}
	long int result = (1 - last_x * modulus) / value;
	if (result < 0) result += modulus;
	
	assert(0 <= result < modulus && value * result % modulus == 1);
	return result;
}