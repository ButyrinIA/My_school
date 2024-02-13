#include "../s21_string.h"

int s21_sscanf_specificator(char *format, char *str, const char *init_str,
                            sscanf_struct example, int *match, va_list ptr,
                            int width) {
  int count_int_symbols = 0;
  if (*format == 'c') {
    if (!example.asterix) {
      int *ptr_ch = va_arg(ptr, int *);
      *ptr_ch = *str;
      if (*str != 0) *match = *match + 1;
    }
    count_int_symbols++;
  } else if (s21_strchr("diouxX", *format) != S21_NULL) {
    *match +=
        s21_sscanf_diouxX(str, format, width, ptr, example, &count_int_symbols);
  } else if (s21_strchr("feEgG", *format) != S21_NULL) {
    *match += s21_sscanf_feEgG(str, width, ptr, example, &count_int_symbols);
  } else if (*format == 's') {
    *match += s21_sscanf_spec_s(str, width, ptr, example, &count_int_symbols);
  } else if (*format == 'p' && !example.asterix) {
    void **ptr_ptr = S21_NULL;
    ptr_ptr = va_arg(ptr, void **);
    *ptr_ptr = &ptr_ptr;
    *match = *match + 1;
  } else if (*format == 'n' && !example.asterix) {
    int *counter_ptr = NULL;
    counter_ptr = va_arg(ptr, int *);
    *counter_ptr = str - init_str;
  }
  return count_int_symbols;
}
