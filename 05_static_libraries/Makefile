example: main.o libnumbers.a
	gcc main.o libnumbers.a -o example

libnumbers.a: helper.o extra.o
	ar rcs libnumbers.a helper.o extra.o

main.i: main.c helper.h
	gcc -E main.c -o main.i

main.s: main.i
	gcc -S main.i -o main.s

main.o: main.s
	gcc -c main.s -o main.o

helper.i: helper.c helper.h
	gcc -E helper.c -o helper.i

helper.s: helper.i
	gcc -S helper.i -o helper.s

helper.o: helper.s
	gcc -c helper.s -o helper.o

extra.i: extra.c
	gcc -E extra.c -o extra.i

extra.s: extra.i
	gcc -S extra.i -o extra.s

extra.o: extra.s
	gcc -c extra.s -o extra.o
