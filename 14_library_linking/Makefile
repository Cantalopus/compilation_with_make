.PHONY: all
all: diagonal diagonal_static
	ls -l $(^)

diagonal: main.o 
	gcc $(^) -lm -lc -o $(@)

diagonal_static: main.o
	gcc -static $(<) -lm -lc -o $(@)

.SECONDARY:

main.i: main.c
	gcc -E $(<) -o $(@)

main.s: main.i 
	gcc -g -Wall -Wextra -S $(<) -o $(@)

main.o: main.s 
	gcc -c $(<) -o $(@)



.PHONY: clean
clean:
	rm -f main.i \
		  main.s \
          main.o \
		  diagonal \
		  diagonal_static