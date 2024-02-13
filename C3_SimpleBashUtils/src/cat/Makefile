C = gcc

CFLAGS =  -Wall -Werror -Wextra -c

all:  s21_cat

s21_cat:  s21_cat.c s21_cat.h 
	$(C) $(CFLAGS) s21_cat.c -o s21_cat.o
	$(C) s21_cat.o -o s21_cat
	rm s21_cat.o

clean:
	rm s21_cat

rebuild: clean all
