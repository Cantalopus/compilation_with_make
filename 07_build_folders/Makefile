CC = gcc

bin/example: build/main.o build/helper.o
	mkdir -p bin
	$(CC) $^ -o $@

build/main.i: src/app/main.c src/lib/include/helper.h
	mkdir -p build
	$(CC) -E $< -o $@

build/main.s: build/main.i 
	mkdir -p build
	$(CC) -S $< -o $@

build/main.o: build/main.s 
	mkdir -p build
	$(CC) -c $< -o $@

build/helper.i: src/lib/helper.c src/lib/include/helper.h 
	mkdir -p build
	$(CC) -E $< -o $@

build/helper.s: build/helper.i 
	mkdir -p build
	$(CC) -S $< -o $@

build/helper.o: build/helper.s 
	mkdir -p build
	$(CC) -c $< -o $@ 


.PHONY: clean
clean: 
	rm -rf build \
		   bin













#bin/example: build/main.o build/helper.o
#	mkdir -p bin
#	gcc build/main.o build/helper.o -o bin/example
#
#build/main.i: main.c helper.h
#	mkdir -p build
#	gcc -E main.c -o build/main.i
#
#build/main.s: build/main.i
#	mkdir -p build
#	gcc -S build/main.i -o build/main.s
#
#build/main.o: build/main.s
#	mkdir -p build
#	gcc -c build/main.s -o build/main.o
#
#build/helper.i: helper.c helper.h
#	mkdir -p build
#	gcc -E helper.c -o build/helper.i
#
#build/helper.s: build/helper.i
#	mkdir -p build
#	gcc -S build/helper.i -o build/helper.s
#
#build/helper.o: build/helper.s
#	mkdir -p build
#	gcc -c build/helper.s -o build/helper.o
