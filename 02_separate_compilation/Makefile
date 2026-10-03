CC = gcc

.PHONEY: all
all: example second

example: main.o libhelper.a
	$(CC) $^ -o $@

main.i: main.c helper.h 
	$(CC) -E $< -o $@

helper.i: helper.c helper.h 
	$(CC) -E $< -o $@

main.s: main.i
	$(CC) -S $< -o $@ 

helper.s: helper.i
	$(CC) -S $< -o $@ 

main.o: main.s 
	$(CC) -c $< -o $@

helper.o: helper.s 
	$(CC) -c $< -o $@

libhelper.a: helper.o extra.o
	ar rcs $@ $^

extra.i: extra.c
	$(CC) -E $< -o $@

extra.s: extra.i
	$(CC) -S $< -o $@

extra.o: extra.s 
	$(CC) -c $< -o $@

second.i: second.c 
	$(CC) -E $< -o $@

second.s: second.i
	$(CC) -S $< -o $@

second.o: second.s 
	$(CC) -c $< -o $@

second: second.o libhelper.a
	$(CC) $^ -o $@

.PHONEY: clean
clean:
	rm -f main.i \
	      helper.i \
		  main.s \
		  helper.s \
		  main.o \
		  helper.o \
		  libhelper.a \
		  extra.i \
		  extra.s \
		  extra.o \
		  second.i \
		  second.s \
		  second.o \
		  second \
		  example