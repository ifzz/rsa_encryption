
/**
 * rsa
 * File: rsa.h
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */

#include <stdio.h>

/* key
 */

typedef struct _key {
	char* exponent;
	char* modulus;
} key;

typedef struct _keypair{
	key* public_key;
	key* private_key;
} keypair;

/* Keygen
 * 
 * Generates a keypair
 *
 * n is the upper bound on the size of the prime numbers used
 * If public is not null, it will only generate the private key
 * Otherwise, it will generate a public key
 */
keypair* keygen(long int n, key* public_key);

/** is prime
  * Returns 0 when the number is not prime
  * Returns 1 when the number is prime
  * 
  * Uses the Miller-Rabin primality test
  *
  * k is the accuracy
  * n is the number
  */
char is_prime(long int n, int k);


/** random prime
  * 
  * selects a random prime number
  * 
  * n is the upper bound 
  */
long int rand_prime(long int n);

long int multinv(long int modulus, long int value);

/**  Encode
  * Encodes a message using the public key to be sent to alice
  */
char* encode(char* msg, char* public_key);

/** Decode
  * Decodes a message sent by alice using the private key
  */
char* decode(char* btsting, char* private_key);