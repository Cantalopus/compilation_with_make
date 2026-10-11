CC = gcc
CPPFLAGS = -Isrc/lib/orders/include -Isrc/lib/stock/include
CFLAGS = -g -Wall -Wextra
DFLAGS = -MMD -MF $(@:.i=.d) -MT $(@)

DEP = $(wildcard $(BUILD_DIR)/*.d)
BIN = $(wildcard bin/*)

ORDER_OBJ = $(BUILD_DIR)/bolt_order.o \
			$(BUILD_DIR)/nut_order.o \
			$(BUILD_DIR)/panel_order.o
STOCK_OBJ = $(BUILD_DIR)/bolt_stock.o \
			$(BUILD_DIR)/nut_stock.o \
			$(BUILD_DIR)/panel_stock.o 

OBJ = $(ORDER_OBJ) $(STOCK_OBJ)

MODE ?= debug

BUILD_DIR = build/$(MODE)
BIN_DIR = bin/$(MODE)

ifeq ($(MODE),debug)
CFLAGS = -g -O0 -Wall -Wextra
else ifeq ($(MODE), release)
CFLAGS = -g -O2 -Wall -Wextra
else ifeq ($(MODE), turbo)
CFLAGS = -g -O3 -Wall -Wextra
else
$(error Unknown MODE '$(MODE)'; use debug or release)
endif

##################################################

.PHONY: all
all: $(BIN_DIR)/balance \
	 $(BIN_DIR)/order \
	 $(BIN_DIR)/stock

$(BIN_DIR)/balance: $(BUILD_DIR)/balance_check.o \
             $(BUILD_DIR)/libstock.a \
			 $(BUILD_DIR)/liborder.a | $(BIN_DIR)
	$(CC) $(^) -lc -o $(@)

$(BIN_DIR)/order: $(BUILD_DIR)/order_report.o \
           $(BUILD_DIR)/liborder.a   | $(BIN_DIR)
	$(CC) $(^) -lc -o $(@)

$(BIN_DIR)/stock: $(BUILD_DIR)/stock_report.o \
           $(BUILD_DIR)/libstock.a   | $(BIN_DIR) 
	$(CC) $(^) -lc -o $(@)

##################################################

$(BUILD_DIR)/liborder.a: $(ORDER_OBJ)         | $(BUILD_DIR)
	ar rcs $(@) $(^)

$(BUILD_DIR)/libstock.a: $(STOCK_OBJ)         | $(BUILD_DIR)
	ar rcs $(@) $(^)

##################################################

.SECONDARY:

$(BUILD_DIR)/%.i: src/apps/checks/%.c         | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.i: src/apps/reports/%.c        | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.i: src/lib/orders/hardware/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.i: src/lib/orders/panels/%.c   | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.i: src/lib/stock/hardware/%.c  | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.i: src/lib/stock/panels/%.c    | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

$(BUILD_DIR)/%.s: $(BUILD_DIR)/%.i | $(BUILD_DIR)
	$(CC) $(CFLAGS) -S $(<) -o $(@)

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.s | $(BUILD_DIR)
	$(CC) -c $(<) -o $(@)

##################################################

-include $(DEP)

##################################################

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $(@)

.PHONY: show-config
show-config:
	@echo "MODE      = $(MODE)"
	@echo "BUILD_DIR = $(BUILD_DIR)"
	@echo "BIN_DIR   = $(BIN_DIR)"
	@echo "CFLAGS    = $(CFLAGS)"

.PHONY: check-build
check-build:
	$(if $(wildcard build), @echo build directory found, \
	                        @echo No build directory)

.PHONY: clean build
clean:
	$(if $(wildcard bin build), rm -rf $(wildcard bin build))

#clean:
#	touch clean