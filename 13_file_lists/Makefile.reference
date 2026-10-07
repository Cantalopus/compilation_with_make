ORDER_INC = -Isrc/lib/orders/include
STOCK_INC  = -Isrc/lib/stock/include


ORDER_OBJ = build/bolt_order.o \
            build/nut_order.o \
            build/panel_order.o 
STOCK_OBJ = build/bolt_stock.o \
			build/nut_stock.o \
			build/panel_stock.o

ORDER_DEP =	$(patsubst %.o,%.d,$(ORDER_OBJ))
STOCK_DEP = $(patsubst %.o,%.d,$(STOCK_OBJ)) 

CC = gcc
CPPFLAGS = $(STOCK_INC) $(ORDER_INC)
CFLAGS = -g -Wall -Wextra

.PHONY: all
all: bin/balance bin/order bin/stock

bin/balance: build/balance_check.o \
             build/liborder.a \
			 build/libstock.a          | bin
	$(CC) $(^) -o $(@)

bin/order: build/order_report.o \
           build/liborder.a            | bin
	$(CC) $(^) -o $(@)

bin/stock: build/stock_report.o \
           build/libstock.a            | bin
	$(CC) $(^) -o $(@)

build/liborder.a: $(ORDER_OBJ)         | build
	ar rcs $(@) $(^)

build/libstock.a: $(STOCK_OBJ)         | build
	ar rcs $(@) $(^) 

.SECONDARY:

build/%.i: src/apps/checks/%.c         | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/apps/reports/%.c        | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/orders/hardware/%.c | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/orders/panels/%.c   | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/stock/hardware/%.c  | build 
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/stock/panels/%.c    | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.s: build/%.i                   | build
	$(CC) $(CFLAGS) -S $(<) -o $(@)

build/%.o: build/%.s | build
	$(CC) -c $(<) -o $(@)


-include build/balance_check.d \
		 build/order_report.d \
		 build/stock_report.d \
		 $(STOCK_DEP) \
		 $(ORDER_DEP)

build bin:
	mkdir -p $(@)

.PHONY: clean
clean: 
	rm -rf bin build