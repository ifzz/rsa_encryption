/**
 * main
 * File: main.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */
#include<stdio.h>
#include"rsa.h"

int main()
{
	int mod, val;
	printf("Modulus: ");
	scanf("%d", &mod);
	printf("Value: ");
	scanf("%d", &val);

	printf("Multinv: %ld\n", multinv(mod, val));
	return 0;
}
