#ifndef CAT_H
#define CAT_H

#include <getopt.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int b;
  int n;
  int s;
  int e;
  int t;
  int v;
} cat_flag;
typedef struct {
  int sym_en;
  int line;
} elem;

void simple_print(int argc, char* argv[]);
void hard_printing(int argc, char* argv[], cat_flag* flag);
void hard_print(FILE* f, cat_flag* flag, elem* elem);
void e_v_t_flags(int sym_cu, int sym_pa, cat_flag* flag);
int b_n_s_flags(cat_flag* flag, elem* elem, int sym_cu, int sym_pa);

#endif
