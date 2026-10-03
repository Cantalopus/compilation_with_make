main.i: main.c
	gcc -E main.c -o main.i

main.s: main.i
	gcc -S main.i -o main.s

main.o: main.s 
	gcc -c main.s -o main.o

example: main.o
	gcc main.o -o example 