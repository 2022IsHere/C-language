CC = gcc
CFLAGS = -Wall -Wextra -std=c18

default: Exercise8

Exercise8: Exercise8.o Student.o
	$(CC) $(CFLAGS) -o Exercise8 Exercise8.o Student.o -lm

Exercise8.o: Exercise8.c Student.h
	$(CC) $(CFLAGS) -c Exercise8.c

Student.o: Student.c Student.h
	$(CC) $(CFLAGS) -c Student.c

clean:
	$(RM) Exercise8 *.o *~
