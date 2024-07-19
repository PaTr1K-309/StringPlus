#include "s21_sscanf.h"

int s21_parse_int_base(s21_sscanf_state *state, void *result, int base,
                       const type *type) {
  bool flag = 1;
  bool is_negative = 0;
  const char *s = state->str;
  s21_skip_whitespace_and_sign(&s, &is_negative, &state->width, &flag,
                               &state->matched);
  base = s21_determine_base(&s, base, &state->width);
  if (flag &&
      ((base == 10 && !isdigit(*s)) || (base == 8 && (*s < '0' || *s > '7')) ||
       (base == 16 && !isxdigit(*s)))) {
    flag = 0;
  }
  if (flag) {
    unsigned long long temp_value =
        s21_parse_signed_digits(&s, base, &state->width, &flag);
    s21_set_signed_value(result, temp_value, is_negative, type);
    state->str = s;
  }
  return flag;
}

void s21_skip_whitespace_and_sign(const char **s, bool *is_negative, int *width,
                                  bool *flag, int *matched) {
  while (isspace(**s)) (*s)++;
  if (**s == '\0') (*matched)--;
  if (**s == '-') {
    (*width)--;
    if (*width <= 0) *flag = 0;
    *is_negative = 1;
    (*s)++;
  } else if (**s == '+') {
    (*width)--;
    if (*width <= 0) *flag = 0;
    (*s)++;
  }
}

int s21_determine_base(const char **s, int base, int *width) {
  if (base == 0) {
    if (**s == '0') {
      if ((*s)[1] == 'x' || (*s)[1] == 'X') {
        base = 16;
        *s += 2;
        *width -= 2;
      } else {
        base = 8;
        (*s)++;
        (*width)--;
      }
    } else {
      base = 10;
    }
  }
  return base;
}

unsigned long long s21_parse_signed_digits(const char **s, int base, int *width,
                                           bool *flag) {
  unsigned long long temp_value = 0;
  while (((base == 10 && isdigit(**s)) ||
          (base == 8 && (**s >= '0' && **s <= '7')) ||
          (base == 16 && isxdigit(**s))) &&
         *width > 0 && *flag == 1) {
    unsigned long long digit_value =
        (isdigit(**s) ? (**s - '0') : (tolower(**s) - 'a' + 10));
    if (temp_value > (ULLONG_MAX - digit_value) / base) {
      temp_value = ULLONG_MAX;
      *flag = 0;
    } else {
      temp_value = temp_value * base + digit_value;
      (*width)--;
      (*s)++;
    }
  }
  return temp_value;
}

void s21_set_signed_value(void *result, unsigned long long temp_value,
                          bool is_negative, const type *type) {
  long long int signed_temp_value = 0;
  if (is_negative) {
    if (temp_value > (unsigned long long)LLONG_MAX + 1) {
      signed_temp_value = LLONG_MIN;
    } else {
      signed_temp_value = -temp_value;
    }
  } else {
    if (temp_value > (unsigned long long)LLONG_MAX) {
      signed_temp_value = LLONG_MAX;
    } else {
      signed_temp_value = temp_value;
    }
  }
  s21_int_type_set(result, &signed_temp_value, type);
}

int s21_parse_unsigned_base(s21_sscanf_state *state, void *result, int base,
                            const type *type) {
  bool flag = 1;
  bool is_negative = 0;
  const char *s = state->str;
  s21_skip_whitespace_and_sign(&s, &is_negative, &state->width, &flag,
                               &state->matched);
  if (base == 16 && *s == '0' && (s[1] == 'x' || s[1] == 'X')) s += 2;
  unsigned long long temp_value =
      s21_parse_signed_digits(&s, base, &state->width, &flag);
  if (flag) state->str = s;
  if (is_negative) temp_value *= -1;
  s21_uint_type_set(result, &temp_value, type);
  return flag;
}

