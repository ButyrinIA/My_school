#include "../s21_string.h"

long int s21_atoi(char *str, int *counter, char *format, int limit) {
  int sign = 1;
  int base = 10;
  long int res = 0;
  int buf = 0;
  int flag_stop = 0;
  int flag_eight = 0;
  int flag_sixteen = 0;
  if (*str == '-') {
    str++;
    buf++;
    sign = 0;
  }
  if ((s21_strchr("oxX", *format) != S21_NULL)) {
    base = 8;
    flag_eight = 1;
    if ((*format == 'x' || *format == 'X')) {
      base = 16;
      flag_sixteen = 1;
      flag_eight = 0;
    } else if (s21_strchr("01234567", *str) == S21_NULL) {
      flag_stop = 1;
    }
  }
  if (!flag_stop) {
    if (flag_sixteen && (s21_strchr("ABCDEFabcdef", *str) != S21_NULL)) {
      res += (toupper(*str) - '7');
    } else {
      res += (*str - '0');
    }
    str++;
    buf++;
    while (((isdigit(*str) &&
             (*format == 'd' || *format == 'u' || *format == 'i')) ||
            ((s21_strchr("01234567", *str) != S21_NULL) && flag_eight) ||
            (flag_sixteen &&
             (s21_strchr("0123456789ABCDEFabcdef", *str) != S21_NULL))) &&
           buf < limit) {
      res *= base;
      if (flag_sixteen && (s21_strchr("ABCDEFabcdef", *str) != S21_NULL)) {
        res += (toupper(*str) - '7');
      } else {
        res += (*str - '0');
      }
      str++;
      buf++;
    }
    *counter = buf;
  }
  return sign ? res : -res;
}