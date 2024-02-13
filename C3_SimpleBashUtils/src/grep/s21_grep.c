#include "s21_grep.h"

void parsing(int argc, char *argv[], grep_flag *flag, elem *elem) {
  char option;
  while ((option = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    if (option == 'e') {
      flag->e = 1;
      strcat(elem->argument, optarg);
      strcat(elem->argument, "|");
    }
    if (option == 'i') {
      flag->i = 1;
    }
    if (option == 'v') {
      flag->v = 1;
    }
    if (option == 'c') {
      flag->c = 1;
    }
    if (option == 'l') {
      flag->l = 1;
    }
    if (option == 'n') {
      flag->h = 1;
    }
    if (option == 's') {
      flag->s = 1;
    }
    if (option == 'f') {
      char temp_str[1000];
      FILE *f = fopen(optarg, "r");
      if (f == NULL) {
        fprintf(stderr, "grep: %s: no such file or directory foo\n", optarg);
        continue;
      }
      while (fgets(temp_str, 499, f) != NULL) {
        strcat(elem->argument, temp_str);
        if (elem->argument[strlen(elem->argument) - 1] != '\n') {
          strcat(elem->argument, "|");
        } else {
          elem->argument[strlen(elem->argument) - 1] = '|';
        }
      }
      fclose(f);
    }
    if (option == 'o') {
      flag->o = 1;
    }
    if (option == '?') {
      fprintf(stderr, "Unknown option: %c\n", option);
    }
  }
}

void hard_printing(char *argv[], grep_flag *flag, elem *elem) {
  FILE *f = fopen(argv[optind], "r");
  if (f == NULL) {
    if (flag->s != 1) {
      fprintf(stderr, "grep: %s: no such file or directory\n", argv[optind]);
    }
    return;
  }
  regex_t regex;
  int cflags = flag->i ? REG_EXTENDED | REG_ICASE : REG_EXTENDED;
  if (!regcomp(&regex, elem->argument, cflags)) {
    int res = 0;
    char argument[5000];
    elem->counter_n = 1;
    elem->counter_c = 0;
    while (fgets(argument, 4999, f) != NULL) {
      regmatch_t pmatch;
      res = regexec(&regex, argument, 1, &pmatch, 0);
      res ^= flag->v;
      if (!res) {
        elem->counter_c++;
        printer(argv, flag, elem, argument, pmatch);
      }
      elem->counter_n++;
    }

    if (flag->l && elem->counter_c > 0) {
      printf("%s\n", argv[optind]);
    }

    if (flag->c && !flag->l) {
      if (elem->file > 1 && !flag->h) printf("%s:", argv[optind]);
      { printf("%d\n", elem->counter_c); }
    }

    regfree(&regex);
  }
  fclose(f);
}

void printer(char *argv[], grep_flag *flag, elem *elem, char *str,
             regmatch_t pmatch) {
  if (flag->l || flag->c) {
    return;
  }
  if (elem->file > 1 && !flag->h) {
    printf("%s:", argv[optind]);
  }
  if (flag->n) printf("%d:", elem->counter_n);

  if (flag->o) {
    for (int i = pmatch.rm_so; i < pmatch.rm_eo; i++) printf("%c", str[i]);
    printf("\n");
  } else
    printf("%s", str);

  if (str[strlen(str) - 1] != '\n') {
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  grep_flag flag = {0};
  elem elem = {0};
  if (argc > 2) {
    parsing(argc, argv, &flag, &elem);
    if (flag.e != 1 && flag.f != 1) {
      strcat(elem.argument, argv[optind++]);
    }
    elem.file = argc - optind;
    for (; optind < argc; optind++) {
      hard_printing(argv, &flag, &elem);
    }
  } else {
    fprintf(stderr, "Insufficient data");
  }
  return 0;
}