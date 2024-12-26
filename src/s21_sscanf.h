#ifndef S21_SSCANF_H
#define S21_SSCANF_H
#include <stdarg.h>

#include "s21_string.h"
typedef struct {
  int h, l, L;
} Options;
void spec_parse(const char **format, const char **str, va_list args, int width,
                const char *nach_str, int *count, Options opt);
void process_width(const char **format, int *width);
void process_d(va_list args, const char **str, int width, Options opt);
void process_i(va_list args, const char **str, int width, Options opt);
void process_s(va_list args, const char **str, int width);
void process_f(va_list args, const char **str, int width, Options opt);
void process_c(va_list args, const char **str);
void process_o(va_list args, const char **str, int width, Options opt);
void process_x(va_list args, const char **str, int width, Options opt);
void process_p(va_list args, const char **str);
void process_n(va_list args, const char **str, const char *nach_str);
void process_u(va_list args, const char **str, int width, Options opt);
void parce_width(const char **format, Options *opt);
void process_percent(const char **str, const char **format);
float s21_atof(const char *str);
void skip_width(int width, const char **ptr);
void *get_int_ptr(va_list args, Options opt);
void *get_unsigned_int_ptr(va_list args, Options opt);
void *get_float_ptr(va_list args, Options opt);
void assign_unsigned_int_result(void *uint_ptr, unsigned long long result,
                                Options opt);
void assign_float_result(void *float_ptr, double value, Options opt);
#endif