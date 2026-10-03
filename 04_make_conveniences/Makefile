CC = gcc

.PHONY: all
all: example

example: main.o helper.o
	$(CC) $^ -o $@

main.i: main.c helper.h
	$(CC) -E $< -o $@

main.s: main.i
	$(CC) -S $< -o $@
 
main.o: main.s 
	$(CC) -c $< -o $@

helper.i: helper.c helper.h
	$(CC) -E $< -o $@

helper.s: helper.i
	$(CC) -S $< -o $@

helper.o: helper.s 
	$(CC) -c $< -o $@


.PHONY: clean
clean:
	rm -f main.i \
	      main.s \
		  main.o \
		  helper.i \
		  helper.s \
		  helper.o \
		  example
