#include "s21_string_test.h"

START_TEST(s21_test_strstr_found) {
  const char haystack[] = "Hello, World!";
  const char needle[] = "World";
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "World!");
}
END_TEST

START_TEST(s21_test_strstr_not_found) {
  const char haystack[] = "Hello, World!";
  const char needle[] = "Universe";
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(s21_test_strstr_empty_haystack) {
  const char haystack[] = "";
  const char needle[] = "World";
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(s21_test_strpbrk_end_in_between) {
  const char* src = "la\nla\0fgfg";
  const char* result1 = s21_strstr(src, "g");
  const char* result2 = strstr(src, "g");
  ck_assert_ptr_null(result1);
  ck_assert_ptr_null(result2);
}
END_TEST

START_TEST(s21_test_strpbrk_slach_in_between) {
  const char* src = "la\nlafgfg";
  const char* result1 = s21_strstr(src, "gfg");
  const char* result2 = strstr(src, "gfg");
  ck_assert_str_eq(result1, result2);
}
END_TEST

Suite* s21_strstr_suite(void) {
  Suite* s;
  TCase* s21_strstr_tcase;
  s = suite_create("s21_strstr_suite");
  s21_strstr_tcase = tcase_create("s21_strstr_tcase");

  tcase_add_test(s21_strstr_tcase, s21_test_strstr_found);
  tcase_add_test(s21_strstr_tcase, s21_test_strstr_not_found);
  tcase_add_test(s21_strstr_tcase, s21_test_strstr_empty_haystack);
  tcase_add_test(s21_strstr_tcase, s21_test_strpbrk_end_in_between);
  tcase_add_test(s21_strstr_tcase, s21_test_strpbrk_slach_in_between);

  suite_add_tcase(s, s21_strstr_tcase);
  return s;
}
