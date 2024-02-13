#include "s21_string_test.h"

START_TEST(s21_memchr_eq_1) {
  const char *str = "pamparam tutturu";
  const char ch = 't';

  s21_size_t len = s21_strlen(str);

  ck_assert_str_eq(s21_memchr(str, ch, len), memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_eq_2) {
  const char *str = "Hello! World!";
  const char ch = '!';

  s21_size_t len = s21_strlen(str);

  ck_assert_str_eq(s21_memchr(str, ch, len), memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_eq_3) {
  const char *str = "Hello World!";
  const char ch = '\0';

  s21_size_t len = s21_strlen(str);

  ck_assert_ptr_null(s21_memchr(str, ch, len));
  ck_assert_ptr_null(memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_eq_4) {
  const char *str = "pamparam";
  const char ch = 't';

  s21_size_t len = s21_strlen(str);

  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_eq_5) {
  const char *str = "pamparam";
  const char ch = 'p';

  s21_size_t len = s21_strlen(str);

  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_null_1) {
  const char *str = "pamparam";
  const char ch = '\n';

  s21_size_t len = s21_strlen(str);

  ck_assert_ptr_null(s21_memchr(str, ch, len));
  ck_assert_ptr_null(memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_null_2) {
  const char *str = "\n\n\n";
  const char ch = '\t';

  s21_size_t len = s21_strlen(str);

  ck_assert_ptr_null(s21_memchr(str, ch, len));
  ck_assert_ptr_null(memchr(str, ch, len));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s;

  TCase *s21_memchr_tcase;

  s = suite_create("s21_memchr_test");

  s21_memchr_tcase = tcase_create("s21_memchr_tcase");

  tcase_add_test(s21_memchr_tcase, s21_memchr_eq_1);
  tcase_add_test(s21_memchr_tcase, s21_memchr_eq_2);
  tcase_add_test(s21_memchr_tcase, s21_memchr_eq_3);
  tcase_add_test(s21_memchr_tcase, s21_memchr_eq_4);
  tcase_add_test(s21_memchr_tcase, s21_memchr_eq_5);

  tcase_add_test(s21_memchr_tcase, s21_memchr_null_1);
  tcase_add_test(s21_memchr_tcase, s21_memchr_null_2);

  suite_add_tcase(s, s21_memchr_tcase);

  return s;
}
