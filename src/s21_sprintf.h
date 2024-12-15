#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

typedef unsigned long s21_size_t;

typedef struct {
  int minus;
  int plus;
  int space;
  int width;
  int precision;
  char specifier;
  char length;
} flags;

void check_resize(char* buf, s21_size_t* max_size);
void wchar_to_str(char* str, flags fl, wchar_t c, s21_size_t* max_size);
void char_to_str(char* str, flags fl, char c);
void process_char(char* str, flags fl, va_list args, s21_size_t* max_size);
void int_to_str(char* str, flags fl, __int64_t num, s21_size_t* max_size);
void int_to_arr(char* str, flags fl, int digit_count, char* buff, int minus);
void process_int(char* str, flags fl, va_list args, s21_size_t* max_size);
void float_to_str(char* str, flags fl, double num, s21_size_t* max_size);
int float_to_arr(char* str, char* buf, flags fl, double num, double cpy,
                 long long int w_num, int minus);
void process_float(char* str, flags fl, va_list args, s21_size_t* max_size);
void wchar_t_str_str(char* str, flags fl, wchar_t* c, s21_size_t* max_size);
void str_str(char* str, flags fl, char* c, s21_size_t* max_size);
void process_string(char* str, flags fl, va_list args, s21_size_t* max_size);
void uint_t_str(char* str, flags fl, unsigned long num, s21_size_t* max_size);
void process_uint(char* str, flags fl, va_list args, s21_size_t* max_size);
int is_num(const char format);
int is_specs(const char* format);
const char* parsing_flags(const char* format, flags* fl);
const char* paring_width(const char* format, flags* fl);
const char* parsing_prec(const char* format, flags* fl);
const char* parsing_len(const char* format, flags* fl);
void parsing_specs(char format, char* buf, flags fl, va_list args,
                   s21_size_t* max_size);
int s21_sprintf(char* str, const char* format, ...);

#endif