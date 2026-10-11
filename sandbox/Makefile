CC = gcc

.PHONY: build

example: build/main.o 
	$(CC) $(^) -o $(@)

build/main.i: main.c | build
	$(CC) -E $(<) -o $(@)

build/main.s: build/main.i | build
	$(CC) -S $(<) -o $(@)

build/main.o: build/main.s | build
	$(CC) -c $(<) -o $(@)

build bin: 
	mkdir -p build bin

.PHONY: clean
clean:
	rm -rf build bin