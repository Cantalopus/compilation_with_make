example: main.o helper.o
	gcc main.o helper.o -o example

.SECONDARY:

main.i helper.i: helper.h

%.i: %.c
	gcc -E $< -o $@

%.s: %.i
	gcc -S $< -o $@

%.o: %.s
	gcc -c $< -o $@
