#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *s1 = (unsigned char *)dest;
  unsigned char *s2 = (unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++, s1++, s2++) {
    *s1 = *s2;
  }

  return dest;
}