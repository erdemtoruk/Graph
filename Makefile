CC=g++

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
BIN_NAME = main

OBJ_DIR = $(BIN_DIR)/obj

CFLAGS=-I$(INC_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BIN  = $(BIN_DIR)/$(BIN_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -g -c $< -o $@ $(CFLAGS)

build: $(OBJS)
	$(CC) -g -o $(BIN) $^ $(CFLAGS)

clean:
	rm -Rf $(OBJ_DIR)/*
	find $(BIN_DIR) -maxdepth 1 -type f -delete

run: build
	$(BIN_DIR)/$(BIN_NAME)

valgrind: clean build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt $(BIN_DIR)/$(BIN_NAME)

.PHONY: all tests clean run valgrind