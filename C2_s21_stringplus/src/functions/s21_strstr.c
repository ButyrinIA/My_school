#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t needle_length = s21_strlen(needle);
  int flag = 1;
  if (needle_length != 0) {
    flag = 0;
    s21_size_t haystack_len = s21_strlen(haystack);
    while (haystack_len-- >= needle_length) {
      if (!s21_memcmp(haystack, needle, needle_length)) {
        flag = 1;
        break;
      }
      haystack++;
    }
  }
  return flag ? (char *)haystack : S21_NULL;
}
