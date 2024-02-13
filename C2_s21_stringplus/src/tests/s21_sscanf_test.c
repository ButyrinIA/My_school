#include "s21_string_test.h"

START_TEST(test_s21_sscanf_integer) {
  int value;
  const char *str = "42";
  const char *format = "%d";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 42);
}
END_TEST

START_TEST(test_s21_sscanf_symbols_before_percent) {
  int value = 0;
  int value2 = 0;
  const char *str = "fd42";
  const char *str2 = "fd42";
  const char *format = "fd%d";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str2, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_s21_sscanf_diff_in_str_and_format) {
  int value = 0;
  int value2 = 0;
  const char *str = "fd42";
  const char *format = "%d";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_s21_sscanf_diff2_in_str_and_format) {
  int value = 0;
  int value2 = 0;
  const char *str = "fd42";
  const char *format = "dd%d";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_s21_sscanf_integer_percent) {
  int value = 0;
  const char *str = "%42";
  const char *format = "%%%d";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 42);
}
END_TEST

START_TEST(test_s21_sscanf_integer_no_percent) {
  int value = 0;
  const char *str = "42";
  const char *format = "%%%d";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(value, 0);
}
END_TEST

START_TEST(test_s21_sscanf_float) {
  float value;
  const char *str = "3.14";
  const char *format = "%f";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_float_eq_tol(value, 3.14, 0.001);
}
END_TEST

START_TEST(test_s21_sscanf_float_neg) {
  float value;
  const char *str = "-3.14";
  const char *format = "%f";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_float_eq_tol(value, -3.14, 0.001);
}
END_TEST

START_TEST(test_s21_sscanf_string) {
  char buffer[10];
  char buffer2[10];
  const char *str = "Hello";
  const char *str2 = "Hello";
  const char *format = "%s";
  int result = s21_sscanf(str, format, buffer);
  sscanf(str2, format, buffer2);
  ck_assert_int_eq(result, 1);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sscanf_multiple_values) {
  int value1, value2;
  const char *str = "10 20";
  const char *format = "%d %d";
  int result = s21_sscanf(str, format, &value1, &value2);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(value1, 10);
  ck_assert_int_eq(value2, 20);
}
END_TEST

START_TEST(test_s21_sscanf_empty_string) {
  int value = 0;
  int value2 = 0;
  const char *str = "";
  const char *str2 = "";
  const char *format = "%d";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str2, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_s21_sscanf_invalid_format) {
  int value;
  const char *str = "Hello";
  const char *format = "%d";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 0);
}

START_TEST(test_s21_sscanf_multiple_formats) {
  int value1;
  float value2;
  const char *str = "10 3.14";
  const char *format = "%d %f";
  int result = s21_sscanf(str, format, &value1, &value2);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(value1, 10);
  ck_assert_float_eq_tol(value2, 3.14, 0.001);
}

START_TEST(test_s21_sscanf_multiple_formats_partial_match) {
  int value1, value3, value4 = 0;
  int value2 = 0;
  const char *str = "10 Hello";
  const char *format = "%d %f";
  int result = s21_sscanf(str, format, &value1, &value2);
  int result2 = sscanf(str, format, &value3, &value4);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value1, value3);
  ck_assert_int_eq(value2, 0);
}

START_TEST(test_s21_sscanf_integer_float) {
  int value1;
  float value2;
  const char *str = "10 3.14";
  const char *format = "%d %f";
  int result = s21_sscanf(str, format, &value1, &value2);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(value1, 10);
  ck_assert_float_eq_tol(value2, 3.14, 0.001);
}
END_TEST

START_TEST(test_s21_sscanf_float_integer) {
  float value1;
  int value2;
  const char *str = "3.14 10";
  const char *format = "%f %d";
  int result = s21_sscanf(str, format, &value1, &value2);
  ck_assert_int_eq(result, 2);
  ck_assert_float_eq_tol(value1, 3.14, 0.001);
  ck_assert_int_eq(value2, 10);
}

START_TEST(test_s21_sscanf_string_integer_float) {
  char buffer[10];
  int value1, value3;
  float value2, value4;
  const char *str = "Hello 10 3.14";
  const char *format = "%s %d %f";
  int result = s21_sscanf(str, format, buffer, &value1, &value2);
  int result2 = sscanf(str, format, buffer, &value3, &value4);
  ck_assert_int_eq(result, result2);
  ck_assert_str_eq(buffer, "Hello");
  ck_assert_int_eq(value1, 10);
  ck_assert_float_eq_tol(value2, 3.14, 0.001);
}

