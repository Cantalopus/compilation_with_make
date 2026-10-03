example: main.o helper.o
	gcc main.o helper.o -o example

main.i: main.c
	gcc -E main.c -o main.i

main.s: main.i
	gcc -S main.i -o main.s 

main.o: main.s 
	gcc -c main.s -o main.o

helper.i: helper.c 
	gcc -E helper.c -o helper.i

helper.s: helper.i
	gcc -S helper.i -o helper.s 

helper.o: helper.s 
	gcc -c helper.s -o helper.o


.PHONEY: clean
clean: 
	rm -f main.i \
	      main.s \
	      main.o \
		  helper.i \
		  helper.s \
		  helper.o \
		  example
































#example: main.o helper.o
#	gcc main.o helper.o -o example
#
#main.i: main.c helper.h
#	gcc -E main.c -o main.i
#
#main.s: main.i
#	gcc -S main.i -o main.s
#
#main.o: main.s
#	gcc -c main.s -o main.o
#
#helper.i: helper.c helper.h
#	gcc -E helper.c -o helper.i
#
#helper.s: helper.i
#	gcc -S helper.i -o helper.s
#
#helper.o: helper.s
#	gcc -c helper.s -o helper.o


