#include "s21_string_test.h"

START_TEST(s21_strncat_eq_1) {
  char str[30] = "pamparam tutturu";
  char str2[30] = "pamparam tutturu";
  const char ch[4] = "tot";
  s21_size_t len = 30;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strncat_eq_2) {
  char str[29] = "pamparam tutturu";
  char str2[29] = "pamparam tutturu";
  const char* ch = "S21_NULL";
  s21_size_t len = 10;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strncat_eq_3) {
  char str[20] = "omg";
  char str2[20] = "omg";
  const char* ch = "S21_NULL";
  s21_size_t len = 10;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strncat_eq_4) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "hello everyone";
  s21_size_t len = 12;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strncat_eq_5) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "\0\0\0\0\0\n";
  s21_size_t len = 12;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strncat_eq_6) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "\0\0\0\0\0\n";
  s21_size_t len = 1;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strncat_eq_7) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "-12-3-13149453\n";
  s21_size_t len = 20;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strncat_eq_8) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "\t\t\t\t\t\\\n";
  s21_size_t len = 20;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strncat_eq_9) {
  char str[10] = "\0";
  char str2[10] = "\0";
  const char* ch = "\0";
  s21_size_t len = 3;

  s21_strncat(str, ch, len);
  strncat(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

Suite* s21_strncat_suite(void) {
  Suite* s;

  TCase* s21_strncat_tcase;

  s = suite_create("s21_strncat_test");

  s21_strncat_tcase = tcase_create("s21_strncat_tcase");

  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_1);
  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_2);
  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_3);
  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_4);
  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_5);
  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_6);
  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_7);
  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_8);
  tcase_add_test(s21_strncat_tcase, s21_strncat_eq_9);

  suite_add_tcase(s, s21_strncat_tcase);

  return s;
}
