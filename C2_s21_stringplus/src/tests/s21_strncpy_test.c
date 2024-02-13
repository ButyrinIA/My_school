#include "s21_string_test.h"

START_TEST(s21_test_strncpy_regular) {
  char dest[10];
  const char* src = "lalala";
  s21_strncpy(dest, src, sizeof(dest) - 1);
  dest[sizeof(dest) - 1] = '\0';
  ck_assert_str_eq(dest, "lalala");
}
END_TEST

START_TEST(s21_test_strncpy_partial) {
  char dest[10];
  const char* src = "lalala";
  s21_strncpy(dest, src, 3);
  dest[3] = '\0';
  ck_assert_str_eq(dest, "lal");
}
END_TEST

START_TEST(s21_test_strncpy_without_last_symbol) {
  char dest[10];
  char dest2[10];
  const char* src = "lalala";
  s21_strncpy(dest, src, sizeof(dest));
  strncpy(dest2, src, sizeof(dest2));
  ck_assert_str_eq(dest, dest2);
}
END_TEST

START_TEST(s21_est_strncpy_empty_src) {
  char dest[10];
  const char* src = "";
  s21_strncpy(dest, src, sizeof(dest));
  ck_assert_str_eq(dest, "");
}
END_TEST

START_TEST(s21_test_strncpy_end_in_between) {
  char dest[10];
  char dest2[10];
  const char* src = "la\nla\0fgfg";
  s21_strncpy(dest, src, sizeof(dest));
  strncpy(dest2, src, sizeof(dest2));
  ck_assert_str_eq(dest, dest2);
}
END_TEST

Suite* s21_strncpy_suite(void) {
  Suite* s;
  TCase* s21_strncpy_tcase;
  s = suite_create("s21_strncpy_suite");
  s21_strncpy_tcase = tcase_create("s21_strncpy_tcase");

  tcase_add_test(s21_strncpy_tcase, s21_test_strncpy_regular);
  tcase_add_test(s21_strncpy_tcase, s21_test_strncpy_partial);
  tcase_add_test(s21_strncpy_tcase, s21_test_strncpy_without_last_symbol);
  tcase_add_test(s21_strncpy_tcase, s21_est_strncpy_empty_src);
  tcase_add_test(s21_strncpy_tcase, s21_test_strncpy_end_in_between);

  suite_add_tcase(s, s21_strncpy_tcase);
  return s;
}
