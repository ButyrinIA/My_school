#include "s21_string_test.h"

START_TEST(s21_strncmp_eq_1) {
  char str[30] = "pamparam tutturu";
  char str2[30] = "pamparam tutturu";

  s21_size_t len = 30;

  ck_assert_int_eq(s21_strncmp(str, str2, len), strncmp(str, str2, len));
}
END_TEST

START_TEST(s21_strncmp_eq_2) {
  char str[30] = "par tutturu";
  char str2[30] = "tar tutturu";

  s21_size_t len = 2;

  ck_assert_int_eq(s21_strncmp(str, str2, len), strncmp(str, str2, len));
}
END_TEST

START_TEST(s21_strncmp_eq_3) {
  char str[30] = "\t";
  char str2[30] = "\n";

  s21_size_t len = 1;

  ck_assert_int_eq(s21_strncmp(str, str2, len), strncmp(str, str2, len));
}
END_TEST

START_TEST(s21_strncmp_eq_4) {
  char* str = "HELLO EVERYONE";
  char* str2 = "HELLOEVERYONE";

  s21_size_t len = 15;

  ck_assert_int_eq(s21_strncmp(str, str2, len), strncmp(str, str2, len));
}
END_TEST

START_TEST(s21_strncmp_eq_5) {
  char* str = "\0\0\0";
  char* str2 = "\0\0\0";

  s21_size_t len = 3;

  ck_assert_int_eq(s21_strncmp(str, str2, len), strncmp(str, str2, len));
}
END_TEST

START_TEST(s21_strncmp_eq_6) {
  char* str = "test_string";
  char* str2 = "test_string";

  s21_size_t len = 0;
  ck_assert_int_eq(s21_strncmp(str, str2, len), strncmp(str, str2, len));
}
END_TEST

Suite* s21_strncmp_suite(void) {
  Suite* s;

  TCase* s21_strncmp_tcase;

  s = suite_create("s21_strncmp_test");

  s21_strncmp_tcase = tcase_create("s21_strncmp_tcase");

  tcase_add_test(s21_strncmp_tcase, s21_strncmp_eq_1);
  tcase_add_test(s21_strncmp_tcase, s21_strncmp_eq_2);
  tcase_add_test(s21_strncmp_tcase, s21_strncmp_eq_3);
  tcase_add_test(s21_strncmp_tcase, s21_strncmp_eq_4);
  tcase_add_test(s21_strncmp_tcase, s21_strncmp_eq_5);
  tcase_add_test(s21_strncmp_tcase, s21_strncmp_eq_6);

  suite_add_tcase(s, s21_strncmp_tcase);

  return s;
}
