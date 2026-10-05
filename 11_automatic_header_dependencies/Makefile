CC = gcc
CPPFLAGS = -Isrc/lib/include
CFLAGS = -Wall -Wextra -g 

.PHONY: all
all: bin/example bin/second

bin/example: build/main.o build/libnumbers.a | bin
	$(CC) $(^) -o $(@)

bin/second: build/second.o build/libnumbers.a | bin
	$(CC) $(^) -o $(@)

build/libnumbers.a: build/helper.o build/extra.o | build
	ar rcs $(@) $(^)

.SECONDARY:

#build/main.i build/helper.i build/extra.i build/second.i: \
#	src/lib/include/helper.h 

build/%.i: src/app/%.c | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.i: src/lib/%.c | build
	$(CC) $(CPPFLAGS) -MMD -MF $(@:.i=.d) -MT $(@) -E $(<) -o $(@)

build/%.s: build/%.i | build
	$(CC) $(CFLAGS) -S $(<) -o $(@)

build/%.o: build/%.s | build
	$(CC) -c $(<) -o $(@)

-include build/main.d \
         build/second.d \
		 build/helper.d \
		 build/extra.d

build bin:
	mkdir -p $(@)


.PHONY: clean
clean: 
	rm -rf build bin