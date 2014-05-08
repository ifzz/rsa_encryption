#include "rsa.h"
#include <assert.h>

/**
 * rsa
 * File: rsa.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */




keypair* keygen(long int N)
{
	long int prv, pub;
	long int p = rand_prime(N);
	long int q = rand_prime(N);
	long int n = p * q;
	long int totient;
	totient = (p - 1) * (q - 1);

	for(;;)
	{
		prv = rand_range(0, totient);
		if (gcd(prv, totient) == 1) break;
	}

	printf("Private Key: %ld\n", prv);

	pub = multinv(totient, prv);
	assert(pub * prv % totient == gcd(pub, totient) == gcd(prv, totient) == 1);

	keypair* keys = (keypair*)malloc(sizeof(keypair));
	key* public = (key*)malloc(sizeof(key));
	key* private = (key*)malloc(sizeof(key));
	assert ((public != NULL) && (private != NULL) && (keys != NULL));

	keys->public_key = public;
	keys->private_key = private;

	public->modulus = private->modulus = n;
	public->exponent = pub;
	private->exponent = prv;
	return keys;
}







