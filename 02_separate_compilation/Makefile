CC = gcc

.SECONDARY:

.PHONEY: all
all: example second

example: main.o libhelper.a
	$(CC) $^ -o $@

main.i: main.c helper.h 
	$(CC) -E $< -o $@

helper.i: helper.c helper.h 
	$(CC) -E $< -o $@

%.s: %.i
	$(CC) -S $< -o $@ 

#helper.s: helper.i
#	$(CC) -S $< -o $@ 

%.o: %.s 
	$(CC) -c $< -o $@

#helper.o: helper.s 
#	$(CC) -c $< -o $@

libhelper.a: helper.o extra.o
	ar rcs $@ $^

%.i: %.c
	$(CC) -E $< -o $@

main.i helper.i second.i: helper.h

#extra.s: extra.i
#	$(CC) -S $< -o $@

#extra.o: extra.s 
#	$(CC) -c $< -o $@

#second.i: second.c 
#	$(CC) -E $< -o $@

#second.s: second.i
#	$(CC) -S $< -o $@

#second.o: second.s 
#	$(CC) -c $< -o $@

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