CC = gcc

.PHONY: all
all: bin/example bin/second

bin/example: build/main.o build/libnumbers.a
	mkdir -p bin
	$(CC) $^ -o $@

bin/second: build/second.o build/libnumbers.a 
	mkdir -p bin
	$(CC) $^ -o $@

build/libnumbers.a: build/helper.o build/extra.o 
	mkdir -p build
	ar rcs $@ $^

.SECONDARY:

build/main.i build/helper.i build/extra.i build/second.i: \
	src/lib/include/helper.h 

build/%.i: src/app/%.c 
	mkdir -p build
	$(CC) -E $< -o $@

build/%.i: src/lib/%.c 
	mkdir -p build
	$(CC) -E $< -o $@ 

build/%.s: build/%.i
	mkdir -p build
	$(CC) -S $< -o $@ 

build/%.o: build/%.s 
	mkdir -p build
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -rf build bin



































#CC = gcc
#
#.PHONY: all
#all: bin/example bin/second
#
#bin/example: build/main.o build/libnumbers.a
#	mkdir -p bin
#	$(CC) $^ -o $@
#
#bin/second: build/second.o build/libnumbers.a 
#	mkdir -p bin
#	$(CC) $^ -o $@
#
#build/libnumbers.a: build/helper.o build/extra.o
#	mkdir -p build
#	ar rcs $@ $^
#
#.SECONDARY:	
#
#build/main.i build/helper.i build/extra.i build/second.i: src/lib/include/helper.h
#
#build/%.i: src/app/%.c 
#	mkdir -p build
#	$(CC) -E $< -o $@
#
#build/%.i: src/lib/%.c 
#	mkdir -p build
#	$(CC) -E $< -o $@
#
#build/%.s: build/%.i 
#	mkdir -p build
#	$(CC) -S $< -o $@
#
#build/%.o: build/%.s 
#	mkdir -p build
#	$(CC) -c $< -o $@
#
#.PHONY: clean
#clean: 
#	rm -rf build bin