#include "../s21_string.h"

char *s21_strerror(int errnum) {
  S21_ERRORS_ARRAY;
  static char res[100] = {0};
  char str_error[80] = UNKNOWN_ERROR;
  char errnum_str[50];
  s21_itoa(errnum, errnum_str, 10);
  if (errnum > ERR_MAX || errnum < 0) {
    s21_strncat(str_error, errnum_str, s21_strlen(errnum_str));
    s21_strncpy(res, str_error, s21_strlen(str_error));
  } else {
    s21_strncpy(res, errors_list[errnum], s21_strlen(errors_list[errnum]));
  }
  return res;
}
