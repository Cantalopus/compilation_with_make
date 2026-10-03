bin/example: build/main.o build/helper.o
	mkdir -p bin
	gcc build/main.o build/helper.o -o bin/example

build/main.i: main.c helper.h
	mkdir -p build
	gcc -E main.c -o build/main.i

build/main.s: build/main.i
	mkdir -p build
	gcc -S build/main.i -o build/main.s

build/main.o: build/main.s
	mkdir -p build
	gcc -c build/main.s -o build/main.o

build/helper.i: helper.c helper.h
	mkdir -p build
	gcc -E helper.c -o build/helper.i

build/helper.s: build/helper.i
	mkdir -p build
	gcc -S build/helper.i -o build/helper.s

build/helper.o: build/helper.s
	mkdir -p build
	gcc -c build/helper.s -o build/helper.o
