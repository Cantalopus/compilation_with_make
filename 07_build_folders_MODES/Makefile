CC = gcc
CPPFLAGS = -Isrc/lib/include
CFLAGS = -g -O0 -Wall -Wextra
DFLAGS = -MMD -MF $(@:.i=.d) -MT $(@)

#################################################################

MODE ?= debug

APP = $(wildcard src/app/*.c)
LIB = $(wildcard src/lib/*.c)
SRC = $(APP) $(LIB) 
BIN_DIR = bin/$(MODE)
BUILD_DIR = build/$(MODE)
BUILD = $(wildcard $(BUILD_DIR)/*.*)

PP  = $(wildcard $(BUILD_DIR)/*.i) 
ASM = $(patsubst %.i,%.s,$(PP))
OBJ = $(patsubst %.s,%.o,$(ASM))
INC = $(wildcard */*/*/*.h)
DEP = $(patsubst %.i,%.d,$(PP))

#################################################################

ifeq ($(MODE),debug)
CFLAGS = -g -O0 -Wall -Wextra
$(info >>>>>>>>>>DEBUG MODE<<<<<<<<<<)
else ifeq ($(MODE),release)
CFLAGS = -O3 -Wall -Wextra
$(info >>>>>>>>>>RELEASE MODE<<<<<<<<<<)
else
$(error ERROR: '$(MODE)' is not a valid build mode,\
                         use debug or release)
endif

#################################################################

.PHONY: all
all: $(BIN_DIR)/example 

#################################################################

$(BIN_DIR)/example: $(BUILD_DIR)/main.o \
                    $(BUILD_DIR)/libhelper.a | $(BIN_DIR)
	$(CC) $(^) -o $(@) 

$(BUILD_DIR)/libhelper.a: $(BUILD_DIR)/helper.o | $(BUILD_DIR)
	ar rcs $(@) $(^)

#################################################################

.SECONDARY:

$(BUILD_DIR)/%.i: src/app/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.i: src/lib/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.s: $(BUILD_DIR)/%.i | $(BUILD_DIR)
	$(CC) $(CFLAGS) -S $(<) -o $(@) 

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.s | $(BUILR_DIR)
	$(CC) -c $(<) -o $(@)

#################################################################

-include $(DEP)

#################################################################

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $(@) 

#################################################################

.PHONY: clean
clean:
	rm -rf build bin