#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"
void spec_parse(const char **format, const char **str, va_list args, int width,
                const char *nach_str, int *count);
void process_width(const char **format, int *width);
void process_d(va_list args, const char **str, int width);
void process_i(va_list args, const char **str, int width);
void process_s(va_list args, const char **str, int width);
void process_f(va_list args, const char **str, int width);
void process_c(va_list args, const char **str);
void process_o(va_list args, const char **str, int width);
void process_x(va_list args, const char **str, int width);
void process_p(va_list args, const char **str);
void process_n(va_list args, const char **str, const char *nach_str);
void process_u(va_list args, const char **str, int width);
void parce_width(const char **format);
void process_percent(const char **str, const char **format);
float s21_atof(const char *str);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *ptr = str;
  int count = 0;
  int fail = 0;

  while (!fail && *format) {
    if (*format == ' ') {
      for (; *format == ' '; format++, ptr++) {
      }
    } else if (*format == '%') {
      format++;
      int width = -1;
      int skip = 0;
      if (*format == '*') {
        skip = 1;
        format++;
      }
      process_width(&format, &width);
      parce_width(&format);
      if (skip) {
        if (width != -1) {
          ptr += width - 1;
        } else {
          while (*ptr && *ptr != ' ') {
            ptr++;
          }
        }
      } else {
        spec_parse(&format, &ptr, args, width, str, &count);
      }

      while (*format && *format != ' ' && *format != '%') format++;
    } else {
      if (*ptr != *format) {
        fail = 1;
      }
      ptr++;
      format++;
    }
  }
  va_end(args);
  return count;
}
void parce_width(const char **format) {
  for (; **format == 'h' || **format == 'l' || **format == 'L'; (*format)++) {
  }
}
void spec_parse(const char **format, const char **str, va_list args, int width,
                const char *nach_str, int *count) {
  // https://codelessons.dev/ru/scanf-in-c-cplusplus/#%D1%82%D0%B8%D0%BF
  switch (**format) {
    case '%':
      process_percent(str, format);
      count--;
      break;
    case 'd':
      process_d(args, str, width);
      break;
    case 's':
      process_s(args, str, width);
      break;
    case 'c':
      process_c(args, str);
      break;
    case 'i':
      process_i(args, str, width);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      process_f(args, str, width);
      break;
    case 'o':
      process_o(args, str, width);
      break;
    case 'u':
      process_u(args, str, width);
      break;
    case 'x':
    case 'X':
      process_x(args, str, width);
      break;
    case 'p':
      process_p(args, str);
      break;
    case 'n':
      process_n(args, str, nach_str);
      (*count)--;
      break;
    default:
      break;
  }
  (*count)++;
}
void process_width(const char **format, int *width) {
  int result = 0;
  for (; **format >= '0' && **format <= '9'; (*format)++) {
    result = result * 10 + (int)(*(*format) - '0');
  }
  *width = result != 0 ? result : -1;
}

void process_percent(const char **str, const char **format) {
  if (**str == '%') {
    (*str)++;
    (*format)++;
  }
}
void process_d(va_list args, const char **str, int width) {
  int *int_ptr = va_arg(args, int *);
  if (int_ptr == NULL) return;
  int i = 0;
  int pos = 1;
  int result = 0;
  if (**str == '-') {
    pos = -1;
    (*str)++;
  } else if (**str == '+') {
    pos = 1;
    (*str)++;
  }
  while ((width == -1 || i < width) && **str >= '0' && **str <= '9') {
    result = result * 10 + (int)(*(*str) - '0');
    (*str)++;
    i++;
  }
  *int_ptr = pos * result;
}

void process_s(va_list args, const char **str, int width) {
  char *str_ptr = va_arg(args, char *);
  int i = 0;

  while ((width == -1 || i < width) && **str != ' ' && **str != '\0' &&
         i < 99) {
    str_ptr[i++] = **str;
    (*str)++;
  }
  str_ptr[i] = '\0';
}

void process_f(va_list args, const char **str, int width) {
  float *float_ptr = va_arg(args, float *);
  if (float_ptr == NULL) return;

  char num[50];
  int i = 0;
  int pos = 1;
  int exponent = 0;
  int exp_pos = 1;

  if (**str == '-') {
    pos = -1;
    (*str)++;
  } else if (**str == '+') {
    (*str)++;
  }
  int fail = 0;
  while (!fail && (width == -1 || i < width) &&
         ((**str >= '0' && **str <= '9') || **str == '.' || **str == 'e' ||
          **str == 'E' || **str == '-')) {
    if (**str == 'e' || **str == 'E') {
      (*str)++;
      if (**str == '-') {
        exp_pos = -1;
        (*str)++;
      } else if (**str == '+') {
        (*str)++;
      }
      int ex_count = 1;
      while (**str >= '0' && **str <= '9' &&
             (width == -1 || i + ex_count < width)) {
        exponent = exponent * 10 + (**str - '0');
        (*str)++;
        ex_count++;
      }
      exponent *= exp_pos;
      fail = 1;
    } else if (i < (int)sizeof(num) - 1) {
      num[i++] = **str;
      (*str)++;
    } else {
      fail = 1;
    }
  }

  if (i > 0) {
    num[i] = '\0';
    *float_ptr = pos * (float)s21_atof(num) * pow(10, exponent);
  } else {
    *float_ptr = 0.0f;
  }
}

