#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *up_str = S21_NULL;
  if (str) {
    up_str = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  }
  if (up_str) {
    s21_strncpy(up_str, str, s21_strlen(str) + 1);
    for (char *up = up_str; *up; up++) {
      if (*up >= 'a' && *up <= 'z') *up -= 32;
    }
  }
  return (void *)up_str;
}