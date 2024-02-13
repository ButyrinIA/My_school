#include "s21_string_test.h"

START_TEST(s21_sharp_eq_1) {
  char input[] = "";
  char tru_result[] = "";
  char* result = s21_to_upper(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_2) {
  char input[] = "\0";
  char tru_result[] = "\0";

  char* result = s21_to_upper(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_3) {
  char input[] = " \0";
  char tru_result[] = " \0";
  char* result = s21_to_upper(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_4) {
  char input[] = "f*ck the verter 01";
  char tru_result[] = "F*CK THE VERTER 01";
  char* result = s21_to_upper(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST
START_TEST(s21_sharp_eq_5) {
  char input[] = "Me AnD vErTeR -> 69";
  char tru_result[] = "ME AND VERTER -> 69";
  char* result = s21_to_upper(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_6) {
  char input[] = "";
  char tru_result[] = "";
  char* result = s21_to_lower(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST
START_TEST(s21_sharp_eq_7) {
  char input[] = "\0";
  char tru_result[] = "\0";
  char* result = s21_to_lower(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_8) {
  char input[] = " \0";
  char tru_result[] = " \0";
  char* result = s21_to_lower(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_9) {
  char input[] = "F*CK THE VERTER 01";
  char tru_result[] = "f*ck the verter 01";
  char* result = s21_to_lower(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_10) {
  char input[] = "Me AnD vErTeR -> 69";
  char tru_result[] = "me and verter -> 69";
  char* result = s21_to_lower(input);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_11) {
  char src[] = "Hello";
  char str[] = "_wtf?_";
  s21_size_t start_index = -1;

  char* tru_result = S21_NULL;
  char* result = s21_insert(src, str, start_index);

  ck_assert_pstr_eq(tru_result, result);
  if (result != S21_NULL) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_12) {
  char src[] = "Hello";
  char str[] = "_wtf?_";
  s21_size_t start_index = 0;

  char tru_result[] = "_wtf?_Hello";
  char* result = s21_insert(src, str, start_index);

  ck_assert_str_eq(tru_result, result);
  if (result != S21_NULL) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_13) {
  char src[] = "Hello";
  char str[] = "_wtf?_";
  s21_size_t start_index = 3;

  char tru_result[] = "Hel_wtf?_lo";
  char* result = s21_insert(src, str, start_index);

  ck_assert_str_eq(tru_result, result);
  if (result != S21_NULL) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_14) {
  char src[] = "Hello";
  char str[] = "_wtf?_";
  s21_size_t start_index = 5;

  char tru_result[] = "Hello_wtf?_";
  char* result = s21_insert(src, str, start_index);

  ck_assert_str_eq(tru_result, result);
  if (result != S21_NULL) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_15) {
  char src[] = "Hello";
  char str[] = "_wtf?_";
  s21_size_t start_index = 10;

  char* tru_result = S21_NULL;
  char* result = s21_insert(src, str, start_index);

  ck_assert_pstr_eq(tru_result, result);
  if (result != S21_NULL) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_16) {
  char str[] = "aaIIIaaIIIoaa";
  char trim_char[] = "baakao";

  char tru_result[] = "IIIaaIII";
  char* result = s21_trim(str, trim_char);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_17) {
  char str[] = "aaIIIaaIIIoaa";
  char trim_char[] = "";

  char tru_result[] = "aaIIIaaIIIoaa";
  char* result = s21_trim(str, trim_char);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_18) {
  char str[] = "   aaIIIa aIIIoaa      ";
  char trim_char[] = "";

  char tru_result[] = "aaIIIa aIIIoaa";
  char* result = s21_trim(str, trim_char);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_19) {
  char str[] = "   aaIIIa aIIIoaa      ";
  char* trim_char = S21_NULL;

  char tru_result[] = "aaIIIa aIIIoaa";
  char* result = s21_trim(str, trim_char);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_20) {
  char str[] = "";
  char trim_char[] = "abc";

  char tru_result[] = "";
  char* result = s21_trim(str, trim_char);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_21) {
  char str[] = "\0";
  char trim_char[] = "";

  char tru_result[] = "";
  char* result = s21_trim(str, trim_char);

  ck_assert_str_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_sharp_eq_22) {
  char str[] = "Hi";
  char trim_char[] = "Hi";

  char* tru_result = "";
  char* result = s21_trim(str, trim_char);

  ck_assert_pstr_eq(tru_result, result);
  if (result) free(result);
}
END_TEST

Suite* s21_sharp_suite(void) {
  Suite* s;

  TCase* s21_sharp_tcase;

  s = suite_create("s21_sharp_test");

  s21_sharp_tcase = tcase_create("s21_sharp_tcase");

  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_1);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_2);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_3);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_4);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_5);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_6);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_7);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_8);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_9);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_10);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_11);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_12);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_13);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_14);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_15);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_16);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_17);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_18);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_19);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_20);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_21);
  tcase_add_test(s21_sharp_tcase, s21_sharp_eq_22);

  suite_add_tcase(s, s21_sharp_tcase);

  return s;
}