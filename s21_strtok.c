#include "s21_string.h"

char *s21_strtok(char *str, const char *divider) {
  char *res = S21_NULL;
  if (divider != S21_NULL) {
    static char *next = S21_NULL;

    if (str) next = str;

    if (next) {
      while (*next && s21_strchr(divider, *next)) next++;

      if (*next != '\0') {
        res = next;

        while (*next && !s21_strchr(divider, *next)) next++;

        if (*next)
          *next++ = '\0';
        else
          next = S21_NULL;
      }
    }
  }
  return res;
}
