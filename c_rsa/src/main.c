/**
 * main
 * File: main.c
 * Auth: Evan Wilde 				<etcwilde@uvic.ca>
 * Date: May 05 2014
 */
#include "rsa.h"
#include "message.h"
//#include "user.h" // For now just pass in through argv

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





int main(int argc, char const *argv[])
{
	int i;
	srand(time(NULL));

	// printf("argc: %d\n", argc);
	// if (argc != 2)
	// 	fprintf(stderr, "Useage:\n-k: Generate keys\n-e [public key] [message]: Encrypt message with public key\n-d [private key] [message]: decrypt message with private key");



	keypair* keys = keygen(pow(2, 15));
	printf("Public key: %s\nPrivate key: %s\n", key_to_char(keys->public_key), key_to_char(keys->private_key));

	char* menc = encode("Hello World", keys->public_key); 




	// message* new_message = mencode("Hello World");
	// char* my_message = mdecode(new_message);
	// printf(">>> %s\n", my_message );



	// char** val = (char**)queue_list(another_message);
	// // char* something = (char*)malloc(sizeof(char) * 1);
	// long int j = another_message->size;
	// while (j >= 0)
	// {
	// 	printf("%c", *val[j]);
	// 	j--;
	// }
	// printf("\n");

	// printf(">> Word: %s\n", mdecode(another_message));



	// printf("Encoded, then decoded message:\n%s\n", mdecode(mencode("This is a message")));
	return 0;
}
