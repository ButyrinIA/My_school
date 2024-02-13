#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  while (n--) {
    *ptr = (unsigned char)c;
    ptr++;
  }
  return str;
}