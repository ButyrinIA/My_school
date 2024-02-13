C = gcc

CFLAGS =  -Wall -Werror -Wextra -c

all:  s21_grep

s21_grep:   s21_grep.c  s21_grep.h 
	$(C) $(CFLAGS)  s21_grep.c -o  s21_grep.o
	$(C)  s21_grep.o -o s21_grep
	rm s21_grep.o

clean:
	rm s21_grep

rebuild: clean all
