#include <stdio.h>

#include "../s21_string.h"

void* s21_to_upper(const char* str) {
  if (str == S21_NULL) return S21_NULL;

  s21_size_t len = s21_strlen(str);
  char* res = (char*)calloc(len + 1, sizeof(char));

  for (s21_size_t i = 0; i <= len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      res[i] = str[i] - 32;
    else
      res[i] = str[i];
  }

  // res[len] = '\0';

  return res;
}

void* s21_to_lower(const char* str) {
  if (str == S21_NULL) return S21_NULL;

  s21_size_t len = s21_strlen(str);
  char* res = (char*)calloc(len + 1, sizeof(char));

  for (s21_size_t i = 0; i <= len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      res[i] = str[i] + 32;
    else
      res[i] = str[i];
  }

  // res[len] = '\0';

  return res;
}

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  s21_size_t result_len = src_len + str_len + 1;
  unsigned char* result_str = S21_NULL;

  if (start_index <= src_len && str != S21_NULL && src != S21_NULL) {
    result_str = (unsigned char*)calloc(result_len, sizeof(char));

    s21_size_t i = 0;

    for (; i < start_index; i++) result_str[i] = src[i];

    for (s21_size_t j = 0; j < str_len; j++, i++) result_str[i] = str[j];

    for (s21_size_t j = start_index; i < result_len; j++, i++)
      result_str[i] = src[j];
  }

  return result_str;
}

int s21_start_size(const char* src, const char* trim_chars) {
  int start_size = -1;
  for (int i = 0; src[i] != '\0' && start_size == -1; i++) {
    int match = 0;
    for (int j = 0; trim_chars[j] != '\0'; j++) {
      if (src[i] == trim_chars[j]) {
        match = 1;
      }
    }
    if (match != 1) {
      start_size = i;
    }
  }
  return start_size;
}

int s21_end_size(const char* src, const char* trim_chars) {
  int end_size = -1;
  int i = (int)s21_strlen(src) - 1;
  for (; i >= 0 && end_size == -1; i--) {
    int match = 0;
    for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
      if (src[i] == trim_chars[j]) {
        match = 1;
      }
    }
    if (match != 1) {
      end_size = i;
    }
  }
  return end_size;
}

void* s21_trim(const char* src, const char* trim_chars) {
  if (src == S21_NULL) return S21_NULL;
  char* res = S21_NULL;
  if (s21_strlen(trim_chars) == 0) {
    res = s21_trim(src, "\t \n");
  } else {
    int start = s21_start_size(src, trim_chars);
    int end = s21_end_size(src, trim_chars);

    if (end - start > 0) {
      res = (char*)calloc(end - start + 2, sizeof(char));
      for (int i = 0; start <= end; i++, start++) {
        res[i] = src[start];
      }
    } else if (end - start == 0) {
      res = (char*)calloc(2, sizeof(char));
    }
  }

  return (void*)res;
}