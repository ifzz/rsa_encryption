#include "integer.h"

#include <stdio.h>


inline int sign(int x) { return 2 * (x >= 0);}



int intsize(int n)
{
	int count;
	for (count = 0; n != 0; n /= 10, ++count){}
	return count;
}

/* size int
 * number of digits in an integer
 */
int integersize(integer* n)
{
	int count;
	digit* current_digit;
	for (count = 0, current_digit = n->_head; current_digit != NULL; count++, current_digit = current_digit->next){}
	return count;
}

/** Digit
  * Constructs a digit
  * The input digit d must be one digit
  * i.e between 0 and 9.
  */
digit* Digit(int d)
{
	assert((d >= 0) && (d <= 9)); // Otherwise this has multiple digits
	digit* retval = (digit*)malloc(sizeof(digit));
	retval->item = d;
	retval->next = NULL;
	retval->prev = NULL;
	return retval;
}

int get_digit(digit* d)
{
	return d->item;
}

/** Frees Digit
  * Frees a digit
  */
void free_Digit(digit* d)
{
	free(d);
}

/** Integer
  * Allocate an integer given a list of characters
  * 
  * Returns null if any char cannot be converted to an integer
  */
integer* Integer_char(char* n)
{
	int i;
	integer* number = (integer*)malloc(sizeof(integer));
	assert(number != NULL);
	for (i = 0; i < strlen(n); i++)
	{
		printf("%c\n", n[i]);
	}
	return NULL;
}

/** Integer
  * Allocate an integer given a long int
  */
integer* Integer_int(long int n);

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

int main(void)
{
	digit* my_digit = Digit(1);
	printf("my digit: %d\n", get_digit(my_digit));
	free_Digit(my_digit);

	Integer_char("123");

	printf("Size of 1234: %d\n", intsize(1234));
	return 0;
}