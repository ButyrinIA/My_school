#include "s21_string_test.h"

START_TEST(s21_test_memcmp_equal) {
  const char str1[] = "lalala";
  const char str2[] = "lalala";
  int result = s21_memcmp(str1, str2, sizeof(str1));
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_test_memcmp_different) {
  const char str1[] = "lalala";
  const char str2[] = "pamparam";
  int result = s21_memcmp(str1, str2, sizeof(str1));
  ck_assert_int_ne(result, 0);
}
END_TEST

START_TEST(s21_test_memcmp_partial_match) {
  const char str1[] = "lalala";
  const char str2[] = "pamlalapam";
  const char str3[] = "lalala";
  const char str4[] = "pamlalapam";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str3, str4, 6));
}
END_TEST

START_TEST(s21_test_memcmp_different_lengths) {
  const char str1[] = "lalala";
  const char str2[] = "lalala ";
  int result = s21_memcmp(str1, str2, sizeof(str1));
  ck_assert_int_ne(result, 0);
}
END_TEST

START_TEST(s21_test_memcmp_null_str2) {
  const char str1[] = "lalala";
  int result = s21_memcmp(str1, "", sizeof(str1));
  int result2 = memcmp(str1, "", s21_strlen((char *)str1));
  ck_assert_int_eq(result, result2);
}
END_TEST

START_TEST(s21_test_memcmp_null_str1) {
  const char str1[] = {0};
  const char str2[] = "lalala ";
  int result1 = s21_memcmp(str1, str2, sizeof(str2));
  int result2 = memcmp(str1, str2, s21_strlen((char *)str2));
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(s21_test_memcmp_null_empty) {
  const char str1[] = "rvrvrvr";
  const char str2[] = "";
  int result1 = s21_memcmp(str1, str2, sizeof(str2));
  int result2 = memcmp(str1, str2, sizeof(str2));
  ck_assert_int_eq(result1, result2);
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s;
  TCase *s21_memcmp_tcase;
  s = suite_create("s21_memcmp_suite");
  s21_memcmp_tcase = tcase_create("s21_memcmp_tcase");

  tcase_add_test(s21_memcmp_tcase, s21_test_memcmp_equal);
  tcase_add_test(s21_memcmp_tcase, s21_test_memcmp_different);
  tcase_add_test(s21_memcmp_tcase, s21_test_memcmp_partial_match);
  tcase_add_test(s21_memcmp_tcase, s21_test_memcmp_different_lengths);
  tcase_add_test(s21_memcmp_tcase, s21_test_memcmp_null_str2);
  tcase_add_test(s21_memcmp_tcase, s21_test_memcmp_null_str1);
  tcase_add_test(s21_memcmp_tcase, s21_test_memcmp_null_empty);

  suite_add_tcase(s, s21_memcmp_tcase);
  return s;
}
