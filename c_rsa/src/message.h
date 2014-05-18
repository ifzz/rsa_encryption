/**
 * message
 * File: message.h
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 16 2014
 */
 
 #include <assert.h>
 #include <string.h>
 #include <stdio.h>
 #include "queue.h"

/* Message uses a linked list structure to store 
 * each ascii-ified element
 */
typedef queue message;

/* print message
 * returns a printable form of the message
 * This assumes that the message is printable
 * and human-readable.
 */
char* print_message(message* msg);

/* Message Encode
 * 
 * Converts a char* string to a message
 */
message* mencode(char* msg);

/* Message decode
 * 
 * Converts a message to a char*
 */
char* mdecode(message* msg);

/* Free Message
 * Frees the memory of a message
 */
void free_message(message* msg);
