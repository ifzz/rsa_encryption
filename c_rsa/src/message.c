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
char* print_message(message* msg)
{
	if (msg == NULL)
	{
		fprintf(stderr, "Warning: No message provided\n");
		return NULL;
	}
	// long int j = msg->size;
	long int j = 0;
	char** chars = (char**)queue_list(msg);
	char* word = (char*)malloc(sizeof(char) * j + 1);
	assert(chars != NULL);
	assert(word != NULL);
	char* pos = word;
	while (j < msg->size)
	{
		*pos = *chars[j];
		pos++, j++;
	}
	*pos = '\0';
	return word;
}


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
	char* word = print_message(msg);
	queue_free(msg);
	return word;
}
