#include "s21_string.h"

static int parse_int(const char **str, int *value);
static int parse_string(const char **str, char *buf);
static int parse_float(const char **str, float *value);
static int parse_char(const char **str, char *value);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int matched = 0;
  
  for (const char *format_ptr = format, *str_ptr = str; *format_ptr && *str_ptr; format_ptr++) {
        if (*format_ptr == '%') {
            format_ptr++;
            if (*format_ptr == 'd') {
                int *i = va_arg(args, int*);
                if (parse_int(&str_ptr, i)) {
                    matched++;
                } else {
                    va_end(args);
                    return matched;
                }
            } else if (*format_ptr == 's') {
                char *buf = va_arg(args, char*);
                if (parse_string(&str_ptr, buf)) {
                    matched++;
                } else {
                    va_end(args);
                    return matched;
                }
            } else if (*format_ptr == 'f') {
                float *f = va_arg(args, float*);
                if (parse_float(&str_ptr, f)) {
                    matched++;
                } else {
                    va_end(args);
                    return matched;
                }
            } else if (*format_ptr == 'c') {
                char *c = va_arg(args, char*);
                if (parse_char(&str_ptr, c)) {
                    matched++;
                } else {
                    va_end(args);
                    return matched;
                }
            } else {
                va_end(args);
                return matched;
            }
        } else {
            if (*format_ptr != *str_ptr) {
                va_end(args);
                return matched;
            }
            str_ptr++;
        }
    }

    va_end(args);
    return matched;
}

static int parse_int(const char **str, int *value) {
    int sign = 1;
    const char *s = *str;
    
    if (*s == '-') {
        sign = -1;
        s++;
    }
    
    if (!isdigit(*s)) {
        return 0;
    }

    *value = 0;
    while (isdigit(*s)) {
        *value = (*value * 10) + (*s - '0');
        s++;
    }
    *value *= sign;
    *str = s;
    return 1;
}

static int parse_string(const char **str, char *buf) {
    const char *s = *str;

    if (*s == '\0') {
        return 0;
    }

    while (!isspace(*s) && *s) {
        *buf++ = *s++;
    }
    *buf = '\0';
    *str = s;
    return 1;
}

static int parse_float(const char **str, float *value) {
    const char *s = *str;
    int sign = 1;

    if (*s == '-') {
        sign = -1;
        s++;
    }

    if (!isdigit(*s) && *s != '.') {
        return 0;
    }

    float result = 0.0;
    while (isdigit(*s)) {
        result = (result * 10.0) + (*s - '0');
        s++;
    }

    if (*s == '.') {
        s++;
        float fraction = 1.0;
        while (isdigit(*s)) {
            fraction /= 10.0;
            result += (*s - '0') * fraction;
            s++;
        }
    }

    *value = sign * result;
    *str = s;
    return 1;
}

static int parse_char(const char **str, char *value) {
    if (**str == '\0') {
        return 0;
    }

    *value = **str;
    (*str)++;
    return 1;
}