#include "../s21_string.h"

void* s21_memchr(const void* str, int c, s21_size_t n) {
  unsigned char* s1 = (unsigned char*)str;
  void* res = S21_NULL;

  for (s21_size_t i = 0; i < n && res == S21_NULL; i++, s1++) {
    if (*s1 == c) {
      res = s1;
    }
  }
  return res;
}