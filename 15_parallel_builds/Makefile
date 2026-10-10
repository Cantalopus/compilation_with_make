CC = gcc
CPPFLAGS = -Isrc/lib/orders/include -Isrc/lib/stock/include
CFLAGS = -g -Wall -Wextra
DFLAGS = -MMD -MF $(@:.i=.d) -MT $(@)

DEP = $(wildcard build/*.d)
BIN = $(wildcard bin/*)

ORDER_OBJ = build/bolt_order.o \
			build/nut_order.o \
			build/panel_order.o
STOCK_OBJ = build/bolt_stock.o \
			build/nut_stock.o \
			build/panel_stock.o 

OBJ = $(ORDER_OBJ) $(STOCK_OBJ)


.PHONY: all
all: bin/balance \
	 bin/order \
	 bin/stock

bin/balance: build/balance_check.o \
			 build/liborder.a \
			 build/libstock.a | bin
	$(CC) $(^) -lc -o $(@)

bin/order: build/order_report.o \
		   build/liborder.a | bin
	$(CC) $(^) -lc -o $(@)

bin/stock: build/stock_report.o \
		   build/libstock.a | bin
	$(CC) $(^) -lc -o $(@)

build/liborder.a: $(ORDER_OBJ) | build
	ar rcs $(@) $(^)

build/libstock.a: $(STOCK_OBJ) | build
	ar rcs $(@) $(^)

.SECONDARY:

build/%.i: src/apps/checks/%.c | build
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

build/%.i: src/apps/reports/%.c | build
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

build/%.i: src/lib/orders/hardware/%.c | build
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

build/%.i: src/lib/orders/panels/%.c | build
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

build/%.i: src/lib/stock/hardware/%.c | build
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

build/%.i: src/lib/stock/panels/%.c | build
	$(CC) $(CPPFLAGS) $(DFLAGS) -E $(<) -o $(@)

build/%.s: build/%.i | build
	$(CC) $(CFLAGS) -S $(<) -o $(@)

build/%.o: build/%.s | build
	$(CC) -c $(<) -o $(@)


-include $(DEP)


build bin:
	mkdir -p $(@)

.PHONY: clean
clean: 
	$(if $(wildcard bin build), rm -rf $(wildcard bin build))