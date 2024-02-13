#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *s1 = S21_NULL;
  s21_size_t size = s21_strlen(str);
  for (s21_size_t i = 0; i <= size; i++) {
    if (str[i] == c) {
      s1 = (char *)&str[i];
    }
  }
  return s1;
}