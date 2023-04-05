CC = gcc
CFLAGS = -Wall -Wextra -std=c18

default: Exercise7

Exercise7: Exercise7.o Matrix.o Sieve.o
	$(CC) $(CFLAGS) -o Exercise7 Exercise7.o Matrix.o Sieve.o -lm

Exercise7.o: Exercise7.c Matrix.h Sieve.h
	$(CC) $(CFLAGS) -c Exercise7.c

Matrix.o: Matrix.c Matrix.h
	$(CC) $(CFLAGS) -c Matrix.c

Sieve.o: Sieve.c Sieve.h
	$(CC) $(CFLAGS) -c Sieve.c

clean:
	$(RM) Exercise7 *.o *~
