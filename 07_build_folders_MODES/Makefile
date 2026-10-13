CC = gcc
CPPFLAGS = -Isrc/lib/include
CFLAGS ?= -g -O0 -Wall -Wextra
DFLAGS = -MMD -MF $(@:.i=.d) -MT $(@)

MODE ?= debug

ifeq ($(MODE),debug)
CFLAGS = -g -O0 -Wall -Wextra
$(info >>>>>>>DEBUG MODE<<<<<<<)
else ifeq ($(MODE),release)
CFLAGS = -O2 -Wall -Wextra
$(info >>>>>>>RELEASE MODE<<<<<<<)
else
$(error $(MODE) is not a valid mode, use debug or release)
endif

BUILD_DIR = build/$(MODE)
BIN_DIR = bin/$(MODE)
DEP = $(wildcard $(BUILD_DIR)/*.d)

$(BIN_DIR)/example: $(BUILD_DIR)/main.o \
                    $(BUILD_DIR)/libhelper.a    | $(BIN_DIR)
	$(CC) $(^) -lc -o $(@) 

$(BUILD_DIR)/libhelper.a: $(BUILD_DIR)/helper.o | $(BUILD_DIR)
	ar rcs $(@) $(^)

.SECONDARY:

$(BUILD_DIR)/%.i: src/app/%.c      | $(BUILD_DIR) 
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.i: src/lib/%.c      | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.s: $(BUILD_DIR)/%.i | $(BUILD_DIR)
	$(CC) $(CFLAGS) -S $(<) -o $(@)

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.s | $(BUILD_DIR)
	$(CC) -c $(<) -o $(@) 

-include $(DEP)

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $(BUILD_DIR) $(BIN_DIR)

.PHONY: clean
clean: 
	$(if $(wildcard build bin), rm -rf \
	     $(wildcard build bin))

.PHONY: list-dep 
list-dep:
	@echo '$(DEP)'