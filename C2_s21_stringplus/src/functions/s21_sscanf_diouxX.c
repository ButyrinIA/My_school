#include "../s21_string.h"

int s21_sscanf_diouxX(char *str, char *format, int width, va_list ptr,
                      sscanf_struct example, int *count_int_symbols) {
  int result = 0;
  int int_symbols = 0;
  long int value_int = 0;
  if ((*str == '-' ||
       (isdigit(*str) && (s21_strchr("diu", *format) != S21_NULL)) ||
       ((s21_strchr("01234567", *str) != S21_NULL) && (*format == 'o')) ||
       ((s21_strchr("0123456789ABCDEFabcdef", *str) != S21_NULL) &&
        (s21_strchr("xX", *format) != S21_NULL))) &&
      *str != '\0') {
    value_int = s21_atoi(str, &int_symbols, format, width);
    if ((!example.asterix) && s21_strchr("ouxX", *format) != S21_NULL) {
      if (example.flag_short == 1) {
        *(va_arg(ptr, unsigned short int *)) = value_int;
      } else if (example.flag_long == 1) {
        *(va_arg(ptr, unsigned long int *)) = value_int;
      } else {
        *(va_arg(ptr, unsigned int *)) = value_int;
      }
      result++;
    } else if (!example.asterix) {
      if (example.flag_short == 1) {
        *(va_arg(ptr, short int *)) = value_int;
      } else if (example.flag_long == 1) {
        *(va_arg(ptr, long int *)) = value_int;
      } else {
        *(va_arg(ptr, int *)) = value_int;
      }
      result++;
    }
    example.flag_long = example.flag_short = 0;
    *count_int_symbols += int_symbols;
  } else {
    example.flag_stop = 1;
  }
  return result;
}