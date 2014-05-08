/**
 * main
 * File: main.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */
#include <stdio.h>
#include <time.h>
#include "rsa.h"
#include <stdlib.h>
#include "mathx.h"


int main()
{
	int i;
	srand(time(NULL));

	// for ( i = 0; i < 30; i++) printf("[%d]: %d\n", i, rand_range(0, 100));

	// printf("Random Numbers: \n");
	// for ( i = 0; i <100; i++) printf("[%d]: %ld\n", i,rand_prime(power(10, 8)));
	
	keypair* keys = keygen(power(2, 15));

	printf("Public Key: %d\nPrivate Key: %d\nModulus: %d\n", keys->public_key->exponent, keys->private_key->exponent, keys->public_key->modulus);


	return 0;
}
