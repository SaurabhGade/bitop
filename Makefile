CC=gcc
PDIR=$(shell pwd)
SRC_DIR=$(PDIR)/src
BUILD_DIR=$(PDIR)/build
BIN_DIR=$(PDIR)/bin
INCLUDE_DIR=$(PDIR)/include

CFLAGS=-g -Wall -Werror -Wextra -I$(INCLUDE_DIR) 

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(addprefix $(BUILD_DIR)/, $(notdir $(SRC_FILES:.c=.o)));

test: $(OBJ_FILES)
	$(CC) $(CFLAGS) $(BUILD_DIR)/*.o -o $(BIN_DIR)/test -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/bitop.h
	$(CC) $(CFLAGS) -c $< -o $@ -lm

run:
	$(BIN_DIR)/test


.PHONY: clean			#To tell file make clean is not a file but a command that should always run regrdless of wheter a file with that naem exist.
	
clean:
	rm -f $(BUILD_DIR)/*.o 
