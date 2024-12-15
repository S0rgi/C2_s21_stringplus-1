#include "s21_sprintf.h"

#include <math.h>

#include "s21_string.h"

void check_resize(char *buf, s21_size_t *max_size) {
  if (s21_strlen(buf) > *max_size / 2) {
    *max_size *= 2;
    char *temp = realloc(buf, *max_size);
    if (temp) {
      buf = temp;
    } else {
      free(temp);
    }
  }
}

void wchar_to_str(char *str, flags fl, wchar_t c, s21_size_t *max_size) {
  if (fl.minus) {
    wcstombs(str, &c, *max_size);
    int a = s21_strlen(str);
    for (int i = a; i < fl.width; i++) {
      *(str + i) = fl.specifier;
    }
  } else {
    char *buff = malloc(*max_size);
    *buff = '\0';
    wcstombs(buff, &c, *max_size);
    int size = fl.width - s21_strlen(buff);
    for (int i = 0; i < size; i++) {
      *(str + i) = fl.specifier;
    }
    wcstombs(str, &c, *max_size);
    free(buff);
  }
  str++;
  *str = '\0';
}

void char_to_str(char *str, flags fl, char c) {
  if (fl.minus) {
    *str = c;
    str++;
    for (int i = 1; i < fl.width; i++) {
      *(str + i) = fl.specifier;
    }
  } else {
    for (int i = 1; i < fl.width; i++) {
      *(str + i) = fl.specifier;
    }
    *str = c;
  }
  str++;
  *str = '\0';
}

void process_char(char *str, flags fl, va_list args, s21_size_t *max_size) {
  if (fl.length == 'l') {
    wchar_t c = va_arg(args, wchar_t);
    wchar_to_str(str, fl, c, max_size);
  } else {
    char c = va_arg(args, int);
    char_to_str(str, fl, c);
  }
}

void int_to_str(char *str, flags fl, __int64_t num, s21_size_t *max_size) {
  char *buff = malloc(*max_size);
  int digit_count = 0, minus = 0;
  __int64_t cpy = num;
  if (num < 0) {
    num *= -1;
    minus = 1;
  }
  if (cpy == 0 && fl.precision != -1 && fl.precision != -2) {
    buff[digit_count++] = '0';
  }
  while (num > 0) {
    int digit = num % 10;
    buff[digit_count++] = (char)('0' + digit);
    num -= digit;
    num /= 10;
  }
  if (fl.space && fl.plus == 0 && cpy >= 0 && fl.precision <= 0) {
    buff[digit_count++] = ' ';
  }
  int_to_arr(str, fl, digit_count, buff, minus);
  free(buff);
}

void int_to_arr(char *str, flags fl, int digit_count, char *buff, int minus) {
  if (fl.precision) {
    fl.precision -= digit_count;
    for (int i = 0; i < fl.precision; i++) {
      buff[digit_count++] = '0';
    }
  }
  if (minus) {
    buff[digit_count++] = '-';
  }
  if (fl.plus && minus == 0) {
    buff[digit_count++] = '+';
  }

  int dobavleno = 0;
  if (fl.minus) {
    char *copy_str = str + digit_count;
    for (int i = digit_count; i < fl.width; i++) {
      *copy_str = fl.specifier;
      copy_str++;
      dobavleno++;
    }
    *copy_str = '\0';
  }
  if (fl.minus == 0) {
    for (int i = digit_count; i < fl.width; i++) {
      buff[digit_count++] = fl.specifier;
    }
  }

  for (digit_count--; digit_count >= 0; digit_count--) {
    *str++ = buff[digit_count];
  }

  *(str + dobavleno) = '\0';
}

void process_int(char *str, flags fl, va_list args, s21_size_t *max_size) {
  __int64_t num = va_arg(args, __int64_t);
  switch (fl.length) {
    case 0:
      num = (__int32_t)num;
      break;
    case 'h':
      num = (__int16_t)num;
  }
  int_to_str(str, fl, num, max_size);
}

