#include "rsa.h"
#include <assert.h>

/**
 * rsa
 * File: rsa.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */

char* key_to_char(key* k)
{
	int modlen = intlen(k->modulus);
	int explen = intlen(k->exponent);
	char* result = (char*)malloc(sizeof(char) * modlen * explen + 1);
	assert(result != NULL);
	result = strcat(result, itoa(k->exponent));
	result = strcat(result, ":");
	result = strcat(result, itoa(k->modulus));
	return result;
}

keypair* keygen(long int N)
{
	long int prv, pub;
	long int p = rand_prime(N), q = rand_prime(N);
	long int n = p * q, totient = (p - 1) * (q - 1);
	for(;;)
	{
		prv = rand_range(0, totient);
		if (gcd(prv, totient) == 1) break;
	}
	pub = multinv(totient, prv);
	assert(pub * prv % totient == gcd(pub, totient) == gcd(prv, totient) == 1);
	keypair* keys = (keypair*)malloc(sizeof(keypair));
	key* public = (key*)malloc(sizeof(key));
	key* private = (key*)malloc(sizeof(key));
	assert ((public != NULL) && (private != NULL) && (keys != NULL));
	keys->public_key = public, keys->private_key = private;
	public->modulus = private->modulus = n;
	public->exponent = pub, private->exponent = prv;
	return keys;
}

/** Encode
  * Encodes a message using a public key to be
  * sent to the holder of the private key
  */
char* encode(char* msg, key* public_key)
{
	assert(msg != NULL);
	assert(public_key != NULL);
	queue* encrypted_msg = (queue*)malloc(sizeof(queue));
	assert(encrypted_msg != NULL);

	/* For each character k *= character, k %= modulo */
	/* Then place in a char* buffer */

	return "Hello";
}

/** Decode
  * Decodes a message sent by alice using the private key
  */
char* decode(char* btsting, key* private_key)
{
	assert(btsting != NULL);
	assert(private_key != NULL);
	return "World";
}
