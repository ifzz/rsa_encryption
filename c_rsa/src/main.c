/**
 * main
 * File: main.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */
#include <stdio.h>
#include <time.h>
#include "rsa.h"
#include "rand.h"


int main()
{
	int i;
	int j;
	for(i = 0; i < 100 + 1; i++) j = printf("[%d]: prime: %d\n", i, is_prime(i, 0));
	return 0;
}
