#include "s21_string_test.h"

START_TEST(s21_test_strpbrk_found) {
  const char str[] = "lalala pam";
  const char* result = s21_strpbrk(str, "am");
  ck_assert_ptr_nonnull(result);
  ck_assert_int_eq(*result, 'a');
}
END_TEST

START_TEST(s21_test_strpbrk_not_found) {
  const char str[] = "lalala";
  const char* result = s21_strpbrk(str, "mcwv");
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(s21_test_strpbrk_end_in_between) {
  const char* src = "la\nla\0fgfg";
  const char* result1 = s21_strpbrk(src, "g");
  const char* result2 = strpbrk(src, "g");
  ck_assert_ptr_null(result1);
  ck_assert_ptr_null(result2);
}
END_TEST

START_TEST(s21_test_strpbrk_slach_in_between) {
  const char* src = "la\nlafgfg";
  const char* result1 = s21_strpbrk(src, "g");
  const char* result2 = strpbrk(src, "g");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_test_strpbrk_empty_str) {
  const char str[] = "";
  const char* result = s21_strpbrk(str, "H");
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(s21_test_strpbrk_empty_chars) {
  const char str1[] = "lalala";
  const char str2[] = "lalala";
  const char* result1 = s21_strpbrk(str1, "");
  const char* result2 = strpbrk(str2, "");
  ck_assert_ptr_null(result1);
  ck_assert_ptr_null(result2);
}
END_TEST

Suite* s21_strpbrk_suite(void) {
  Suite* s;
  TCase* s21_strpbrk_tcase;
  s = suite_create("s21_strpbrk_suite");
  s21_strpbrk_tcase = tcase_create("s21_strpbrk_tcase");

  tcase_add_test(s21_strpbrk_tcase, s21_test_strpbrk_found);
  tcase_add_test(s21_strpbrk_tcase, s21_test_strpbrk_not_found);
  tcase_add_test(s21_strpbrk_tcase, s21_test_strpbrk_end_in_between);
  tcase_add_test(s21_strpbrk_tcase, s21_test_strpbrk_empty_str);
  tcase_add_test(s21_strpbrk_tcase, s21_test_strpbrk_empty_chars);
  tcase_add_test(s21_strpbrk_tcase, s21_test_strpbrk_slach_in_between);

  suite_add_tcase(s, s21_strpbrk_tcase);
  return s;
}
