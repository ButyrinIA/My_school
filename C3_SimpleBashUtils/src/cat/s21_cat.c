#include "s21_cat.h"

void simple_print(int argc, char *argv[]) {
  FILE *f = fopen(argv[argc - 1], "r");
  char str;
  if (f == NULL) {
    fprintf(stderr, "cat: %s: No such file or directory\n", argv[argc - 1]);

  } else {
    while ((str = fgetc(f)) != EOF) {
      printf("%c", str);
    }
    fclose(f);
  }
}

void hard_printing(int argc, char *argv[], cat_flag *flag) {
  struct option long_option[] = {{"--", 0, NULL, '-'},
                                 {"number-nonblank", 0, NULL, 'b'},
                                 {"number", 0, NULL, 'n'},
                                 {"squeeze-blank", 0, NULL, 's'},
                                 {NULL, 0, NULL, 0}};
  int option;
  int index;
  elem elem1 = {1, 1};
  elem *elem = &elem1;
  while ((option = getopt_long(argc, argv, "benstvET", long_option, &index)) !=
         -1) {
    if (option == 'b') {
      flag->b = 1;
    }
    if (option == 'e') {
      flag->e = 1;
      flag->v = 1;
    }
    if (option == 'n') {
      flag->n = 1;
    }
    if (option == 's') {
      flag->s = 1;
    }
    if (option == 't') {
      flag->t = 1;
      flag->v = 1;
    }
    if (option == 'v') {
      flag->v = 1;
    }
    if (option == 'E') {
      flag->e = 1;
    }
    if (option == 'T') {
      flag->t = 1;
    }
    if (option == '?') {
      printf("Unknown option: %c\n", option);
    }
  }
  for (int i = optind; i < argc; i++) {
    FILE *f = fopen(argv[i], "r");
    if (f == NULL) {
      fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
      continue;
    }
    hard_print(f, flag, elem);
    fclose(f);
  }
}
void hard_print(FILE *f, cat_flag *flag, elem *elem) {
  int sym_cu;
  int sym_pa = 0;
  while ((sym_cu = fgetc(f)) != EOF) {
    if (b_n_s_flags(flag, elem, sym_cu, sym_pa) == 1) {
      e_v_t_flags(sym_cu, sym_pa, flag);
    }
    if (sym_cu == '\n') {
      elem->sym_en += 1;
    } else {
      elem->sym_en = 0;
    }

    sym_pa = sym_cu;
  }
}

int b_n_s_flags(cat_flag *flag, elem *elem, int sym_cu, int sym_pa) {
  if (flag->s == 1 && elem->sym_en > 1 && sym_cu == '\n') {
    return 0;
  } else if (flag->n == 1 && flag->b == 0 &&
             (sym_pa == '\n' || elem->line == 1)) {
    printf("%6d\t", elem->line++);
  } else if (flag->b == 1 && sym_cu != '\n' &&
             (sym_pa == '\n' || elem->line == 1)) {
    printf("%6d\t", elem->line++);
  }
  return 1;
}

void e_v_t_flags(int sym_cu, int sym_pa, cat_flag *flag) {
  if (sym_cu == '\n') {
    if (flag->e == 1) {
      if (sym_pa == '\n') {
        printf("\t$\n");
      } else {
        printf("$\n");
      }
    } else
      printf("\n");
  } else if (sym_cu == '\t') {
    if (flag->t == 1) {
      printf("^I");
    } else {
      printf("\t");
    }
  }

  else if (flag->v == 1 && sym_cu != '\t') {
    if (sym_cu >= 0 && sym_cu <= 31 && sym_cu != '\n' && sym_cu != '\t') {
      printf("^%c", sym_cu + 64);
    } else if (sym_cu == 127) {
      printf("^?");
    } else if (sym_cu >= 128 && sym_cu <= 159)
      printf("M-^%c", (sym_cu + 191) % 255);

    else {
      printf("%c", sym_cu);
    }
  } else {
    printf("%c", sym_cu);
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2) {
    simple_print(argc, argv);
  } else if (argc > 2) {
    cat_flag flag = {0};
    hard_printing(argc, argv, &flag);
  } else {
    printf("error\n");
  }
  return 0;
}
