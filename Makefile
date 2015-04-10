CC = gcc
CFLAGS = -Wall -std=c99 -g
OBJ = util_space_3.o test.o
SRC = util_space_3.c test.c


%.o:
	$(CC) $(CFLAGS) -c -o $@ $*.c

make: $(OBJ)
	$(CC) $(CFLAGS) -o test $(OBJ)

clean:
	rm -f *.o test
