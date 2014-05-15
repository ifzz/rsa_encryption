/**
 * stringx
 * File: stringx.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 15 2014
 */



 #include "stringx.h"

/* integer to ascii
 * Converts an integer (positive or negative)
 * to ascii text in the form of a char*
 */
char* itoa(int n)
{
	int length = intlen(n), i;
	char* str = (char*)malloc(sizeof(char) * length + 1), *j, neg = 0;
	assert(str != NULL);
	memset(str, 0, sizeof(str));
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	for (i = n, j = str + length - 1, *(j + 1) = '\0'; i != 0; j--, i /= 10) *j = (i % 10) + 48;
	if (neg) *j = '-';
	return str;
}

/* integer length
 * Gets the number of digits in an integer
 */
int intlen(int n)
{
	if (n < 0) return intlen(-n) + 1;
	int count;
	count = 0;
	for (; n != 0; n /= 10, count++){}
	return count;
}