void float_to_str(char *str, flags fl, double num, s21_size_t *max_size) {
  long double cpy, frac;
  long long int w_num = (long long int)num, digit_count, minus = 0;
  char *buff = malloc(*max_size);
  *buff = '\0';
  if (fl.precision == 0) {
    fl.precision = 6;
  }
  if (num < 0) {
    num *= -1;
    minus = 1;
    w_num *= -1;
  }
  cpy = modfl(num, &frac);

  long long int t = num + 0.1;
  if (fl.precision < 4 && t == w_num + 1 && fl.plus == 0 && fl.minus) {
    w_num++;
  }

  for (int i = 0; i < fl.precision; i++) {
    cpy *= 10.0;
  }

  if (fl.precision > -1) {
    cpy = roundl(cpy);
  } else {
    if (cpy > 0.5) {
      cpy = round(cpy);
    } else {
      cpy = (long long int)num;
    }
  }

  if (fl.space && fl.plus == 0 && minus == 0) {
    *str++ = ' ';
    fl.width--;
  }

  if (minus && fl.precision > 0 && w_num + 1 == cpy * 10) {
    w_num++;
  }

  digit_count = float_to_arr(str, buff, fl, num, cpy, w_num, minus);

  for (digit_count--; digit_count >= 0; digit_count--) {
    *str++ = buff[digit_count];
  }
  *str = '\0';
  free(buff);
}

int float_to_arr(char *str, char *buf, flags fl, double num, double cpy,
                 long long int w_num, int minus) {
  int digit, i = 0, digit_count = 0;
  for (; i < fl.precision && fl.precision != -1; i++, digit_count++) {
    digit = fmodl(cpy, 10);
    buf[digit_count] = (char)('0' + digit);
    cpy -= digit;
    cpy /= 10;
  }
  if (fl.precision > 0) {
    buf[digit_count++] = '.';
    if (num < 1 && -1 < num && (fl.plus || fl.minus) && num != 0) {
      buf[digit_count++] = '1';
    }
    if (num < 1 && -1 < num) {
      buf[digit_count++] = '0';
    }

    while (w_num) {
      digit = w_num % 10;
      buf[digit_count++] = (char)('0' + digit);
      w_num -= digit;
      w_num /= 10;
    }
  } else {
    while (cpy >= 1) {
      digit = fmodl(roundl(cpy), 10);
      buf[digit_count++] = digit + '0';
      cpy -= digit;
      cpy /= 10;
    }
  }
  if (minus) buf[digit_count++] = '-';
  if (fl.plus && minus == 0) {
    buf[digit_count++] = '+';
  }
  if (fl.minus == 0) {
    for (w_num = digit_count; w_num < fl.width; w_num++, digit_count++) {
      buf[w_num] = fl.specifier;
    }
  } else {
    char *str_cpy = str + digit_count;
    for (w_num = digit_count; w_num < fl.width; w_num++, digit_count++) {
      *str_cpy = fl.specifier;
    }
  }
  return digit_count;
}

void process_float(char *str, flags fl, va_list args, s21_size_t *max_size) {
  long double num;
  num = va_arg(args, double);
  if (num != num) {
    s21_strcpy(str, "-nan");
  } else if (num == INFINITY) {
    s21_strcpy(str, "inf");
  } else if (num == -INFINITY) {
    s21_strcpy(str, "-inf");
  } else {
    float_to_str(str, fl, num, max_size);
  }
}

void wchar_t_str_str(char *str, flags fl, wchar_t *c, s21_size_t *max_size) {
  char *buf = malloc(*max_size);
  wcstombs(buf, c, *max_size);
  if (fl.precision) {
    buf[fl.precision] = '\0';
  }
  int a = s21_strlen(buf);
  if (fl.minus) {
    wcstombs(str, c, *max_size);
    s21_strcpy(str, buf);
    for (int i = a; i < fl.width; i++) {
      *(str + i) = fl.specifier;
    }
  } else {
    for (int i = a; i < fl.width; i++) {
      *(str + i) = fl.specifier;
    }
    wcstombs(str, c, *max_size);
    s21_strcpy(str, buf);
  }
  free(buf);
}

void str_str(char *str, flags fl, char *c, s21_size_t *max_size) {
  char *buf = malloc(*max_size);

  s21_strcpy(buf, c);
  int a = s21_strlen(buf);
  if (fl.precision) {
    buf[fl.precision] = '\0';
  }

  if (fl.precision < 0) {
    fl.width = a + fl.width;
  }
  if (fl.minus) {
    if (fl.precision != -2) {
      s21_strcpy(str, buf);
    }
    for (int i = a; i < fl.width; i++) {
      *(str + i) = fl.specifier;
    }
  } else {
    for (int i = a; i < fl.width; i++) {
      *(str + i) = fl.specifier;
    }
    if (fl.precision >= 0) {
      s21_strcpy(str, buf);
    }
  }
  free(buf);
}

