CC = clang
CFLAGS = -std=c17 -Wall -Wextra -Werror -Wpedantic -O2 -g
LFLAGS =

hashing_OBJS = hashing.o xor.o

all: hashing

%.o: %.c
	$(CC) $(CFLAGS) -c $<

hashing: hashing.o xor.o
	$(CC) $(LFLAGS) $(hashing_OBJS) -o hashing

checkhashing: hashing
	valgrind --leak-check=full ./hashing

clean:
	rm -f *.o hashing

scan-build: clean
	scan-build --use-cc=$(CC) make all

format:
	clang-format -i -style=file *.[ch]

.PHONY: all clean scan-build format checkhashing
