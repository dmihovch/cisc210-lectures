CC = cc
CFLAGS = -Wall -Wextra -g -O0 -fno-omit-frame-pointer
PROGRAMS = 00-ptr-arith 01-structs 02-heap-stack

all: $(PROGRAMS)

00-ptr-arith: 00-ptr-arith.c
	$(CC) $(CFLAGS) $< -o $@

01-structs: 01-structs.c
	$(CC) $(CFLAGS) $< -o $@

02-heap-stack: 02-heap-stack.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
