#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
/**
 * integer
 * File: integer.h
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 07 2014
 * 
 * Size-independent version of an integer
 */

typedef struct _digit
{
	short item;
	struct _digit* next;
	struct _digit* prev;

} digit;

/* An integer is a list of digits  */
typedef struct _integer 
{
	char neg;
	digit* _head;
	digit* _tail;
} integer;

/* size int
 * number of digits in an integer
 */
int sizeint(integer* n);

/** Digit
  * Constructs a digit
  */
digit* Digit(short d);

/** Frees Digit
  * Frees a digit
  */
void free_Digit(digit* d);

/** Integer
  * Allocate an integer given a list of characters
  * 
  * Returns null if any char cannot be converted to an integer
  */
integer* Integer_char(char* n);

/** Integer
  * Allocate an integer given a long int
  */
integer* Integer_int(long int n);

/** integer append
  * Appends a digit to an integer
  */
integer* Integer_append(integer* i, digit* d);

/** Add
  * Adds two integers together
  * x = a + b
  */
integer* add(integer* a, integer* b);

/** Subtract
  * Subtracts b from a
  * x = a - b
  */
integer* subtract(integer* a, integer* b);

/** Divide
  * Integer Divides two integers
  * x = a / b
  */
integer* divide(integer* a, integer* b);

/** multiply
  * Multiplies two integers together
  * x = a * b
  */
integer* multiply(integer* a, integer* b);

/** Operator
  * Performs an operation on each digit
  */
integer* operator(integer* a, integer* b, integer* operation);


/** Free Integer
  * Frees all digits and then the integer
  */
void free_Integer(integer* i);
