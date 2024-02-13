#include <check.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

#ifndef S21_STRING_TEST_H
#define S21_STRING_TEST_H

Suite *s21_strlen_suite(void);
Suite *s21_memchr_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strtok_suite(void);
Suite *s21_sprintf_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_sscanf_suite(void);
Suite *s21_sharp_suite(void);

void s21_test_one_suite(Suite *current_suit, int *sum_of_errors);

#endif
