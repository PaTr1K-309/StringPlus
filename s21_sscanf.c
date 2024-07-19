#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  bool error_flag = 0;
  s21_sscanf_state state = {0};
  state.str = str;
  state.start_str = str;
  va_start(state.args, format);
  const char *format_ptr = format;
  while (*format_ptr && !error_flag) {
    char n_spec_check = 0;
    if (*format_ptr == '%') {
      format_ptr++;
      if (*format_ptr == '*') {
        state.suppress_assignment = 1;
        format_ptr++;
      }
      state.has_width = 0;
      width_handle(&state, &format_ptr);
      type type = TYPE_INT;
      if (state.width == 0) state.width = 100;
      while (s21_length_handle(*format_ptr, &type)) format_ptr++;
      if (!s21_format_specifier(&state, *format_ptr, &type)) va_end(state.args);
      state.suppress_assignment = 0;
      state.width = 0;
      n_spec_check = *format_ptr;
      if (*format_ptr != '\0') format_ptr++;
      if (*format_ptr == '%') continue;
    } else if (*format_ptr != *state.str)
      error_flag = 1;
    if (!error_flag && *state.str != '\0' && *format_ptr != '\0') {
      format_ptr++;
      if (!state.has_width && n_spec_check != 'n') state.str++;
    }
  }
  va_end(state.args);
  return state.matched;
}

void width_handle(s21_sscanf_state *state, const char **format_ptr) {
  while (isdigit(**format_ptr)) {
    state->width = state->width * 10 + (**format_ptr - '0');
    (*format_ptr)++;
    state->has_width = 1;
  }
}