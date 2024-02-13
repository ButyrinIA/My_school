#include "s21_string_test.h"

#define BUFF_SIZE 1024

START_TEST(s21_sprintf_custom_eq_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 100;
  double b = 11234.44446;
  char c = '\n';

  int res1 = s21_sprintf(str, "%d %5.5lf hello? %c", a, b, c);
  int res2 = sprintf(str2, "%d %5.5lf hello? %c", a, b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_custom_eq_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 0.15345811;
  long double b = 11234.44446;
  const char* str_test = "why?\n\n";

  int res1 = s21_sprintf(str, "%-1.10G %2.5Lf %+Le %1.1s", a, b, b, str_test);
  int res2 = sprintf(str2, "%-1.10G %2.5Lf %+Le %1.1s", a, b, b, str_test);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_custom_eq_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 0.15345811;
  double b = 159.11111999999;

  int res1 = s21_sprintf(str, "%#10.1g %-2.10lf", a, b);
  int res2 = sprintf(str2, "%#10.1g %-2.10lf", a, b);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_custom_eq_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 0;
  int b = 10234395;
  int c = 161616;
  int* d = &c;
  int x = -1;

  int res1 = s21_sprintf(str, "%#10o %15o %#x||| %% %1p %u", a, b, c, d, x);
  int res2 = sprintf(str2, "%#10o %15o %#x||| %% %1p %u", a, b, c, d, x);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_custom_eq_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double x = 11200.5974313123;
  int a = 50;
  double y = 111.99999;

  int res1 = s21_sprintf(str, "%#10g %*G ", x, a, y);
  int res2 = sprintf(str2, "%#10g %*G ", x, a, y);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_custom_eq_6) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double x = 11200.5974313123;
  int a = 2;
  double y = 111.99999;
  int b = 18;

  int res1 = s21_sprintf(str, "%#10e %*E %10g %*G %#95f %*.*f", x, a, y, y, a,
                         x, x, a, b, y);
  int res2 = sprintf(str2, "%#10e %*E %10g %*G %#95f %*.*f", x, a, y, y, a, x,
                     x, a, b, y);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_custom_eq_7) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = -1;
  int b = 20;
  unsigned int c = 100;

  int res1 = s21_sprintf(str, "%% %u check this string\n\n %d %i", a, b, c);
  int res2 = sprintf(str2, "%% %u check this string\n\n %d %i", a, b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_e_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 0.153333;
  double b = 4.999999;

  int res1 = s21_sprintf(str, "%e %.15e", b, a);
  int res2 = sprintf(str2, "%e %.15e", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_e_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1888.8888888;
  double b = -0.111111;

  int res1 = s21_sprintf(str, "%0#e %+15e", b, a);
  int res2 = sprintf(str2, "%0#e %+15e", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_e_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 300000.9999999;
  double b = -4.9999999;

  int res1 = s21_sprintf(str, "%-11e %+15.15e", b, a);
  int res2 = sprintf(str2, "%-11e %+15.15e", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_e_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1;
  double b = 2;

  int res1 = s21_sprintf(str, "%-+5e %+1.e", b, a);
  int res2 = sprintf(str2, "%-+5e %+1.e", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_e_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1000.1;
  double b = 2000.1;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-+*.*e %.e", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*e %.e", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_e_6) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 111111.9999;
  double b = 11111.9999;
  for (int i = 0; i < 10; i++) {
    int res1 = s21_sprintf(str, "%-+*.*e %.e", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*e %.e", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_E_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 0.153333;
  double b = 4.999999;

  int res1 = s21_sprintf(str, "%E %.15E", b, a);
  int res2 = sprintf(str2, "%E %.15E", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_E_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1888.8888888;
  double b = -0.111111;

  int res1 = s21_sprintf(str, "%0#E %+15E", b, a);
  int res2 = sprintf(str2, "%0#E %+15E", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_E_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 300000.9999999;
  double b = -4.9999999;

  int res1 = s21_sprintf(str, "%-11E %+15.15E", b, a);
  int res2 = sprintf(str2, "%-11E %+15.15E", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_E_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1;
  double b = 2;

  int res1 = s21_sprintf(str, "%-+5E %+1.E", b, a);
  int res2 = sprintf(str2, "%-+5E %+1.E", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_E_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1000.1;
  double b = 2000.1;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-+*.*E %.E", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*E %.E", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_E_6) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 111111.9999;
  double b = 11111.9999;
  for (int i = 0; i < 10; i++) {
    int res1 = s21_sprintf(str, "%-+*.*E %.E", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*E %.E", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_G_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 0.153333;
  double b = 4.999999;

  int res1 = s21_sprintf(str, "%G %.15G", b, a);
  int res2 = sprintf(str2, "%G %.15G", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_G_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1888.8888888;
  double b = -0.111111;

  int res1 = s21_sprintf(str, "%0#G %+15G", b, a);
  int res2 = sprintf(str2, "%0#G %+15G", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_G_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 300000.9999999;
  double b = -4.9999999;

  int res1 = s21_sprintf(str, "% 11G %+15.15G", b, a);
  int res2 = sprintf(str2, "% 11G %+15.15G", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_G_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1;
  double b = 2;

  int res1 = s21_sprintf(str, "%-+5G %+1.10G", b, a);
  int res2 = sprintf(str2, "%-+5G %+1.10G", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_G_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1000.1;
  double b = 2000.1;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-+*.*G %.G", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*G %.G", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_G_6) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 111111.9999;
  double b = 11111.9999;
  for (int i = 0; i < 10; i++) {
    int res1 = s21_sprintf(str, "%-+*.*G %.G", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*G %.G", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_g_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 0.153333;
  double b = 4.999999;

  int res1 = s21_sprintf(str, "%g %.15g", b, a);
  int res2 = sprintf(str2, "%g %.15g", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1888.8888888;
  double b = -0.111111;

  int res1 = s21_sprintf(str, "%0#g %+15g", b, a);
  int res2 = sprintf(str2, "%0#g %+15g", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 300000.9999999;
  double b = -4.9999999;

  int res1 = s21_sprintf(str, "% 11g %+15.15g", b, a);
  int res2 = sprintf(str2, "% 11g %+15.15g", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1;
  double b = 2;

  int res1 = s21_sprintf(str, "%-+5g %+1.10g", b, a);
  int res2 = sprintf(str2, "%-+5g %+1.10g", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1000.1;
  double b = 2000.1;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-+*.*g %.g", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*g %.g", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_g_6) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 111111.9999;
  double b = 11111.9999;
  for (int i = 0; i < 10; i++) {
    int res1 = s21_sprintf(str, "%-+*.*g %.g", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*g %.g", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_f_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 0.153333;
  double b = 4.999999;

  int res1 = s21_sprintf(str, "%f %.15f", b, a);
  int res2 = sprintf(str2, "%f %.15f", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_f_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1888.8888888;
  double b = -0.111111;

  int res1 = s21_sprintf(str, "%0#f %+15f", b, a);
  int res2 = sprintf(str2, "%0#f %+15f", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_f_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 300000.9999999;
  double b = -4.9999999;

  int res1 = s21_sprintf(str, "% 11f %+15.15f", b, a);
  int res2 = sprintf(str2, "% 11f %+15.15f", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_f_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1;
  double b = 2;

  int res1 = s21_sprintf(str, "%-+5f %+01.10f", b, a);
  int res2 = sprintf(str2, "%-+5f %+01.10f", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_f_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 1000.1;
  double b = 2000.1;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-+*.*f %.f", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*f %.f", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_f_6) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  double a = 111111.9999;
  double b = 11111.9999;
  for (int i = 0; i < 10; i++) {
    int res1 = s21_sprintf(str, "%-+*.*f %.f", i, i, b, a);
    int res2 = sprintf(str2, "%-+*.*f %.f", i, i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_o_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 1593;

  int res1 = s21_sprintf(str, "%o", a);
  int res2 = sprintf(str2, "%o", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_o_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int b = 0;
  int c = 1111111;

  int res1 = s21_sprintf(str, "%o %o", b, c);
  int res2 = sprintf(str2, "%o %o", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_o_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = INT_MAX;
  int b = 9999999;

  int res1 = s21_sprintf(str, "%11o %15o", b, a);
  int res2 = sprintf(str2, "%11o %15o", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_o_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 3;
  int b = 3;

  int res1 = s21_sprintf(str, "%o %#o", b, a);
  int res2 = sprintf(str2, "%o %#o", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_o_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 999;
  int b = 9;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%#-*o %#o", i, b, a);
    int res2 = sprintf(str2, "%#-*o %#o", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_X_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 1593;

  int res1 = s21_sprintf(str, "%X", a);
  int res2 = sprintf(str2, "%X", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_X_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int b = 0;
  int c = 1111111;

  int res1 = s21_sprintf(str, "%X %X", b, c);
  int res2 = sprintf(str2, "%X %X", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_X_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = INT_MAX;
  int b = 9999999;

  int res1 = s21_sprintf(str, "%11X %15X", b, a);
  int res2 = sprintf(str2, "%11X %15X", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_X_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 3;
  int b = 3;

  int res1 = s21_sprintf(str, "%X %#X", b, a);
  int res2 = sprintf(str2, "%X %#X", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_X_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 999;
  int b = 9;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%#-*X %#X", i, b, a);
    int res2 = sprintf(str2, "%#-*X %#X", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_x_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 1593;

  int res1 = s21_sprintf(str, "%x", a);
  int res2 = sprintf(str2, "%x", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_x_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int b = 0;
  int c = 1111111;

  int res1 = s21_sprintf(str, "%x %x", b, c);
  int res2 = sprintf(str2, "%x %x", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_x_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = INT_MAX;
  int b = 9999999;

  int res1 = s21_sprintf(str, "%11x %15x", b, a);
  int res2 = sprintf(str2, "%11x %15x", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_x_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 3;
  int b = 3;

  int res1 = s21_sprintf(str, "%x %#x", b, a);
  int res2 = sprintf(str2, "%x %#x", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_x_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 999;
  int b = 9;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%#-*x %#x", i, b, a);
    int res2 = sprintf(str2, "%#-*x %#x", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_d_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 1593;

  int res1 = s21_sprintf(str, "%d", a);
  int res2 = sprintf(str2, "%d", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_d_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int b = 0;
  int c = 1111111;

  int res1 = s21_sprintf(str, "%d %d", b, c);
  int res2 = sprintf(str2, "%d %d", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_d_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = INT_MAX;
  int b = INT_MIN;

  int res1 = s21_sprintf(str, "%11d % 15d", b, a);
  int res2 = sprintf(str2, "%11d % 15d", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_d_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 3;
  int b = 3;

  int res1 = s21_sprintf(str, "%d %d", b, a);
  int res2 = sprintf(str2, "%d %d", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_d_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 999;
  int b = 9;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-*d %d", i, b, a);
    int res2 = sprintf(str2, "%-*d %d", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_i_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 1593;

  int res1 = s21_sprintf(str, "%i", a);
  int res2 = sprintf(str2, "%i", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_i_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int b = 0;
  int c = 1111111;

  int res1 = s21_sprintf(str, "%i %i", b, c);
  int res2 = sprintf(str2, "%i %i", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_i_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = INT_MAX;
  int b = INT_MIN;

  int res1 = s21_sprintf(str, "%11i % 15i", b, a);
  int res2 = sprintf(str2, "%11i % 15i", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_i_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 3;
  int b = 3;

  int res1 = s21_sprintf(str, "%i %i", b, a);
  int res2 = sprintf(str2, "%i %i", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_i_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 999;
  int b = 9;
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-*i %i", i, b, a);
    int res2 = sprintf(str2, "%-*i %i", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_c_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  char a = '\n';

  int res1 = s21_sprintf(str, "%-10c", a);
  int res2 = sprintf(str2, "%-10c", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_c_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  char b = '\n';
  char c = '\t';

  int res1 = s21_sprintf(str, "%c %c", b, c);
  int res2 = sprintf(str2, "%c %c", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_c_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  char a = '\t';
  char b = '\t';

  int res1 = s21_sprintf(str, "%11c %15c", b, a);
  int res2 = sprintf(str2, "%11c %15c", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_c_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int a = 50;
  int b = 51;

  int res1 = s21_sprintf(str, "%c %c", b, a);
  int res2 = sprintf(str2, "%C %c", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_c_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  char a = '1';
  int b = '0';
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-*i %i", i, b, a);
    int res2 = sprintf(str2, "%-*i %i", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_s_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  const char* a = "\n;;;1315";

  int res1 = s21_sprintf(str, "%-10.11s", a);
  int res2 = sprintf(str2, "%-10.11s", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_s_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  const char* b = " hello";
  const char* c = "'this okay";

  int res1 = s21_sprintf(str, "%s %s", b, c);
  int res2 = sprintf(str2, "%s %s", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_s_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  const char* a = "KFKJSjdkDAA";
  const char* b = "\n\n\n\n\n";

  int res1 = s21_sprintf(str, "%11s %15s", b, a);
  int res2 = sprintf(str2, "%11s %15s", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_s_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  const char* a = "string s21_string test";
  const char* b = "'glwpeko1  koe1'";

  int res1 = s21_sprintf(str, "%s %s", b, a);
  int res2 = sprintf(str2, "%s %s", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_s_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  const char* a = "hello\t\teveryone";
  const char* b = "and\n%welcome";
  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-*s %s", i, b, a);
    int res2 = sprintf(str2, "%-*s %s", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_p_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int test = 123;
  int* a = &test;

  int res1 = s21_sprintf(str, "%p", a);
  int res2 = sprintf(str2, "%p", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_p_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  float a = 100.0;
  float* b = &a;
  const char* c = "test";

  int res1 = s21_sprintf(str, "%p %p", b, c);
  int res2 = sprintf(str2, "%p %p", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_p_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  const char* b = "hello";
  const char* a = "bye";

  int res1 = s21_sprintf(str, "%11p %-15p", b, a);
  int res2 = sprintf(str2, "%11p %-15p", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_p_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  const char* b = "tkgsl";
  double temp = 0.123456;
  double* a = &temp;

  int res1 = s21_sprintf(str, "%p %p", b, a);
  int res2 = sprintf(str2, "%p %p", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_p_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  int test = 0;
  int* a = &test;
  int* b = a;

  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-*p %p", i, b, a);
    int res2 = sprintf(str2, "%-*p %p", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

START_TEST(s21_sprintf_u_1) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  unsigned int a = 123;

  int res1 = s21_sprintf(str, "%u", a);
  int res2 = sprintf(str2, "%u", a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_u_2) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  unsigned int b = 111241;
  unsigned int c = 10311;

  int res1 = s21_sprintf(str, "%u %u", b, c);
  int res2 = sprintf(str2, "%u %u", b, c);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_u_3) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  unsigned int a = 10000;
  unsigned int b = 11123;

  int res1 = s21_sprintf(str, "%11u %-15u", b, a);
  int res2 = sprintf(str2, "%11u %-15u", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_u_4) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  unsigned int a = 100;
  unsigned int b = 101;

  int res1 = s21_sprintf(str, "%u %u", b, a);
  int res2 = sprintf(str2, "%u %u", b, a);

  ck_assert_str_eq(str, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_u_5) {
  char str[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";

  unsigned int a = -1;
  unsigned int b = 100;

  for (int i = 0; i < 16; i++) {
    int res1 = s21_sprintf(str, "%-*u %.1u", i, b, a);
    int res2 = sprintf(str2, "%-*u %.1u", i, b, a);
    ck_assert_str_eq(str, str2);
    ck_assert_int_eq(res1, res2);
  }
}
END_TEST

Suite* s21_sprintf_suite(void) {
  Suite* s;

  TCase* s21_sprintf_tcase;
  TCase* s21_sprintf_E_tcase;
  TCase* s21_sprintf_e_tcase;
  TCase* s21_sprintf_G_tcase;
  TCase* s21_sprintf_g_tcase;
  TCase* s21_sprintf_f_tcase;
  TCase* s21_sprintf_o_tcase;
  TCase* s21_sprintf_x_tcase;
  TCase* s21_sprintf_X_tcase;
  TCase* s21_sprintf_d_tcase;
  TCase* s21_sprintf_i_tcase;
  TCase* s21_sprintf_c_tcase;
  TCase* s21_sprintf_s_tcase;
  TCase* s21_sprintf_p_tcase;
  TCase* s21_sprintf_u_tcase;

  s = suite_create("s21_sprintf_test");

  s21_sprintf_tcase = tcase_create("s21_sprintf_tcase");
  s21_sprintf_E_tcase = tcase_create("s21_sprintf_E_tcase");
  s21_sprintf_e_tcase = tcase_create("s21_sprintf_e_tcase");
  s21_sprintf_G_tcase = tcase_create("s21_sprintf_G_tcase");
  s21_sprintf_g_tcase = tcase_create("s21_sprintf_g_tcase");
  s21_sprintf_f_tcase = tcase_create("s21_sprintf_f_tcase");
  s21_sprintf_o_tcase = tcase_create("s21_sprintf_o_tcase");
  s21_sprintf_x_tcase = tcase_create("s21_sprintf_x_tcase");
  s21_sprintf_X_tcase = tcase_create("s21_sprintf_X_tcase");
  s21_sprintf_d_tcase = tcase_create("s21_sprintf_d_tcase");
  s21_sprintf_i_tcase = tcase_create("s21_sprintf_d_tcase");
  s21_sprintf_c_tcase = tcase_create("s21_sprintf_c_tcase");
  s21_sprintf_s_tcase = tcase_create("s21_sprintf_s_tcase");
  s21_sprintf_p_tcase = tcase_create("s21_sprintf_p_tcase");
  s21_sprintf_u_tcase = tcase_create("s21_sprintf_u_tcase");

  tcase_add_test(s21_sprintf_tcase, s21_sprintf_custom_eq_1);
  tcase_add_test(s21_sprintf_tcase, s21_sprintf_custom_eq_2);
  tcase_add_test(s21_sprintf_tcase, s21_sprintf_custom_eq_3);
  tcase_add_test(s21_sprintf_tcase, s21_sprintf_custom_eq_4);
  tcase_add_test(s21_sprintf_tcase, s21_sprintf_custom_eq_5);
  tcase_add_test(s21_sprintf_tcase, s21_sprintf_custom_eq_6);
  tcase_add_test(s21_sprintf_tcase, s21_sprintf_custom_eq_7);

  tcase_add_test(s21_sprintf_e_tcase, s21_sprintf_e_1);
  tcase_add_test(s21_sprintf_e_tcase, s21_sprintf_e_2);
  tcase_add_test(s21_sprintf_e_tcase, s21_sprintf_e_3);
  tcase_add_test(s21_sprintf_e_tcase, s21_sprintf_e_4);
  tcase_add_test(s21_sprintf_e_tcase, s21_sprintf_e_5);
  tcase_add_test(s21_sprintf_e_tcase, s21_sprintf_e_6);

  tcase_add_test(s21_sprintf_E_tcase, s21_sprintf_E_1);
  tcase_add_test(s21_sprintf_E_tcase, s21_sprintf_E_2);
  tcase_add_test(s21_sprintf_E_tcase, s21_sprintf_E_3);
  tcase_add_test(s21_sprintf_E_tcase, s21_sprintf_E_4);
  tcase_add_test(s21_sprintf_E_tcase, s21_sprintf_E_5);
  tcase_add_test(s21_sprintf_E_tcase, s21_sprintf_E_6);

  tcase_add_test(s21_sprintf_G_tcase, s21_sprintf_G_1);
  tcase_add_test(s21_sprintf_G_tcase, s21_sprintf_G_2);
  tcase_add_test(s21_sprintf_G_tcase, s21_sprintf_G_3);
  tcase_add_test(s21_sprintf_G_tcase, s21_sprintf_G_4);
  tcase_add_test(s21_sprintf_G_tcase, s21_sprintf_G_5);
  tcase_add_test(s21_sprintf_G_tcase, s21_sprintf_G_6);

  tcase_add_test(s21_sprintf_g_tcase, s21_sprintf_g_1);
  tcase_add_test(s21_sprintf_g_tcase, s21_sprintf_g_2);
  tcase_add_test(s21_sprintf_g_tcase, s21_sprintf_g_3);
  tcase_add_test(s21_sprintf_g_tcase, s21_sprintf_g_4);
  tcase_add_test(s21_sprintf_g_tcase, s21_sprintf_g_5);
  tcase_add_test(s21_sprintf_g_tcase, s21_sprintf_g_6);

  tcase_add_test(s21_sprintf_f_tcase, s21_sprintf_f_1);
  tcase_add_test(s21_sprintf_f_tcase, s21_sprintf_f_2);
  tcase_add_test(s21_sprintf_f_tcase, s21_sprintf_f_3);
  tcase_add_test(s21_sprintf_f_tcase, s21_sprintf_f_4);
  tcase_add_test(s21_sprintf_f_tcase, s21_sprintf_f_5);
  tcase_add_test(s21_sprintf_f_tcase, s21_sprintf_f_6);

  tcase_add_test(s21_sprintf_o_tcase, s21_sprintf_o_1);
  tcase_add_test(s21_sprintf_o_tcase, s21_sprintf_o_2);
  tcase_add_test(s21_sprintf_o_tcase, s21_sprintf_o_3);
  tcase_add_test(s21_sprintf_o_tcase, s21_sprintf_o_4);
  tcase_add_test(s21_sprintf_o_tcase, s21_sprintf_o_5);

  tcase_add_test(s21_sprintf_x_tcase, s21_sprintf_x_1);
  tcase_add_test(s21_sprintf_x_tcase, s21_sprintf_x_2);
  tcase_add_test(s21_sprintf_x_tcase, s21_sprintf_x_3);
  tcase_add_test(s21_sprintf_x_tcase, s21_sprintf_x_4);
  tcase_add_test(s21_sprintf_x_tcase, s21_sprintf_x_5);

  tcase_add_test(s21_sprintf_X_tcase, s21_sprintf_X_1);
  tcase_add_test(s21_sprintf_X_tcase, s21_sprintf_X_2);
  tcase_add_test(s21_sprintf_X_tcase, s21_sprintf_X_3);
  tcase_add_test(s21_sprintf_X_tcase, s21_sprintf_X_4);
  tcase_add_test(s21_sprintf_X_tcase, s21_sprintf_X_5);

  tcase_add_test(s21_sprintf_d_tcase, s21_sprintf_d_1);
  tcase_add_test(s21_sprintf_d_tcase, s21_sprintf_d_2);
  tcase_add_test(s21_sprintf_d_tcase, s21_sprintf_d_3);
  tcase_add_test(s21_sprintf_d_tcase, s21_sprintf_d_4);
  tcase_add_test(s21_sprintf_d_tcase, s21_sprintf_d_5);

  tcase_add_test(s21_sprintf_i_tcase, s21_sprintf_i_1);
  tcase_add_test(s21_sprintf_i_tcase, s21_sprintf_i_2);
  tcase_add_test(s21_sprintf_i_tcase, s21_sprintf_i_3);
  tcase_add_test(s21_sprintf_i_tcase, s21_sprintf_i_4);
  tcase_add_test(s21_sprintf_i_tcase, s21_sprintf_i_5);

  tcase_add_test(s21_sprintf_c_tcase, s21_sprintf_c_1);
  tcase_add_test(s21_sprintf_c_tcase, s21_sprintf_c_2);
  tcase_add_test(s21_sprintf_c_tcase, s21_sprintf_c_3);
  tcase_add_test(s21_sprintf_c_tcase, s21_sprintf_c_4);
  tcase_add_test(s21_sprintf_c_tcase, s21_sprintf_c_5);

  tcase_add_test(s21_sprintf_s_tcase, s21_sprintf_s_1);
  tcase_add_test(s21_sprintf_s_tcase, s21_sprintf_s_2);
  tcase_add_test(s21_sprintf_s_tcase, s21_sprintf_s_3);
  tcase_add_test(s21_sprintf_s_tcase, s21_sprintf_s_4);
  tcase_add_test(s21_sprintf_s_tcase, s21_sprintf_s_5);

  tcase_add_test(s21_sprintf_p_tcase, s21_sprintf_p_1);
  tcase_add_test(s21_sprintf_p_tcase, s21_sprintf_p_2);
  tcase_add_test(s21_sprintf_p_tcase, s21_sprintf_p_3);
  tcase_add_test(s21_sprintf_p_tcase, s21_sprintf_p_4);
  tcase_add_test(s21_sprintf_p_tcase, s21_sprintf_p_5);

  tcase_add_test(s21_sprintf_u_tcase, s21_sprintf_u_1);
  tcase_add_test(s21_sprintf_u_tcase, s21_sprintf_u_2);
  tcase_add_test(s21_sprintf_u_tcase, s21_sprintf_u_3);
  tcase_add_test(s21_sprintf_u_tcase, s21_sprintf_u_4);
  tcase_add_test(s21_sprintf_u_tcase, s21_sprintf_u_5);

  suite_add_tcase(s, s21_sprintf_tcase);
  suite_add_tcase(s, s21_sprintf_e_tcase);
  suite_add_tcase(s, s21_sprintf_E_tcase);
  suite_add_tcase(s, s21_sprintf_G_tcase);
  suite_add_tcase(s, s21_sprintf_g_tcase);
  suite_add_tcase(s, s21_sprintf_f_tcase);
  suite_add_tcase(s, s21_sprintf_o_tcase);
  suite_add_tcase(s, s21_sprintf_x_tcase);
  suite_add_tcase(s, s21_sprintf_X_tcase);
  suite_add_tcase(s, s21_sprintf_d_tcase);
  suite_add_tcase(s, s21_sprintf_i_tcase);
  suite_add_tcase(s, s21_sprintf_c_tcase);
  suite_add_tcase(s, s21_sprintf_s_tcase);
  suite_add_tcase(s, s21_sprintf_p_tcase);
  suite_add_tcase(s, s21_sprintf_u_tcase);

  return s;
}
