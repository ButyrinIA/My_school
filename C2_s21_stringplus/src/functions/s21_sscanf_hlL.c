#include "../s21_string.h"

int s21_sscanf_hlL(char *format, char *str, sscanf_struct *example, int *width,
                   int *str_move) {
  int count_int_symbols = 1;
  format++;
  int is_even = 1;
  while (*format == '%') {
    if (is_even % 2 == 0) {
      if (*str != '%') {
        example->flag_stop = 1;
        break;
      }
      *str_move = *str_move + 1;
    }
    format++;
    count_int_symbols++;
    is_even++;
  }
  if (isdigit(*format)) {
    int buf = 0;
    *width = s21_atoi(format, &buf, "d", s21_strlen(format));
    count_int_symbols += buf;
    while (buf--) {
      format++;
    }
  }
  if (s21_strchr("hlL*", *format) != S21_NULL) {
    if (*format == 'h') {
      example->flag_short = 1;
    } else if (*format == 'l') {
      example->flag_long = 1;
    } else if (*format == 'L') {
      example->flag_double = 1;
    } else if (*format == '*') {
      example->asterix = 1;
    }
    format++;
    count_int_symbols++;
  }

  return count_int_symbols;
}