#include "s21_string_test.h"

START_TEST(s21_test_strchr_found) {
  const char str[] = "lalala pa";
  char* result = s21_strchr(str, 'p');
  ck_assert_ptr_nonnull(result);
  ck_assert_int_eq(*result, 'p');
}
END_TEST

START_TEST(s21_test_strchr_not_found) {
  const char str[] = "lampa";
  char* result = s21_strchr(str, 'b');
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(s21_test_strchr_empty_negative) {
  const char* str = "";
  char* result1 = s21_strchr(str, '-');
  char* result2 = strchr(str, '-');
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(s21_test_strchr_empty) {
  const char str[] = "";
  char* result = s21_strchr(str, 'l');
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(s21_test_strchr_last_character) {
  const char str[] = "lalala m";
  char* result = s21_strchr(str, 'm');
  ck_assert_int_eq(*result, 'm');
}
END_TEST

Suite* s21_strchr_suite(void) {
  Suite* s;
  TCase* s21_strchr_tcase;
  s = suite_create("s21_strchr_suite");
  s21_strchr_tcase = tcase_create("s21_strchr_tcase");

  tcase_add_test(s21_strchr_tcase, s21_test_strchr_found);
  tcase_add_test(s21_strchr_tcase, s21_test_strchr_not_found);
  tcase_add_test(s21_strchr_tcase, s21_test_strchr_empty_negative);
  tcase_add_test(s21_strchr_tcase, s21_test_strchr_empty);
  tcase_add_test(s21_strchr_tcase, s21_test_strchr_last_character);

  suite_add_tcase(s, s21_strchr_tcase);
  return s;
}
