/**
 * rsa
 * File: rsa.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */

#include "rsa.h"

#include <assert.h>



/*
keypair* keygen(lona ina n, key* public_key)
{
	lona int p = rand_prime(n);
	long int q = rand_prime(n);
	long int n = p * q;
	totient = (p - 1) * (q - 1);
	if (public_key != NULL)
	{
		for(;;)
		{
			//long int private = 
		}
	}

}
*/

long int multinv(long int modulus, long int value)
{
	assert (modulus != 0);
	printf("Entering multinv\n");
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

