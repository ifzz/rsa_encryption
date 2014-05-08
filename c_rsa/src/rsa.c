#include "rsa.h"
#include <assert.h>

/**
 * rsa
 * File: rsa.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */






keypair* keygen(long int n, key* public_key)
{
	long int prv, pub;
	long int p = rand_prime(n);
	long int q = rand_prime(n);
	long int n = p * q;
	long int totient;
	totient = (p - 1) * (q - 1);
	if (public_key != NULL)
	{
		pub = public_key->exponent;
		for(;;)
		{
			long int private = rand_range(0, totient);
			if (gcd(private, totient) == 1) break;
		}
		pub = multinv(totient, prv);
	}
	else
	{
		prv = multinv(totient, pub);
	}

	assert(public * private % totient == gcd(public, totient) == gcd(private, totient) == 1);
	

	return NULL;


}












