#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include "s21_string.h"

typedef enum {
  TYPE_INT,
  TYPE_SHORT,
  TYPE_LONG,
  TYPE_LONG_LONG,
  TYPE_FLOAT,
  TYPE_LONG_DOUBLE
} type;

typedef struct {
  const char *format;
  const char *str;
  const char *start_str;
  va_list args;
  int matched;
  int width;
  bool suppress_assignment;
  bool has_width;
  int chars_count;
} s21_sscanf_state;

void width_handle(s21_sscanf_state *state, const char **format_ptr);
int s21_length_handle(char format_specifier, type *type);
int s21_format_specifier(s21_sscanf_state *state, char format_specifier,
                         type *type);
int s21_digit_spec_handle(s21_sscanf_state *state, int *flag, type *type,
                          int base);
int s21_unsigned_digit_spec_handle(s21_sscanf_state *state, int *flag,
                                   type *type, int base);
int s21_string_spec_handle(s21_sscanf_state *state, int *flag);
int s21_floats_spec_handle(s21_sscanf_state *state, int *flag, type *type);
int s21_char_spec_handle(s21_sscanf_state *state, int *flag);
void s21_n_spec_handle(s21_sscanf_state *state);
int s21_parse_int_base(s21_sscanf_state *state, void *value, int bases,
                       const type *type);
void s21_skip_whitespace_and_sign(const char **s, bool *is_negative, int *width,
                                  bool *flag, int *matched);
int s21_determine_base(const char **s, int base, int *width);
unsigned long long s21_parse_signed_digits(const char **s, int base, int *width,
                                           bool *flag);
void s21_set_signed_value(void *result, unsigned long long temp_value,
                          bool is_negative, const type *type);
int s21_parse_unsigned_base(s21_sscanf_state *state, void *value, int base,
                            const type *type);
int s21_parse_string(s21_sscanf_state *state, char *buf);
int s21_parse_float(s21_sscanf_state *state, void *value, const type *type);
void s21_parse_fraction(const char **s, int *width, bool *has_digits,
                        long double *temp_value);
int s21_parse_exponent(const char **s, int *width);
int s21_parse_char(s21_sscanf_state *state, char *value);
void s21_int_type_set(void *result, long long int *temp_value,
                      const type *type);
void s21_uint_type_set(void *result, unsigned long long *temp_value,
                       const type *type);
void s21_float_type_set(void *result, long double *temp_value,
                        const type *type);

#endif  // SRC_S21_SSCANF_H_