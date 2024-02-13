#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *buffer = S21_NULL;
  if (str) buffer = str;

  if (buffer) {
    str = buffer + s21_strspn(buffer, delim);
    buffer = str + s21_strcspn(str, delim);
    if (*buffer != '\0') {
      *buffer = '\0';
      buffer++;
    }
  }

  return *str != '\0' ? str : S21_NULL;
}
