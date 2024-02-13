#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *res = dest;
  for (s21_size_t i = 0; i < n; i++, dest++, src++) {
    *dest = *(char *)src;
  }
  return res;
}
