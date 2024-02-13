#include "../s21_string.h"

int s21_sscanf_spec_s(char *str, int width, va_list ptr, sscanf_struct example,
                      int *count_int_symbols) {
  int result = 0;
  char *str_ptr = S21_NULL;
  if (!example.asterix) {
    str_ptr = va_arg(ptr, char *);
    result++;
  } else {
    char buf[1000] = "";
    str_ptr = buf;
  }
  while (((*str != '\n') && (*str != '\0') && (*str != ' ')) && (width > 0)) {
    *str_ptr = *str;
    str++;
    str_ptr++;
    width--;
    *count_int_symbols = *count_int_symbols + 1;
    if (*str == '\0') {
      *str_ptr = '\0';
      break;
    }
  }
  return result;
}