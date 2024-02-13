#include "../s21_string.h"

int s21_sscanf_feEgG(char *str, int width, va_list ptr, sscanf_struct example,
                     int *count_int_symbols) {
  int result = 0;
  long double value_float = 0;
  int int_symbols = 0;
  if ((isdigit(*str) || *str == '-') && *str != '\0') {
    value_float = s21_atof(str, &int_symbols, width);
    if (!example.asterix) {
      if (example.flag_double == 1) {
        *(va_arg(ptr, long double *)) = value_float;
      } else {
        *(va_arg(ptr, float *)) = value_float;
      }
      result++;
    }
    example.flag_double = 0;
    *count_int_symbols += int_symbols;

  } else {
    example.flag_stop = 1;
  }
  return result;
}