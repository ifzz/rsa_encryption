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

test: $(BIN)miller

clean:
	$(RM) $(BIN)*
	$(RM) $(BUILD)*

rebuild: clean all

# Build Objects

$(BUILD)mathx.o: $(SRC)mathx.c $(SRC)mathx.h
	$(CC) $(CFLAGS) $(SRC)mathx.c -o $(BUILD)mathx.o

$(BUILD)miller-rabin.o: $(SRC)miller-rabin.c $(SRC)miller-rabin.h
	$(CC) $(CFLAGS) $(SRC)miller-rabin.c -o $(BUILD)miller-rabin.o

$(BUILD)rand.o: $(SRC)rand.c $(SRC)rand.h 
	$(CC) $(CFLAGS) $(SRC)rand.c -o $(BUILD)rand.o

$(BUILD)rsa.o: $(SRC)rsa.c $(SRC)rsa.h $(BUILD)miller-rabin.o $(BUILD)mathx.o $(BUILD)rand.o
	$(CC) $(CFLAGS) $(SRC)rsa.c -o $(BUILD)rsa.o

$(BUILD)main.o: $(SRC)main.c
	$(CC) $(CFLAGS) $(SRC)main.c -o $(BUILD)main.o

# Link Objects
$(BIN)rsa: $(BUILD)main.o $(BUILD)rsa.o $(BUILD)miller-rabin.o $(BUILD)mathx.o
	$(CC) $(BUILD)rand.o $(BUILD)miller-rabin.o $(BUILD)mathx.o $(BUILD)rsa.o $(BUILD)main.o -o $(BIN)rsa

