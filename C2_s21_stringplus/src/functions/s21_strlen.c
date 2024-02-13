#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  if (str == S21_NULL) return 0;
  s21_size_t len = 0;
  while (*str != '\0') {
    str++;
    len++;
  }
  return len;
}
