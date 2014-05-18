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
LFLAGS = -lm

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

$(BUILD)queue.o: $(SRC)queue.c $(SRC)queue.h
	$(CC) $(CFLAGS) $(SRC)queue.c -o $(BUILD)queue.o

$(BUILD)message.o: $(SRC)message.c $(SRC)message.h $(BUILD)queue.o
	$(CC) $(CFLAGS) $(SRC)message.c -o $(BUILD)message.o

$(BUILD)stringx.o: $(SRC)stringx.c $(SRC)stringx.h
	$(CC) $(CFLAGS) $(SRC)stringx.c -o $(BUILD)stringx.o

$(BUILD)miller-rabin.o: $(SRC)miller-rabin.c $(SRC)miller-rabin.h
	$(CC) $(CFLAGS) $(SRC)miller-rabin.c -o $(BUILD)miller-rabin.o

$(BUILD)rand.o: $(SRC)rand.c $(SRC)rand.h $(BUILD)mathx.o
	$(CC) $(CFLAGS) $(SRC)rand.c -o $(BUILD)rand.o

$(BUILD)rsa.o: $(SRC)rsa.c $(SRC)rsa.h $(BUILD)miller-rabin.o $(BUILD)mathx.o $(BUILD)rand.o $(BUILD)stringx.o
	$(CC) $(CFLAGS) $(SRC)rsa.c -o $(BUILD)rsa.o

$(BUILD)main.o: $(SRC)main.c $(BUILD)rsa.o $(BUILD)message.o
	$(CC) $(CFLAGS) $(SRC)main.c -o $(BUILD)main.o

# Link Objects
$(BIN)rsa: $(BUILD)main.o
	$(CC) $(BUILD)queue.o $(BUILD)message.o $(BUILD)stringx.o $(BUILD)rand.o $(BUILD)miller-rabin.o $(BUILD)mathx.o $(BUILD)rsa.o $(BUILD)main.o -o $(BIN)rsa $(LFLAGS) 

