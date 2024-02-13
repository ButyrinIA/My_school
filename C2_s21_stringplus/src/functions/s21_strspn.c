#include "../s21_string.h"

s21_size_t s21_strspn(const char* str1, const char* str2) {
  unsigned char* s1 = (unsigned char*)str1;
  unsigned char* s2 = (unsigned char*)str2;

  int ascii_table[256] = {0};
  while (*s2 != '\0') {
    ascii_table[*s2] = 1;
    s2++;
  }

  s21_size_t length = 0;
  while (ascii_table[*s1] && *s1 != '\0') {
    length++;
    s1++;
  }
  return length;
}