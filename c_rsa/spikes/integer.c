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
digit* Digit(short d)
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

void print_int(integer* n)
{
	digit* d;

	for(d = n->_head; d != NULL; d = d->next)
	{
		printf("%d", get_digit(d));
	}
}

/** Integer
  * Allocate an integer given a list of characters
  * 
  * Returns null if any char cannot be converted to an integer
  * Nice thing about being able to enter a number as a char*:
  * we can enter infinitly long numbers into our integer.
  */
integer* Integer_char(char* n)
{
	char character;
	char* current_char;
	long int val;
	char* endptr;
	
	integer* result = (integer*)malloc(sizeof(integer));
	assert(result != NULL);
	
	for (current_char = n; *current_char != '\0'; current_char++)
	{
		character = *current_char;
		printf("char : %c\n", character);
		errno = 0;
		val = strtol(&character, &endptr, 10);
		if (errno != 0)
		{
			perror("Integer Char");
			free(result);
			return NULL;
		}
		if (endptr == &character)
		{
			fprintf(stderr, "Not a digit: %c\n", character);
			free(result);
			return NULL;
		}
		digit* new_d =  Digit((short) val);
		printf("Value as a digit: %d\n",get_digit(new_d));
		result = Integer_append(result, new_d);	
	}
	print_int(result);
	printf("\n");
	return result;
}

/** Integer Append
  * Append a digit to the tail of an integer 
  */
integer* Integer_append(integer* i, digit* d)
{
	if (i->_head != NULL)
	{
		i->_tail->next = d;
		d->prev = i->_tail;
		d->next = NULL;
		i->_tail = d;
	}
	else
	{
		i->_head = d;
		i->_tail = d;
	}
	return i;
}

char* Integer_to_char(integer* n)
{
	return NULL;
}

/** Integer
  * Allocate an integer given a long int
  */
integer* Integer_int(long int n)
{
	/*integer* my_int = (integer*)malloc(sizeof(integer));
	assert(my_int != NULL);
	my_int->_head = NULL; // Change if we initalize this anywhere
	my_int->_tail = NULL; // Change if we initialize this anywhere
	my_int->neg = 0; // Ignore negative numbers for now
	*/
	return NULL;
}
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
  * Performs an operation on each digit -- Need?
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

	Integer_char("9999999999999999999999899999901");

	printf("Size of 1234: %d\n", intsize(1234));
	return 0;
}
