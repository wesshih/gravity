CC = gcc
CFLAGS = -Wall -std=c99 -g -lm
OBJ = vector3.o simulator.o particle.o
SRC = vector3.c simulator.c particle.c


%.o:
	$(CC) -c -o $@ $*.c $(CFLAGS)

make: $(OBJ)
	$(CC) -o simulator $(OBJ) $(CFLAGS)

clean:
	rm -f *.o simulator
