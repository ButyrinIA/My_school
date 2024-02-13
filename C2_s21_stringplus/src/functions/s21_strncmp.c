#include "../s21_string.h"

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  unsigned char* s1 = (unsigned char*)str1;
  unsigned char* s2 = (unsigned char*)str2;

  while (n-- > 1 && (*s1 - *s2) == 0 && (*s1 != '\0' && *s2 != '\0')) {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}