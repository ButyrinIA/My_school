#include "s21_string_test.h"

START_TEST(s21_strcspn_eq_1) {
  const char* str = "test1";
  const char* str2 = "123";

  ck_assert_uint_eq(s21_strcspn(str, str2), strcspn(str, str2));
}
END_TEST

START_TEST(s21_strcspn_eq_2) {
  const char* str = "hello world";
  const char* str2 = "wolrd";

  ck_assert_uint_eq(s21_strcspn(str, str2), strcspn(str, str2));
}
END_TEST

START_TEST(s21_strcspn_eq_3) {
  const char* str = "\t\t\t\n";
  const char* str2 = "\n";

  ck_assert_uint_eq(s21_strcspn(str, str2), strcspn(str, str2));
}
END_TEST

START_TEST(s21_strcspn_eq_4) {
  const char* str = "\n\n\n\n";
  const char* str2 = "\t";

  ck_assert_uint_eq(s21_strcspn(str, str2), strcspn(str, str2));
}
END_TEST

START_TEST(s21_strcspn_eq_5) {
  const char* str = "so bad";
  const char* str2 = "so";

  ck_assert_uint_eq(s21_strcspn(str, str2), strcspn(str, str2));
}
END_TEST

START_TEST(s21_strcspn_eq_6) {
  const char* str = "1234567890";
  const char* str2 = "abcdefgh0";

  ck_assert_uint_eq(s21_strcspn(str, str2), strcspn(str, str2));
}
END_TEST

START_TEST(s21_strcspn_eq_7) {
  const char* str = "\0";
  const char* str2 = "gggg";

  ck_assert_uint_eq(s21_strcspn(str, str2), strcspn(str, str2));
}
END_TEST

START_TEST(s21_strcspn_eq_8) {
  const char* str = "\0\n";
  const char* str2 = "\n";

  ck_assert_uint_eq(s21_strcspn(str, str2), strcspn(str, str2));
}
END_TEST

Suite* s21_strcspn_suite(void) {
  Suite* s;

  TCase* s21_strcspn_tcase;

  s = suite_create("s21_strcspn_test");

  s21_strcspn_tcase = tcase_create("s21_strcspn_tcase");

  tcase_add_test(s21_strcspn_tcase, s21_strcspn_eq_1);
  tcase_add_test(s21_strcspn_tcase, s21_strcspn_eq_2);
  tcase_add_test(s21_strcspn_tcase, s21_strcspn_eq_3);
  tcase_add_test(s21_strcspn_tcase, s21_strcspn_eq_4);
  tcase_add_test(s21_strcspn_tcase, s21_strcspn_eq_5);
  tcase_add_test(s21_strcspn_tcase, s21_strcspn_eq_6);
  tcase_add_test(s21_strcspn_tcase, s21_strcspn_eq_7);
  tcase_add_test(s21_strcspn_tcase, s21_strcspn_eq_8);

  suite_add_tcase(s, s21_strcspn_tcase);

  return s;
}