START_TEST(test_s21_sscanf_width_flag) {
  int value = 0;
  const char *str = "   42";
  const char *format = "%3d";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 42);
}
END_TEST

START_TEST(test_s21_sscanf_length_flag) {
  long long value;
  const char *str = "1234567890";
  const char *format = "%ld";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 1234567890LL);
}

START_TEST(test_s21_sscanf_length_flag_o) {
  long long value, value2 = 0;
  const char *str = "1234567890";
  const char *format = "%lo";
  int result = s21_sscanf(str, format, &value);
  int result2 = s21_sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}

START_TEST(test_s21_sscanf_multiple_flags) {
  long double value = 0;
  long double value2 = 0;
  const char *str = "   3.14";
  const char *format = "%10Lf";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq_tol(value, value2, 0.001);
}

START_TEST(test_s21_sscanf_exponential_lower) {
  long double value = 0;
  long double value2 = 0;
  const char *str = "1.23e+2";
  const char *format = "%Lf";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq_tol(value, value2, 0.001);
}
END_TEST

START_TEST(test_s21_sscanf_exponential_upper) {
  long double value = 0;
  long double value2 = 0;
  const char *str = "1.23E+2";
  const char *format = "%Lf";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq_tol(value, value2, 0.001);
}

START_TEST(test_s21_sscanf_general_lower) {
  long double value = 0;
  long double value2 = 0;
  const char *str = "32.14";
  const char *format = "%Lf";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq_tol(value, value2, 0.001);
}

START_TEST(test_s21_sscanf_general_upper) {
  long double value = 0;
  long double value2 = 0;
  const char *str = "3.14";
  const char *format = "%LG";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_float_eq_tol(value, value2, 0.001);
}

START_TEST(test_s21_sscanf_octal) {
  int value = 0;
  int value2 = 0;
  int value3 = 0;
  int value4 = 0;
  const char *str = "8 3778";
  const char *format = "%o %o";
  int result = s21_sscanf(str, format, &value, &value3);
  int result2 = sscanf(str, format, &value2, &value4);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
  ck_assert_int_eq(value3, value4);
}

START_TEST(test_s21_sscanf_unsigned_decimal) {
  unsigned int value;
  const char *str = "123";
  const char *format = "%u";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 123);
}

START_TEST(test_s21_sscanf_hexadecimal_lower) {
  unsigned int value, value2;
  const char *str = "C1BaA";
  const char *format = "%x";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}

START_TEST(test_s21_sscanf_hexadecimal_upper) {
  unsigned int value;
  unsigned int value2;
  const char *str = "1A";
  const char *str2 = "1A";
  const char *format = "%X";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str2, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}

START_TEST(test_s21_sscanf_pointer) {
  void **ptr = 0;
  const char *str = "0x7ffee5e5e9e0";
  const char *format = "%p";
  int result = s21_sscanf(str, format, &ptr);
  int result2 = s21_sscanf(str, format, &ptr);
  ck_assert_int_eq(result, result2);
}

START_TEST(test_s21_sscanf_decimal) {
  int value;
  const char *str = "123";
  const char *format = "%i";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 123);
}

START_TEST(test_s21_sscanf_decimal_with_plus_sign) {
  int value;
  const char *str = "+123";
  const char *format = "%i";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 123);
}

START_TEST(test_s21_sscanf_empty_format) {
  int value;
  const char *str = "123";
  const char *format = "";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 0);
}

START_TEST(test_s21_sscanf_empty_input) {
  int value = 0;
  int value2 = 0;
  const char *str = "";
  const char *format = "%d";
  int result = sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
}

START_TEST(test_s21_sscanf_invalid_conversion_specifier) {
  int value;
  int value2;
  const char *str = "123";
  const char *format = "%x";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
}

START_TEST(test_s21_sscanf_max_int) {
  int value;
  const char *str = "2147483647";
  const char *format = "%d";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, INT_MAX);
}

START_TEST(test_s21_sscanf_min_int) {
  int value;
  const char *str = "-2147483648";
  const char *format = "%d";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, INT_MIN);
}

START_TEST(test_s21_sscanf_max_unsigned_int) {
  unsigned int value;
  const char *str = "4294967295";
  const char *format = "%u";
  int result = s21_sscanf(str, format, &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, UINT_MAX);
}

START_TEST(test_s21_sscanf_max_long_long) {
  long int value;
  long int value2;
  const char *str = "9223372036854775807";
  const char *format = "%ld";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
  // ck_assert_int_eq(value, LLONG_MAX);
}

