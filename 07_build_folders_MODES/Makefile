CC = gcc
CPPFLAGS = -Isrc/lib/include
CFLAGS = -g -Wall -Wextra
DFLAGS = -MMD -MF $(@:.i=.d) -MT $(@)

MODE ?= debug

BUILD_DIR = build/$(MODE)
BIN_DIR = bin/$(MODE)

SRC = src/app/main.c \
	  src/lib/helper.c
OBJ = $(BUILD_DIR)/main.o \
      $(BUILD_DIR)/helper.o	  
DEP = $(patsubst %.c,%.d,$(OBJ))

ifeq ($(MODE),debug)
CFLAGS = -g -O0 -Wall -Wextra
else ifeq ($(MODE), release)
CFLAGS = -g -O2 -Wall -Wextra
else
$(error Unknown MODE '$(MODE)'; use debug or release)
endif

##################################################

.PHONY: all
all: $(BIN_DIR)/example

$(BIN_DIR)/example: $(BUILD_DIR)/main.o \
                    $(BUILD_DIR)/libhelper.a | $(BIN_DIR)
	$(CC) $(^) -o $(@)

##################################################

$(BUILD_DIR)/libhelper.a: $(BUILD_DIR)/helper.o | $(BUILD_DIR)
	ar rcs $(@) $(^)

##################################################

.SECONDARY:

$(BUILD_DIR)/%.i: src/app/%.c      | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@) 

$(BUILD_DIR)/%.i: src/lib/%.c      | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.s: $(BUILD_DIR)/%.i | $(BUILD_DIR)
	$(CC) $(CFLAGS) -S $(<) -o $(@)

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.s | $(BUILD_DIR)
	$(CC) -c $(<) -o $(@)

##################################################

-include $(BUILD_DIR)/helper.d \
		 $(BUILD_DIR)/main.d

##################################################

.PHONY: list-dep 
list-dep:
	@echo $(DEP)

.PHONY: list-obj 
list-obj:
	@echo $(OBJ)

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $(@)

.PHONY: clean
clean: 
	$(if $(wildcard bin build), rm -rf $(wildcard bin build))