#include "s21_string_test.h"

START_TEST(s21_memcpy_eq_1) {
  char str[30] = "pamparam tutturu";
  char str2[30] = "pamparam tutturu";
  const char ch[4] = "tot";
  s21_size_t len = s21_strlen(ch);

  s21_memcpy(str, ch, len);
  memcpy(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_memcpy_eq_2) {
  char str[20] = "pamparam tutturu";
  char str2[20] = "pamparam tutturu";
  const char* ch = "S21_NULL";
  s21_size_t len = s21_strlen(ch);

  s21_memcpy(str, ch, len);
  memcpy(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_memcpy_eq_3) {
  char str[20] = "omg";
  char str2[20] = "omg";
  const char* ch = "S21_NULL";
  s21_size_t len = s21_strlen(ch);

  s21_memcpy(str, ch, len);
  memcpy(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_memcpy_eq_4) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "hello everyone";
  s21_size_t len = s21_strlen(ch);

  s21_memcpy(str, ch, len);
  memcpy(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_memcpy_eq_5) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "\0\0\0\0\0\n";
  s21_size_t len = s21_strlen(ch);

  s21_memcpy(str, ch, len);
  memcpy(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_memcpy_eq_6) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "\0\0\0\0\0\n";
  s21_size_t len = s21_strlen(ch);

  s21_memcpy(str, ch, len);
  memcpy(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_memcpy_eq_7) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "-12-3-13149453\n";
  s21_size_t len = s21_strlen(ch);

  s21_memcpy(str, ch, len);
  memcpy(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_memcpy_eq_8) {
  char str[20] = {0};
  char str2[20] = {0};
  const char* ch = "\t\t\t\t\t\\\n";
  s21_size_t len = s21_strlen(ch);

  s21_memcpy(str, ch, len);
  memcpy(str2, ch, len);

  ck_assert_str_eq(str, str2);
}
END_TEST

Suite* s21_memcpy_suite(void) {
  Suite* s;

  TCase* s21_memcpy_tcase;

  s = suite_create("s21_memcpy_test");

  s21_memcpy_tcase = tcase_create("s21_memcpy_tcase");

  tcase_add_test(s21_memcpy_tcase, s21_memcpy_eq_1);
  tcase_add_test(s21_memcpy_tcase, s21_memcpy_eq_2);
  tcase_add_test(s21_memcpy_tcase, s21_memcpy_eq_3);
  tcase_add_test(s21_memcpy_tcase, s21_memcpy_eq_4);
  tcase_add_test(s21_memcpy_tcase, s21_memcpy_eq_5);
  tcase_add_test(s21_memcpy_tcase, s21_memcpy_eq_6);
  tcase_add_test(s21_memcpy_tcase, s21_memcpy_eq_7);
  tcase_add_test(s21_memcpy_tcase, s21_memcpy_eq_8);

  suite_add_tcase(s, s21_memcpy_tcase);

  return s;
}
