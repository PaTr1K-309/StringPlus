#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;

  if (*needle == '\0') {
    result = (char *)haystack;
  }

  while (*haystack != '\0') {
    if (*haystack == *needle) {
      const char *h = haystack;
      const char *n = needle;

      while (*n != '\0' && *h == *n) {
        h++;
        n++;
      }
      if (*n == '\0') {
        result = (char *)haystack;
      }
    }
    haystack++;
  }

  return result;
}