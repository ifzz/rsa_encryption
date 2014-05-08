
OUTPUT = integer

CC = gcc
CFLAGS = -c -g

all: integer

clean:
	rm $(OUTPUT)
	rm $(OUTPUT).o


integer.o: integer.c integer.h
	$(CC) $(CFLAGS) integer.c -o integer.o

integer: integer.o
	$(CC) integer.o -o integer