float s21_atof(const char *str) {
  float result = 0.0f;
  float fraction = 0.0f;
  int fraction_divisor = 1;
  while (*str >= '0' && *str <= '9') {
    result = result * 10 + (*str - '0');
    str++;
  }
  if (*str == '.') {
    str++;
    while (*str >= '0' && *str <= '9') {
      fraction = fraction * 10 + (*str - '0');
      fraction_divisor *= 10;
      str++;
    }
  }
  result += fraction / fraction_divisor;
  return result;
}

void process_c(va_list args, const char **str) {
  char *char_ptr = va_arg(args, char *);
  if (**str != '\0') {
    *char_ptr = **str;
    (*str)++;
  }
}

void process_o(va_list args, const char **str, int width) {
  unsigned int *int_ptr = va_arg(args, unsigned int *);
  if (int_ptr == s21_NULL) return;
  unsigned int result = 0;
  int sign = 1;
  if (**str == '-') {
    sign = -1;
    (*str)++;
  }
  while (**str && (width == -1 || width-- > 0) &&
         (**str >= '0' && **str <= '7')) {
    result = result * 8 + (**str - '0');
    (*str)++;
  }
  *int_ptr = result * sign;
  printf("in ptr: %d\n", *int_ptr);
}

void process_x(va_list args, const char **str, int width) {
  unsigned int *int_ptr = va_arg(args, unsigned int *);
  if (int_ptr == s21_NULL) return;
  int sign = 1;
  unsigned int result = 0;
  if (**str == '-') {
    sign = -1;
    (*str)++;
  }
  if (**str == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X')) {
    *str += 2;
  }

  while (**str && (width == -1 || width-- > 0) &&
         ((**str >= '0' && **str <= '9') || (**str >= 'a' && **str <= 'f') ||
          (**str >= 'A' && **str <= 'F'))) {
    if (**str >= '0' && **str <= '9') {
      result = result * 16 + (**str - '0');
      (*str)++;
    } else if (**str >= 'a' && **str <= 'f') {
      result = result * 16 + (**str - 'a' + 10);
      (*str)++;
    } else if (**str >= 'A' && **str <= 'F') {
      result = result * 16 + (**str - 'A' + 10);
      (*str)++;
    }
  }
  *int_ptr = result * sign;
}
void process_i(va_list args, const char **str, int width) {
  s21_size_t len = s21_strlen(*str);
  int pos = (len > 0 && *str[0] == '-') ? 1 : 0;
  if (len >= (s21_size_t)(2 + pos) && (*str)[0 + pos] == '0' &&
      ((*str)[1 + pos] == 'x' || (*str)[1 + pos] == 'X'))
    process_x(args, str, width);
  else if (len >= (s21_size_t)(1 + pos) && (*str)[0 + pos] == '0')
    process_o(args, str, width);
  else
    process_d(args, str, width);
}
void process_u(va_list args, const char **str, int width) {
  unsigned int *uint_ptr = va_arg(args, unsigned int *);
  if (uint_ptr == s21_NULL) return;

  unsigned int result = 0;

  while (**str && (width == -1 || width-- > 0) &&
         (**str >= '0' && **str <= '9')) {
    if (**str >= '0' && **str <= '9') {
      result = result * 10 + (**str - '0');
      (*str)++;
    }
  }

  *uint_ptr = result;
}

void process_p(va_list args, const char **str) {
  void **ptr_ptr = va_arg(args, void **);
  if (ptr_ptr == NULL) return;

  unsigned long long result = 0;
  int fail = 0;

  if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    *str += 2;
  }

  while ((**str >= '0' && **str <= '9') || (**str >= 'a' && **str <= 'f') ||
         (**str >= 'A' && **str <= 'F')) {
    result *= 16;
    if (**str >= '0' && **str <= '9') {
      result += (**str - '0');
    } else if (**str >= 'a' && **str <= 'f') {
      result += (**str - 'a' + 10);
    } else if (**str >= 'A' && **str <= 'F') {
      result += (**str - 'A' + 10);
    }
    (*str)++;
  }

  *ptr_ptr = (void *)result;
}

void process_n(va_list args, const char **str, const char *nach_str) {
  int *count_ptr = va_arg(args, int *);
  if (count_ptr == s21_NULL) return;

  *count_ptr = fabs(nach_str - (*str));
}
