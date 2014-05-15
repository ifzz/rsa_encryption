/**
 * stringx
 * File: stringx.h
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 15 2014
 */

#include <assert.h>
#include <string.h>
#include <stdlib.h>

/* integer to ascii
 * Converts an integer (positive or negative)
 * to ascii text in the form of a char*
 */
char* itoa(int n);

/* integer length
 * Gets the number of digits in an integer
 */
int intlen(int n);
