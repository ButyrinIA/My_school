#include "s21_string_test.h"

int main(void) {
  int number_failed = 0;
  Suite* s[] = {s21_strlen_suite(),
                s21_memchr_suite(),
                s21_memcpy_suite(),
                s21_memcmp_suite(),
                s21_memset_suite(),
                s21_strncat_suite(),
                s21_strncmp_suite(),
                s21_strcspn_suite(),
                s21_strrchr_suite(),
                s21_strtok_suite(),
                s21_sprintf_suite(),
                s21_sscanf_suite(),
                s21_sharp_suite(),
                s21_strchr_suite(),
                s21_strerror_suite(),
                s21_strncpy_suite(),
                s21_strpbrk_suite(),
                s21_strstr_suite(),
                NULL};

  for (Suite** current_suite = s; *current_suite != NULL; current_suite++) {
    s21_test_one_suite(*current_suite, &number_failed);
  }
  return 0;
}

void s21_test_one_suite(Suite* current_suit, int* sum_of_errors) {
  SRunner* sr = NULL;
  sr = srunner_create(current_suit);

  srunner_run_all(sr, CK_NORMAL);
  *sum_of_errors += srunner_ntests_failed(sr);
  srunner_free(sr);
}
