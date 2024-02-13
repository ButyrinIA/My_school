#include <errno.h>

#include "s21_string_test.h"

START_TEST(s21_test_strerror_known_error) {
  const char* error_message = s21_strerror(3);
  const char* error_message2 = strerror(3);
  ck_assert_str_eq(error_message, error_message2);
}
END_TEST

START_TEST(s21_test_strerror_unknown_error) {
  const char* error_message = s21_strerror(9999);
  const char* error_message2 = strerror(9999);
  ck_assert_str_eq(error_message, error_message2);
}
END_TEST

START_TEST(s21_test_strerror_zero) {
  const char* error_message = s21_strerror(0);
  const char* error_message2 = strerror(0);
  ck_assert_str_eq(error_message, error_message2);
}
END_TEST

START_TEST(s21_test_strerror_negative_error) {
  const char* error_message = s21_strerror(-1);
  const char* error_message2 = strerror(-1);
  ck_assert_str_eq(error_message, error_message2);
}
END_TEST

Suite* s21_strerror_suite(void) {
  Suite* s;
  TCase* s21_strerror_tcase;
  s = suite_create("s21_strerror_suite");
  s21_strerror_tcase = tcase_create("s21_strerror_tcase");

  tcase_add_test(s21_strerror_tcase, s21_test_strerror_known_error);
  tcase_add_test(s21_strerror_tcase, s21_test_strerror_unknown_error);
  tcase_add_test(s21_strerror_tcase, s21_test_strerror_zero);
  tcase_add_test(s21_strerror_tcase, s21_test_strerror_negative_error);

  suite_add_tcase(s, s21_strerror_tcase);
  return s;
}
