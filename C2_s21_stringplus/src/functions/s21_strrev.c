#include "../s21_string.h"

char* s21_strrev(char* str) {
  s21_size_t size = s21_strlen(str);
  for (s21_size_t i = 0; i < size / 2; i++) {
    int temp = str[size - 1 - i];
    str[size - 1 - i] = str[i];
    str[i] = temp;
  }
  return str;
}