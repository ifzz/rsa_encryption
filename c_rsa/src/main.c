/**
 * main
 * File: main.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */
#include "rsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	int i;
	srand(time(NULL));

	keypair* keys = keygen(pow(2, 15));
	printf("Public key: %s\tPrivate key: %s\n", key_to_char(keys->public_key), key_to_char(keys->private_key));

	return 0;
}
