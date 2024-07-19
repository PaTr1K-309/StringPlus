#ifndef SRC_TEST_S21_TESTS_H_
#define SRC_TEST_S21_TESTS_H_

#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *sprintf_suite();
Suite *strlen_suite();
Suite *strcmp_suite();
Suite *strncmp_suite();
Suite *strspn_suite();
Suite *strcspn_suite();
Suite *memcmp_suite();
Suite *memchr_suite();
Suite *memcpy_suite();
Suite *memset_suite();
Suite *strcat_suite();
Suite *strchr_suite();
Suite *strerror_suite();
Suite *strncat_suite();
Suite *strpbrk_suite();
Suite *strrchr_suite();
Suite *strstr_suite();
Suite *strtok_suite();
Suite *strcpy_suite();
Suite *strncpy_suite();
Suite *to_upper_suite();
Suite *to_lower_suite();
Suite *insert_suite();
Suite *trim_suite();
Suite *sscanf_suite();

#endif  // SRC_TEST_S21_TESTS_H_