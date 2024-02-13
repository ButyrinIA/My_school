#include <math.h>

#include "../s21_string.h"

long double s21_atof(char *str, int *counter, int limit) {
  int sign = 1;
  int base = 10;
  float res = 0.0;
  float float_res = 0.0;
  int buf = 0;
  int buf2 = 0;
  int float_counter = 0;
  int flag_stop = 0;
  int pow_rate = 0;
  if (*str == '-') {
    str++;
    buf++;
    sign = 0;
  }
  if (!flag_stop) {
    res = *str - '0';
    str++;
    buf++;
    while (isdigit(*str) && (buf <= limit)) {
      res *= base;
      res += (*str - '0');
      str++;
      buf++;
    }
    if ((*str == '.') && (buf <= limit)) {
      str++;
      float_counter++;
      float_res = *str - '0';
      str++;
      while (isdigit(*str) && ((buf + float_counter) < limit)) {
        float_res *= base;
        float_res += (*str - '0');
        str++;
        float_counter++;
      }
      float_res = float_res / pow(10, float_counter);
    }
    res += float_res;
    if (!s21_memcmp(str, "e+", 2) || !s21_memcmp(str, "E+", 2)) {
      str += 2;
      pow_rate = s21_atoi(str, &buf2, "d", s21_strlen(str));
      buf2 += 2;
    }
    res *= pow(10, pow_rate);
    *counter = buf + float_counter + buf2 + 1;
  }

  return sign ? res : -res;
}