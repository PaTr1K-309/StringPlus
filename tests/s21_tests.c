#include "s21_tests.h"

int main() {
  Suite *tests[] = {
      sprintf_suite(),  strlen_suite(),   strcmp_suite(),  strncmp_suite(),
      strspn_suite(),   strcspn_suite(),  memcmp_suite(),  memset_suite(),
      memchr_suite(),   memcpy_suite(),   strcat_suite(),  strchr_suite(),
      strerror_suite(), strncat_suite(),  strpbrk_suite(), strrchr_suite(),
      strstr_suite(),   strtok_suite(),   strcpy_suite(),  strncpy_suite(),
      to_upper_suite(), to_lower_suite(), insert_suite(),  trim_suite(),
      sscanf_suite(),   S21_NULL};
  for (Suite **cases = tests; *cases != NULL; cases++) {
    SRunner *sr = srunner_create(*cases);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
    printf("\n");
  }
  return 0;
}