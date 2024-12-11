#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H 
#include <stdarg.h>
#include <math.h>

typedef struct {
    int minus;
    int plus;
    int space;
    int width;
    int precision;
    char specifier;
    char length;
} flags;

void wchar_to_str(char* str, flags fl, wchar_t c);
void char_to_str(char* str, flags fl, char c);
void process_int(char* str, flags fl, va_list args);
void int_to_str(char* str, flags fl, __int64_t num);
void int_to_arr(char* str, flags fl, int digit_count, char* buff, int minus);
void process_float(char* str, flags fl, va_list args);
void float_to_str(char* str, flags fl, double num);
int float_to_arr(char* str, char* buf, flags fl, double num, double cpy, long long int w_num, int minus);
void process_string(char* str, flags fl, va_list args);
void wchar_t_str_str(char* str, flags fl, wchar_t* c);
void str_str(char* str, flags fl, char* c);
void process_uint(char* str, flags fl, va_list args);
void uint_t_str(char* str, flags fl, unsigned long num);
int is_specs(const char format);
const char* parsing_flags(const char* format, flags* fl);
const char* paring_width(const char* format, flags* fl);
const char* parsing_prec(const char* format, flags* fl);
const char* parsing_len(const char* format, flags* fl);
int is_num(const char format);
void parsing_specs(char format, char* buf, char* str_begin, char* str, flags fl, va_list args);
#endif