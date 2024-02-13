#ifndef GREP_H
#define GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;

} grep_flag;

typedef struct {
  int counter_n;
  int counter_c;
  int file;
  char argument[5000];
} elem;
void parsing(int argc, char* argv[], grep_flag* flag, elem* elem);
void hard_printing(char* argv[], grep_flag* flag, elem* elem);
void printer(char* argv[], grep_flag* flag, elem* elem, char* str,
             regmatch_t pmatch);
#endif
