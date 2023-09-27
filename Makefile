# Makefile by SandWood Jones

PROJECT_NAME := BIN_TREE
INC_DIR := ./include
SRC_DIR := ./src
OBJ_DIR := ./bin
EXECUTABLE := ./$(shell echo $(PROJECT_NAME) | tr A-Z a-z)

CC := gcc
LIBS :=
CFLAGS := -g -Wall -Wextra -I$(INC_DIR)

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')

OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

DEP_FILES := $(wildcard $(INC_DIR)/*.h)

.PHONY: clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# for any file ending in .o in OBJ_DIR, dependent on the respective .c file and header
# compile it generating object files and output it as with the same name. Also makes sure that OBJ_DIR exists.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP_FILES) | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/$(PROJECT_NAME) $(EXECUTABLE)
	rm -rf $(OBJ_DIR)

# creates the bin directory and its subdirectories if they dont exist
$(OBJ_DIR):
	mkdir -p $(dir $(OBJ_FILES))
