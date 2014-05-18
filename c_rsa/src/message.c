/**
 * message
 * File: message.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 16 2014
 */
 
 #include "message.h"

/* Message uses a linked list structure to store 
 * each ascii-ified element
 */
typedef queue message;

/* print message
 * returns a printable form of the message
 * This assumes that the message is printable
 * and human-readable.
 */
// char* print_message(message* msg)
// {
// 	char* charmsg = (char*)malloc(sizeof(char) * msg->size + 1);
// 	assert(charmsg != NULL);

// }


/* Message Encode
 * 
 * Converts a char* string to a message
 */
message* mencode(char* msg)
{
	assert(msg != NULL);
	char* j;
	int i;
	long int len = strlen(msg);

	message* new_msg = (message*)queue_init();

	for (j = msg, i = 0; i < len; i++, j++)
	{
		queue_push(new_msg, j);
	}
	return new_msg;
}

/* Message decode
 * 
 * Converts a message to a char*
 * The message structure is freed
 */
char* mdecode(message* msg)
{
	assert(msg != NULL);
	char *new_msg, *pos;
	int i;
	new_msg = (char*)malloc(sizeof(char) * msg->size + 1);
	assert(new_msg != NULL);
	size_t len = msg->size;
	for (i = 0, pos = new_msg; pos - new_msg < len; i++)
	{
		*pos = *(char*)queue_pop(msg);
		pos++;	
	}
	*pos = '\0';
	queue_free(msg);
	return new_msg;
}
