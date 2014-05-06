#
# rsa encryption makefile
#

#
# 3 main programs:
# 	keygen
# 	encrypt
# 	decrypt
#

# Directories
BIN = bin/
BUILD = build/
SRC = src/

CFLAGS = -g -c

# Commands
MK = mkdir -p
CP = cp
RM = rm -rf
CC = gcc 

#Phony Targets
.PHONY: all rebuild clean

all: $(BIN)rsa

clean:
	$(RM) $(BIN)*
	$(RM) $(BUILD)*

rebuild: clean all

# build Objects
$(BUILD)rsa.o: $(SRC)rsa.c $(SRC)rsa.h
	$(CC) $(CFLAGS) $(SRC)rsa.c -o $(BUILD)rsa.o


$(BUILD)main.o: $(SRC)main.c
	$(CC) $(CFLAGS) $(SRC)main.c -o $(BUILD)main.o

# Link Objects
$(BIN)rsa: $(BUILD)main.o $(BUILD)rsa.o
	$(CC) $(BUILD)rsa.o $(BUILD)main.o -o $(BIN)rsa
