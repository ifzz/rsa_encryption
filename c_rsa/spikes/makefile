
OUTPUT = integer

CC = gcc
CFLAGS = -c -g

all: integer

clean:
	rm $(OUTPUT).o
	rm $(OUTPUT)



integer.o: integer.c integer.h
	$(CC) $(CFLAGS) -lm integer.c -o integer.o

integer: integer.o
	$(CC) -lm integer.o -o integer

