#include "s21_string_test.h"

START_TEST(s21_strlen_1) {
  const char* str = "test_string";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_2) {
  const char* str = "test_string\n\n\n\t\t\t12345";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_3) {
  const char* str = "test_string\n\0\0\t\t\t12345";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_4) {
  const char* str = "\n";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_5) {
  const char* str = "\0";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_6) {
  const char* str = "--------";
  ck_assert_uint_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite* s21_strlen_suite(void) {
  Suite* s;

  TCase* s21_strlen_tcase;

  s = suite_create("s21_strlen_test");

  s21_strlen_tcase = tcase_create("s21_strlen_tcase");

  tcase_add_test(s21_strlen_tcase, s21_strlen_1);
  tcase_add_test(s21_strlen_tcase, s21_strlen_2);
  tcase_add_test(s21_strlen_tcase, s21_strlen_3);
  tcase_add_test(s21_strlen_tcase, s21_strlen_4);
  tcase_add_test(s21_strlen_tcase, s21_strlen_5);
  tcase_add_test(s21_strlen_tcase, s21_strlen_6);

  suite_add_tcase(s, s21_strlen_tcase);

  return s;
}
