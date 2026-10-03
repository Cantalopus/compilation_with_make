CC = gcc

example: main.o helper.o
	$(CC) $^ -o $@

.SECONDARY:

# when using % to build, we need to add this
# so Make knows that main.i and helper.i
# depend on helper.h
main.i helper.i: helper.h

%.i: %.c 
	$(CC) -E $< -o $@

%.s: %.i
	$(CC) -S $< -o $@

%.o: %.s 
	$(CC) -c $^ -o $@


.PHONY: clean
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
#.SECONDARY:
#
#main.i helper.i: helper.h
#
#%.i: %.c
#	gcc -E $< -o $@
#
#%.s: %.i
#	gcc -S $< -o $@
#
#%.o: %.s
#	gcc -c $< -o $@
