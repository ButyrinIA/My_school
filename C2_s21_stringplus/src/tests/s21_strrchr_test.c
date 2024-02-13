#include "s21_string_test.h"

START_TEST(s21_strrchr_1) {
  const char* str = "test_string";
  int c = '_';

  ck_assert_str_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_2) {
  const char* str = "test_stringl";
  int c = 'l';

  ck_assert_str_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_3) {
  const char* str = "test_string";
  int c = '\0';

  ck_assert_str_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_4) {
  const char* str = "\0\0\0\0\0";
  int c = '\0';

  ck_assert_str_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_null_1) {
  const char* str = "test_string";
  int c = '.';

  ck_assert_ptr_null(strrchr(str, c));
  ck_assert_ptr_null(s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_null_2) {
  const char* str = "\0\0\0\n";
  int c = '\n';

  ck_assert_ptr_null(strrchr(str, c));
  ck_assert_ptr_null(s21_strrchr(str, c));
}
END_TEST

Suite* s21_strrchr_suite(void) {
  Suite* s;

  TCase* s21_strrchr_tcase;

  s = suite_create("s21_strrchr_test");

  s21_strrchr_tcase = tcase_create("s21_strrchr_tcase");

  tcase_add_test(s21_strrchr_tcase, s21_strrchr_1);
  tcase_add_test(s21_strrchr_tcase, s21_strrchr_2);
  tcase_add_test(s21_strrchr_tcase, s21_strrchr_3);
  tcase_add_test(s21_strrchr_tcase, s21_strrchr_4);

  tcase_add_test(s21_strrchr_tcase, s21_strrchr_null_1);
  tcase_add_test(s21_strrchr_tcase, s21_strrchr_null_2);

  suite_add_tcase(s, s21_strrchr_tcase);

  return s;
}
