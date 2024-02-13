#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  s21_size_t len = s21_strlen(str);
  int flag = 1;
  for (s21_size_t i = 0; i <= len && flag; i++) {
    if (str[i] == (char)c) {
      res = (char *)&str[i];
      flag = 0;
    }
  }
  return res;
}