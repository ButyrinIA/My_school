#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n; i++, str1++, str2++) {
    if (*(unsigned char *)str1 != *(unsigned char *)str2) {
      result = *(unsigned char *)str1 - *(unsigned char *)str2;
      break;
    }
  }
  return result;
}
