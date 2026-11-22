CC = gcc
CPPFLAGS = -Isrc/lib/include -MMD -MF $(@:.i=.d) -MT $(@)
CFLAGS = -g -Wall -Wextra

MODE = debug

BIN_DIR = bin/$(MODE)
BUILD_DIR = build/$(MODE)
SRC_DIR = src/ 

APP_SRC = $(wildcard src/app/*.c)
LIB_SRC = $(wildcard src/lib/*.c)
SRC = $(APP_SRC) $(LIB_SRC)
DEP = $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all
all: $(BIN_DIR)/example

$(BIN_DIR)/example: $(BUILD_DIR)/main.o \
                    $(BUILD_DIR)/libhelper.a | $(BIN_DIR)
	$(CC) $(^) -o $(@)

$(BUILD_DIR)/libhelper.a: $(BUILD_DIR)/helper.o | $(BUILD_DIR) 
	ar rcs $(@) $(^) 

.SECONDARY:

$(BUILD_DIR)/%.i: src/app/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) -E $(<) -o $(@) 

$(BUILD_DIR)/%.i: src/lib/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.s: $(BUILD_DIR)/%.i | $(BUILD_DIR)
	$(CC) $(CFLAGS) -S $(<) -o $(@) 

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.s | $(BUILD_DIR)
	$(CC) -c $(<) -o $(@) 


-include $(DEP)


.PHONY: list-src
list-src:
	@echo $(SRC)

.PHONY: list-app_src
list-app_src:
	@echo $(APP_SRC)

.PHONY: list-lib_src
list-lib_src:
	@echo $(LIB_SRC)

.PHONY: list-dep
list-dep:
	@echo $(DEP)

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $(@)

.PHONY: clean
clean:
	rm -rf build bin