void process_string(char *str, flags fl, va_list args, s21_size_t *max_size) {
  if (fl.length == 'l') {
    wchar_t *c = va_arg(args, wchar_t *);
    wchar_t_str_str(str, fl, c, max_size);
  } else {
    char *c = va_arg(args, char *);
    str_str(str, fl, c, max_size);
  }
}

void uint_t_str(char *str, flags fl, unsigned long num, s21_size_t *max_size) {
  char *buf = malloc(*max_size);
  *buf = '\0';
  int digit_count = 0;
  unsigned long cpy = num;
  if (cpy == 0 && fl.precision > -1) {
    buf[digit_count++] = '0';
  }
  if (fl.plus) fl.plus = 0;
  while (num) {
    int digit = num % 10;
    buf[digit_count++] = '0' + digit;
    num -= digit;
    num /= 10;
  }
  int_to_arr(str, fl, digit_count, buf, 0);
  free(buf);
}

void process_uint(char *str, flags fl, va_list args, s21_size_t *max_size) {
  __uint64_t num = va_arg(args, __uint64_t);
  switch (fl.length) {
    case 'h':
      num = (__uint16_t)num;
      break;
    case 'l':
      num = (__uint64_t)num;
      break;
    case 0:
      num = (__uint32_t)num;
      break;
  }
  uint_t_str(str, fl, num, max_size);
}

int is_num(const char format) { return (format >= '0' && format <= '9'); }

int is_specs(const char *format) {
  int res = 0, res2 = 0;
  const char specs[100] = {'c', 'd', 'f', 's', 'u', '%'};
  const char flags[100] = {'+', '-', ' ', '.', '0', '1', '2',
                           '3', '4', '5', '6', '7', '8', '9'};
  res = s21_strcspn(format, specs);
  res2 = s21_strcspn(format, flags);

  if (res == res2) {
    res = 0;
  }
  return res;
}

const char *parsing_flags(const char *format, flags *fl) {
  fl->specifier = ' ';
  while (*format == '-' || *format == '+' || *format == ' ') {
    if (*format == '-') {
      fl->minus = 1;
    }
    if (*format == '+') {
      fl->plus = 1;
    }
    if (*format == ' ') {
      fl->space = 1;
    }
    format++;
  }
  if (fl->minus) {
    fl->specifier = ' ';
  }

  return format;
}

const char *paring_width(const char *format, flags *fl) {
  int res = 0;
  if (is_num(*format)) {
    while (*format && is_num(*format)) {
      res = res * 10 + (*format - '0');
      format++;
    }
  }
  fl->width = res;
  return format;
}

const char *parsing_prec(const char *format, flags *fl) {
  int res = 0;
  if (*format == '.') {
    format++;
    if (is_num(*format)) {
      while (*format && is_num(*format)) {
        res = res * 10 + (*format - '0');
        format++;
      }
      if (res == 0) {
        res = -1;
      }
    } else {
      res = -2;
    }
  }
  fl->precision = res;
  return format;
}

const char *parsing_len(const char *format, flags *fl) {
  if (*format == 'h') {
    fl->length = 'h';
    format++;
  } else if (*format == 'l') {
    fl->length = 'l';
    format++;
  }
  return format;
}

void parsing_specs(char format, char *buf, flags fl, va_list args,
                   s21_size_t *max_size) {
  if (format == 'c') {
    process_char(buf, fl, args, max_size);
  }
  if (format == 'd') {
    process_int(buf, fl, args, max_size);
  }
  if (format == 'f') {
    process_float(buf, fl, args, max_size);
  }
  if (format == 's') {
    process_string(buf, fl, args, max_size);
  }
  if (format == 'u') {
    process_uint(buf, fl, args, max_size);
  }
  if (format == '%') {
    *buf++ = '%';
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  char *str_begin = str;
  s21_size_t max_size = 1024;

  va_list args;
  va_start(args, format);
  while (*format != '\0') {
    char *buf = malloc(max_size);
    flags fl = {0};

    if (*format == '%') {
      format++;
      while (is_specs(format)) {
        format = parsing_flags(format, &fl);
        format = paring_width(format, &fl);
        format = parsing_prec(format, &fl);
        format = parsing_len(format, &fl);
      }
      parsing_specs(*format, buf, fl, args, &max_size);
      format++;
      for (int i = 0; buf[i] != '\0'; i++, str++) {
        *str = buf[i];
      }
    } else {
      *str = *format;
      str++;
      format++;
    }
    free(buf);
  }
  va_end(args);
  *str = '\0';
  return str - str_begin;
}
