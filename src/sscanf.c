#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void spec_parse(const char *spec, const char **str, va_list args);
int str_to_int(const char *str);
void process_d(va_list args, const char **str);
void process_s(va_list args, const char **str);
void process_f(va_list args, const char **str);
void process_c(va_list args, const char **str);
void process_o(va_list args, const char **str);
void process_x(va_list args, const char **str);
void process_p(va_list args, const char **str);
void process_n(va_list args, const char **str);
int main() {
  const char *input = "1733 21.5 L lol 1733";
  float number_f;
  int number_d;
  int number_o;
  char ch;
  char arr[20];
  int count = s21_sscanf(input, "%d %f %c %s %o", &number_d, &number_f, &ch,
                         arr, &number_o);
  printf("Number-int_d: %d\n", number_d);
  printf("Number-int_o: %d\n", number_o);
  printf("Number-float: %f\n", number_f);
  printf("Char: %c\n", ch);
  printf("Str: %s\n", arr);
  printf("Values read: %d\n", count);

  return 0;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *ptr = str;
  int count = 0;

  while (*format) {
    if (*format == ' ') {
      while (*format == ' ') format++;
      while (*ptr == ' ') ptr++;
    } else if (*format == '%') {
      format++;
      spec_parse(format, &ptr, args);
      while (*format && *format != ' ') format++;
      count++;
    } else {
      if (*ptr != *format) {
        break;
      }
      ptr++;
      format++;
    }
  }

  va_end(args);
  return count;
}

void spec_parse(const char *spec, const char **str, va_list args) {
  // https://codelessons.dev/ru/scanf-in-c-cplusplus/#%D1%82%D0%B8%D0%BF
  switch (*spec) {
    case 'd':
      process_d(args, str);
      break;
    case 's':
      process_s(args, str);
      break;
    case 'c':
      process_c(args, str);
      break;
    case 'i':
      process_d(args, str);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      process_f(args, str);
      break;
    case 'o':
      process_o(args, str);
      break;
    case 'u':
      break;
    case 'x':
    case 'X':
      // process_x(args, str);
      break;
    case 'p':
      // process_p(args, str);
      break;
    case 'n':
      // process_n(args, str);
      break;
    default:
      break;
  }
}

int str_to_int(const char *str) {
  int sign = 1;
  int result = 0;

  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }

  while (*str >= '0' && *str <= '9') {
    result = result * 10 + (*str - '0');
    str++;
  }

  return sign * result;
}

void process_d(va_list args, const char **str) {
  int *int_ptr = va_arg(args, int *);
  char num[20];
  int i = 0;

  while (**str >= '0' && **str <= '9' && i < (int)sizeof(num) - 1) {
    num[i++] = **str;
    (*str)++;
  }
  num[i] = '\0';
  *int_ptr = str_to_int(num);
}

void process_s(va_list args, const char **str) {
  char *str_ptr = va_arg(args, char *);
  int i = 0;

  while (**str != ' ' && **str != '\0' && i < 99) {
    str_ptr[i++] = **str;
    (*str)++;
  }
  str_ptr[i] = '\0';
}

void process_f(va_list args, const char **str) {
  float *float_ptr = va_arg(args, float *);
  char num[20];
  int i = 0;

  while ((**str >= '0' && **str <= '9') || **str == '.' || **str == '-' ||
         **str == '+') {
    if (i < (int)sizeof(num) - 1) {
      num[i++] = **str;
      (*str)++;
    } else {
      break;
    }
  }

  num[i] = '\0';

  if (i > 0) {
    *float_ptr = (float)atof(num);
  } else {
    *float_ptr = 0.0f;
  }
}
void process_c(va_list args, const char **str) {
  char *char_ptr = va_arg(args, char *);
  if (**str != '\0') {
    *char_ptr = **str;
    (*str)++;
  }
}
void process_o(va_list args, const char **str) {
  int *int_ptr = va_arg(args, int *);
  if (int_ptr == s21_NULL) return;

  int result = 0;
  int base = 1;
  int fail = 0;
  s21_size_t len = s21_strlen(*str);
  for (s21_size_t i = len - 1; !fail && i >= 0; i--) {
    if ((*str)[i] >= '0' && (*str)[i] <= '7') {
      result += ((*str)[i] - '0') * base;
      base *= 8;
    } else {
      result = 0;
      fail = 1;
    }
  }
  *int_ptr = result;
  *str += len;
}