START_TEST(test_s21_sscanf_min_long_long) {
  long int value;
  long int value2;
  const char *str = "-9223372036854775808";
  const char *format = "%ld";
  int result = s21_sscanf(str, format, &value);
  int result2 = sscanf(str, format, &value2);
  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(value, value2);
}

START_TEST(test_s21_sscanf_string_with_asterix) {
  const char *str = "lmao???1234";
  const char *format = "%*s%d";
  int val = 0;
  int val_1 = 0;
  s21_sscanf(str, format, &val);
  sscanf(str, format, &val_1);

  ck_assert_int_eq(val, val_1);
}

START_TEST(test_s21_sscanf_char_without_asterix) {
  const char *str = "n123";
  const char *format = " %c%d";
  int val = ' ';
  int val_1 = ' ';
  int val_2 = 0;
  int val_3 = 0;
  s21_sscanf(str, format, &val, &val_2);
  sscanf(str, format, &val_1, &val_3);

  ck_assert_int_eq(val, val_1);
  ck_assert_int_eq(val_3, val_2);
}

START_TEST(test_s21_sscanf_n_without_asterix) {
  const char *str = "  1231  ";
  const char *format = " %d%n";
  int val_1 = 0;
  int val = 0;
  int val_2 = 0;
  int val_3 = 0;
  int result = s21_sscanf(str, format, &val, &val_2);
  int result2 = sscanf(str, format, &val_1, &val_3);

  ck_assert_int_eq(result, result2);
  ck_assert_int_eq(val, val_1);
  ck_assert_int_eq(val_3, val_2);
}

START_TEST(test_s21_sscanf_short_int) {
  const char *str = "1231";
  const char *format = " %hd";
  short int val_1 = 0;
  short int val = 0;
  s21_sscanf(str, format, &val);
  sscanf(str, format, &val_1);

  ck_assert_int_eq(val, val_1);
}

START_TEST(test_s21_sscanf_width_int) {
  const char *str = "1231";
  const char *format = " %10d";
  int val_1 = 0;
  int val = 0;
  s21_sscanf(str, format, &val);
  sscanf(str, format, &val_1);

  ck_assert_int_eq(val, val_1);
}

START_TEST(test_s21_sscanf_unsgined_long) {
  const char *str = "1231";
  const char *format = " %10hu";
  long unsigned int val_1 = 0;
  long unsigned int val = 0;
  s21_sscanf(str, format, &val);
  sscanf(str, format, &val_1);

  ck_assert_int_eq(val, val_1);
}

START_TEST(test_s21_sscanf_unsgined_short) {
  const char *str = "1231";
  const char *format = " %10hu";
  short unsigned int val_1 = 0;
  short unsigned int val = 0;
  s21_sscanf(str, format, &val);
  sscanf(str, format, &val_1);

  ck_assert_int_eq(val, val_1);
}

Suite *s21_sscanf_suite(void) {
  Suite *s;
  TCase *s21_sscanf_tcase;
  s = suite_create("s21_sscanf_suite");
  s21_sscanf_tcase = tcase_create("s21_sscanf_tcase");

  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_integer);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_symbols_before_percent);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_diff_in_str_and_format);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_diff2_in_str_and_format);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_integer_percent);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_integer_no_percent);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_float);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_float_neg);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_string);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_multiple_values);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_empty_string);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_invalid_format);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_multiple_formats);
  tcase_add_test(s21_sscanf_tcase,
                 test_s21_sscanf_multiple_formats_partial_match);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_integer_float);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_float_integer);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_string_integer_float);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_width_flag);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_length_flag);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_length_flag_o);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_multiple_flags);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_max_int);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_exponential_lower);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_exponential_upper);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_general_lower);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_general_upper);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_octal);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_unsigned_decimal);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_hexadecimal_lower);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_hexadecimal_upper);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_pointer);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_decimal);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_decimal_with_plus_sign);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_empty_format);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_empty_input);
  tcase_add_test(s21_sscanf_tcase,
                 test_s21_sscanf_invalid_conversion_specifier);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_min_int);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_max_unsigned_int);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_max_long_long);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_min_long_long);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_string_with_asterix);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_char_without_asterix);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_n_without_asterix);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_short_int);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_width_int);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_unsgined_long);
  tcase_add_test(s21_sscanf_tcase, test_s21_sscanf_unsgined_short);

  suite_add_tcase(s, s21_sscanf_tcase);

  return s;
}
