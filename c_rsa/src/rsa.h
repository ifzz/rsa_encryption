#include <stdio.h>

#include "message.h"
#include "miller-rabin.h"
#include "rand.h"
#include "stringx.h"
/**
 * rsa
 * File: rsa.h
 * Auth: Evan Wilde         <etcwilde@uvic.ca>
 * Date: May 05 2014
 */

/* key
 */

typedef struct _key {
	int exponent;
	int modulus;
} key;

typedef struct _keypair{
	key* public_key;
	key* private_key;
} keypair;


/* Key To Char
 * Converts a key to a human-readable 
 * format.
 */
char* key_to_char(key* k);

/* Keygen
 * 
 * Generates a keypair
 *
 * n is the upper bound on the size of the prime numbers used
 * If public is not null, it will only generate the private key
 * Otherwise, it will generate a public key
 */
keypair* keygen(long int N);

/** is prime
  * Returns 0 when the number is not prime
  * Returns 1 when the number is prime
  * 
  * Uses the Miller-Rabin primality test -- NO
  * Usues the Fermat Primality test
  * If k = 0, then will run for 30 times
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
// long int rand_prime(long int n);

long int multinv(long int modulus, long int value);

/**  Encode
  * Encodes a message using the public key to be sent to alice
  */
char* encode(char* msg, key* public_key);

/** Decode
  * Decodes a message sent by alice using the private key
  */
char* decode(char* btsting, key* private_key);
