#include "../s21_string.h"

char* s21_strpbrk(const char* str1, const char* str2) {
  unsigned char* str = (unsigned char*)str1;
  unsigned char* collection = (unsigned char*)str2;

  int ascii_table[256] = {0};

  for (; *collection != '\0'; collection++) {
    ascii_table[*collection] = 1;
  }
  unsigned char* res = S21_NULL;

  for (; *str != '\0' && res == S21_NULL; str++) {
    if (ascii_table[*str]) {
      res = str;
    }
  }
  return (char*)res;
}
