CC = gcc
CPPFLAGS = -Isrc/lib/orders/include -Isrc/lib/stock/include
CFLAGS = -g -Wall -Wextra

.PHONY: all
all: bin/balance bin/order_report bin/stock_report

bin/balance: build/balance_check.o \
             build/liborder.a \
			 build/libstock.a              | bin
	$(CC) $(^) -o $(@)

bin/order_report: build/order_report.o \
                  build/liborder.a         | bin
	$(CC) $(^) -o $(@)

bin/stock_report: build/stock_report.o \
                  build/libstock.a         | bin
	$(CC) $(^) -o $(@) 


build/liborder.a: build/bolt_order.o \
				  build/nut_order.o \
				  build/panel_order.o
	ar rcs $(@) $(^)

build/libstock.a: build/bolt_stock.o \
				  build/nut_stock.o \
				  build/panel_stock.o
	ar rcs $(@) $(^) 

.SECONDARY:

build/%.i: src/apps/checks/%.c | build 
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/apps/reports/%.c | build 
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/orders/hardware/%.c | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/orders/panels/%.c | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/stock/hardware/%.c | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/stock/panels/%.c | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.s: build/%.i | build
	$(CC) $(CFLAGS) -S $(<) -o $(@)

build/%.o: build/%.s | build
	$(CC) -c $(<) -o $(@) 


-include build/balance_check.d \
		 build/order_report.d \
    	 build/stock_report.d \
		 build/bolt_order.d \
		 build/nut_order.d \
		 build/panel_order.d \
		 build/bolt_stock.d \
		 build/nut_stock.d \
		 build/panel_stock.d

build bin: 
	mkdir -p $(@)

.PHONY: clean
clean:
	rm -rf build bin