int s21_parse_string(s21_sscanf_state *state, char *buf) {
  bool flag = 1;
  const char *s = state->str;
  while (isspace(*s)) s++;
  if (*s == '\0') flag = 0;
  if (flag) {
    while (!isspace(*s) && *s && state->width--) *buf++ = *s++;
    *buf = '\0';
    state->str = s;
  }
  return flag;
}

int s21_parse_float(s21_sscanf_state *state, void *result, const type *type) {
  bool flag = 1;
  const char *s = state->str;
  bool is_negative = 0;
  bool has_digits = 0;
  long double temp_value = 0.0;
  s21_skip_whitespace_and_sign(&s, &is_negative, &state->width, &flag,
                               &state->matched);
  while (isdigit(*s) && state->width > 0) {
    temp_value = (temp_value * 10.0) + (*s - '0');
    s++;
    has_digits = 1;
    state->width--;
  }
  if (*s == '.' && state->width > 0) {
    state->width--;
    s++;
    s21_parse_fraction(&s, &state->width, &has_digits, &temp_value);
  }
  if (!has_digits) flag = 0;
  if (flag) {
    if (tolower(*s) == 'e' && state->width > 0) {
      s++;
      state->width--;
      int exponent = s21_parse_exponent(&s, &state->width);
      temp_value *= powl(10.0L, exponent);
    }
    temp_value *= is_negative ? -1 : 1;
    s21_float_type_set(result, &temp_value, type);
    state->str = s;
  }
  return flag;
}

void s21_parse_fraction(const char **s, int *width, bool *has_digits,
                        long double *temp_value) {
  long double fraction = 1.0;
  while (isdigit(**s) && *width > 0) {
    fraction /= 10.0;
    *temp_value += (**s - '0') * fraction;
    (*s)++;
    *has_digits = 1;
    (*width)--;
  }
}

int s21_parse_exponent(const char **s, int *width) {
  int exponent = 0;
  bool exp_neg = 0;
  if (**s == '-') {
    exp_neg = 1;
    (*s)++;
    (*width)--;
  } else if (**s == '+') {
    (*s)++;
    (*width)--;
  }
  while (isdigit(**s) && *width > 0) {
    exponent = (exponent * 10) + (**s - '0');
    (*s)++;
    (*width)--;
  }
  return exp_neg ? -exponent : exponent;
}

int s21_parse_char(s21_sscanf_state *state, char *value) {
  bool flag = 1;
  if (state->chars_count) {
    while (isspace(*state->str)) state->str++;
  }
  if (*state->str == '\0')
    flag = 0;
  else {
    *value = *state->str;
    state->str++;
    state->chars_count++;
  }
  return flag;
}

void s21_int_type_set(void *result, long long int *temp_value,
                      const type *type) {
  if (*type == TYPE_SHORT)
    *(short *)result = (short)*temp_value;
  else if (*type == TYPE_INT)
    *(int *)result = (int)*temp_value;
  else if (*type == TYPE_LONG)
    *(long *)result = (long)*temp_value;
  else if (*type == TYPE_LONG_LONG)
    *(long long *)result = *temp_value;
}

void s21_uint_type_set(void *result, unsigned long long *temp_value,
                       const type *type) {
  if (*type == TYPE_SHORT)
    *(unsigned short *)result = (unsigned short)*temp_value;
  else if (*type == TYPE_INT)
    *(unsigned int *)result = (unsigned int)*temp_value;
  else if (*type == TYPE_LONG)
    *(unsigned long *)result = (unsigned long)*temp_value;
  else if (*type == TYPE_LONG_LONG)
    *(unsigned long long *)result = (unsigned long long)*temp_value;
}

void s21_float_type_set(void *result, long double *temp_value,
                        const type *type) {
  if (*type == TYPE_LONG_DOUBLE)
    *(long double *)result = *temp_value;
  else if (*type == TYPE_LONG)
    *(double *)result = (double)*temp_value;
  else if (*type == TYPE_INT)
    *(float *)result = (float)*temp_value;
}