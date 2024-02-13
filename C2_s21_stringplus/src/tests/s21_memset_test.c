#include "s21_string_test.h"

START_TEST(s21_test_memset_zero) {
  char str[] = "lalala";
  s21_memset(str, 0, (sizeof(str) - 1));
  ck_assert_str_eq(str, "\0\0\0\0\0");
}
END_TEST

START_TEST(s21_test_memset_value) {
  char str[] = "lalala";
  char str2[] = "lalala";
  s21_memset(str, '!', (sizeof(str) - 1));
  memset(str2, '!', (sizeof(str2) - 1));
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_test_memset_partial) {
  char str[] = "lalala";
  char str2[] = "lalala";
  s21_memset(str, '*', 3);
  memset(str2, '*', 3);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_test_memset_empty) {
  char str[] = "";
  s21_memset(str, 'A', (sizeof(str) - 1));
  ck_assert_str_eq(str, "");
}
END_TEST

START_TEST(s21_test_memset_negative) {
  int c = -5;
  char input_str1[] = "eveve";
  char input_str2[] = "eveve";
  s21_memset(input_str1, c, 3);
  memset(input_str2, c, 3);
  ck_assert_str_eq(input_str1, input_str2);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *s21_memset_tcase;
  s = suite_create("s21_memset_suite");
  s21_memset_tcase = tcase_create("s21_memset_tcase");

  tcase_add_test(s21_memset_tcase, s21_test_memset_zero);
  tcase_add_test(s21_memset_tcase, s21_test_memset_value);
  tcase_add_test(s21_memset_tcase, s21_test_memset_partial);
  tcase_add_test(s21_memset_tcase, s21_test_memset_negative);
  tcase_add_test(s21_memset_tcase, s21_test_memset_empty);

  suite_add_tcase(s, s21_memset_tcase);
  return s;
}
