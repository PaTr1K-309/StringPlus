#include "s21_sscanf.h"

int s21_length_handle(char format_specifier, type *type) {
  int flag = 0;
  switch (format_specifier) {
    case 'h':
      *type = TYPE_SHORT;
      flag = 1;
      break;
    case 'l':
      if (*type == TYPE_LONG)
        *type = TYPE_LONG_LONG;
      else
        *type = TYPE_LONG;
      flag = 1;
      break;
    case 'L':
      *type = TYPE_LONG_DOUBLE;
      flag = 1;
      break;
    default:
      break;
  }
  return flag;
}

int s21_format_specifier(s21_sscanf_state *state, char format_specifier,
                         type *type) {
  int flag = state->suppress_assignment;
  switch (format_specifier) {
    case 'd':
      flag = s21_digit_spec_handle(state, &flag, type, 10);
      break;
    case 'i':
      flag = s21_digit_spec_handle(state, &flag, type, 0);
      break;
    case 'o':
      flag = s21_digit_spec_handle(state, &flag, type, 8);
      break;
    case 'u':
      flag = s21_unsigned_digit_spec_handle(state, &flag, type, 10);
      break;
    case 's':
      flag = s21_string_spec_handle(state, &flag);
      break;
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      s21_floats_spec_handle(state, &flag, type);
      break;
    case 'p':
    case 'x':
    case 'X':
      if (format_specifier == 'p') *type = TYPE_LONG_LONG;
      flag = s21_unsigned_digit_spec_handle(state, &flag, type, 16);
      break;
    case 'c':
      flag = s21_char_spec_handle(state, &flag);
      break;
    case 'n':
      s21_n_spec_handle(state);
      break;
    default:
      break;
  }
  return flag;
}

int s21_digit_spec_handle(s21_sscanf_state *state, int *flag, type *type,
                          int base) {
  if (state->suppress_assignment) {
    while (((base == 10 && isdigit(*state->str)) ||
            (base == 8 && (*state->str >= '0' && *state->str <= '7')) ||
            (base == 16 && isxdigit(*state->str)))) {
      state->str++;
    }
  } else {
    void *i = va_arg(state->args, void *);
    if (!i)
      state->matched--;
    else {
      if (s21_parse_int_base(state, i, base, type)) {
        state->matched++;
        *flag = 1;
      }
    }
  }
  return *flag;
}

int s21_unsigned_digit_spec_handle(s21_sscanf_state *state, int *flag,
                                   type *type, int base) {
  void *u = va_arg(state->args, void *);
  if (!u)
    state->matched--;
  else {
    if (s21_parse_unsigned_base(state, u, base, type)) {
      state->matched++;
      *flag = 1;
    }
  }
  return *flag;
}

int s21_string_spec_handle(s21_sscanf_state *state, int *flag) {
  if (state->suppress_assignment) {
    while (!isspace(*state->str) && *state->str) state->str++;
  } else {
    char *buf = va_arg(state->args, char *);
    if (!buf)
      state->matched--;
    else {
      if (s21_parse_string(state, buf)) {
        state->matched++;
        *flag = 1;
      } else
        state->matched--;
    }
  }
  return *flag;
}

int s21_floats_spec_handle(s21_sscanf_state *state, int *flag, type *type) {
  if (state->suppress_assignment) {
    state->str++;
  } else {
    void *f = va_arg(state->args, void *);
    if (!f)
      state->matched--;
    else {
      if (s21_parse_float(state, f, type)) {
        state->matched++;
        *flag = 1;
      }
    }
  }
  return *flag;
}

int s21_char_spec_handle(s21_sscanf_state *state, int *flag) {
  if (state->suppress_assignment) {
    state->str++;
  } else {
    char *c = va_arg(state->args, char *);
    if (!c)
      state->matched--;
    else {
      if (s21_parse_char(state, c)) {
        state->matched++;
        *flag = 1;
      } else
        state->matched = -1;
    }
  }
  return *flag;
}

void s21_n_spec_handle(s21_sscanf_state *state) {
  int *n = va_arg(state->args, int *);
  *n = state->str - state->start_str;
}