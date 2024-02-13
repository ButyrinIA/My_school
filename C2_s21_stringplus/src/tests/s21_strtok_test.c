#include "s21_string_test.h"

START_TEST(s21_strtok_eq_1) {
  char str[30] = "pamparam tutturu";
  char str2[30] = "pamparam tutturu";

  ck_assert_ptr_null(strtok(str, str2));
  ck_assert_ptr_null(s21_strtok(str, str2));
}
END_TEST

START_TEST(s21_strtok_eq_2) {
  char str[30] = "par tutturu";
  char str2[30] = "tar tutturu";

  ck_assert_str_eq(s21_strtok(str, str2), strtok(str, str2));
}
END_TEST

START_TEST(s21_strtok_eq_3) {
  char str[30] = "\t";
  char str2[30] = "\n";

  ck_assert_str_eq(s21_strtok(str, str2), strtok(str, str2));
}
END_TEST

START_TEST(s21_strtok_eq_4) {
  char str[100] = "https::www.yandex.ru\\?href=:ura";
  char str2[100] = "https::www.yandex.ru\\?href=:ura";

  char* delim = " .,\\:";

  char* res_1 = strtok(str, delim);
  char* res_2 = s21_strtok(str2, delim);

  while (res_1 != S21_NULL && res_2 != S21_NULL) {
    ck_assert_str_eq(res_1, res_2);
    ck_assert_str_eq(str, str2);
    res_1 = strtok(S21_NULL, delim);
    res_2 = s21_strtok(S21_NULL, delim);
  }
  ck_assert_ptr_null(res_1);
  ck_assert_ptr_null(res_2);

  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(s21_strtok_eq_5) {
  char* str = "\0\0\0";
  char* str2 = "\0\0\0";

  ck_assert_ptr_null(strtok(str, str2));
  ck_assert_ptr_null(s21_strtok(str, str2));
}
END_TEST

START_TEST(s21_strtok_eq_6) {
  char str[100] = "lol.lol,lol:lol-lol?lol\\lol";
  char* str2 = "\\";

  ck_assert_str_eq(strtok(str, str2), s21_strtok(str, str2));
}
END_TEST

Suite* s21_strtok_suite(void) {
  Suite* s;

  TCase* s21_strtok_tcase;

  s = suite_create("s21_strtok_test");

  s21_strtok_tcase = tcase_create("s21_strtok_tcase");

  tcase_add_test(s21_strtok_tcase, s21_strtok_eq_1);
  tcase_add_test(s21_strtok_tcase, s21_strtok_eq_2);
  tcase_add_test(s21_strtok_tcase, s21_strtok_eq_3);
  tcase_add_test(s21_strtok_tcase, s21_strtok_eq_4);
  tcase_add_test(s21_strtok_tcase, s21_strtok_eq_5);
  tcase_add_test(s21_strtok_tcase, s21_strtok_eq_6);

  suite_add_tcase(s, s21_strtok_tcase);

  return s;
}
