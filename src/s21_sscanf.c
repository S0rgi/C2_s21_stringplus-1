#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void spec_parse(const char *spec, const char **str, va_list args, int width);
int process_width(const char *format, int *width);
void process_d(va_list args, const char **str, int width);
void process_i(va_list args, const char **str, int width);
void process_s(va_list args, const char **str, int width);
void process_f(va_list args, const char **str, int width);
void process_c(va_list args, const char **str, int width);
void process_o(va_list args, const char **str, int width);
void process_x(va_list args, const char **str, int width);
void process_p(va_list args, const char **str, int width);
void process_n(va_list args, const char **str, int width);
void process_u(va_list args, const char **str, int width);
void process_percent(const char **str);
int s21_atoi(const char *str);
float s21_atof(const char *str);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  const char *ptr = str;
  int count = 0;
  int fail = 0;

  while (!fail && *format) {
    if (*format == ' ') {
      while (*format == ' ') {
        format++;
        ptr++;
      }
    } else if (*format == '%') {
      format++;
      int width = -1;
      int skip = 0;

      if (*format == '*') {
        skip = 1;
        format++;
      }

      if (*format >= '0' && *format <= '9') {
        format += process_width(format, &width);
      }

      if (skip) {
        if (width != -1) {
          ptr += width - 1;
        } else {
          while (*ptr && *ptr != ' ') {
            ptr++;
          }
        }
      } else {
        spec_parse(format, &ptr, args, width);
      }

      while (*format && *format != ' ') format++;
      count++;
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

void spec_parse(const char *spec, const char **str, va_list args, int width) {
  // https://codelessons.dev/ru/scanf-in-c-cplusplus/#%D1%82%D0%B8%D0%BF
  switch (*spec) {
    case '%':
      process_percent(str);
      break;
    case 'd':
      process_d(args, str, width);
      break;
    case 's':
      process_s(args, str, width);
      break;
    case 'c':
      process_c(args, str, width);
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
      process_p(args, str, width);
      break;
    case 'n':
      process_n(args, str, width);
      break;
    default:
      break;
  }
}
int process_width(const char *spec, int *width) {
  char num[10];
  int i = 0;
  for (; *spec >= '0' && *spec <= '9' && i < sizeof(num); i++) {
    num[i] = *spec;
    *(spec)++;
  }
  num[i] = '\0';
  *width = s21_atoi(num);
  return i;
}
void process_percent(const char **str) {
  if (**str == '%') {
    (*str)++;
  }
}

void process_d(va_list args, const char **str, int width) {
  int *int_ptr = va_arg(args, int *);
  if (int_ptr == s21_NULL) return;
  char num[20];
  int i = 0;
  int pos = 1;
  if (**str == '-') {
    pos = -1;
    (*str)++;
  } else if (**str == '+') {
    pos = 1;
    (*str)++;
  }
  while ((width == -1 || i < width) && **str >= '0' && **str <= '9' &&
         i < (int)sizeof(num) - 1) {
    num[i++] = **str;
    (*str)++;
  }
  num[i] = '\0';
  *int_ptr = pos * s21_atoi(num);
}
int s21_atoi(const char *str) {
  int result = 0;
  while (*str >= '0' && *str <= '9') {
    result = result * 10 + (*str - '0');
    str++;
  }
  return result;
}

void process_s(va_list args, const char **str, int width) {
  char *str_ptr = va_arg(args, char *);
  int i = 0;

  while (**str != ' ' && **str != '\0' && i < 99) {
    str_ptr[i++] = **str;
    (*str)++;
  }
  str_ptr[i] = '\0';
}

void process_f(va_list args, const char **str, int width) {
  float *float_ptr = va_arg(args, float *);
  if (float_ptr == s21_NULL) return;

  char num[50];
  int i = 0;
  int pos = 1;
  int exp = 1;
  if (**str == '-') {
    pos = -1;
    (*str)++;
  } else if (**str == '+') {
    (*str)++;
  }
  int fail = 0;
  while (!fail && ((**str >= '0' && **str <= '9') || **str == '.' ||
                   **str == 'e' || **str == 'E' || **str == '-')) {
    if (**str == 'e' || **str == 'E') {
      (*str)++;
      char exp_str[10];
      int exp_i = 0;

      if (**str == '-') {
        exp = -1;
        (*str)++;
      } else if (**str == '+') {
        (*str)++;
      }
      while ((**str >= '0' && **str <= '9')) {
        exp_str[exp_i++] = **str;
        (*str)++;
      }
      exp_str[exp_i] = '\0';
      exp *= pow(10, s21_atoi(exp_str));
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
    *float_ptr = pos * exp * (float)s21_atof(num);
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

void process_c(va_list args, const char **str, int width) {
  char *char_ptr = va_arg(args, char *);
  if (**str != '\0') {
    *char_ptr = **str;
    (*str)++;
  }
}
void process_o(va_list args, const char **str, int width) {
  int *int_ptr = va_arg(args, int *);
  if (int_ptr == s21_NULL) return;

  int result = 0;
  int base = 1;
  if (**str == '-') {
    base = -1;
    (*str)++;
  }
  int fail = 0;
  s21_size_t len = s21_strlen(*str);
  for (s21_size_t i = len - 1; i < len && !fail; i--) {
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
void process_x(va_list args, const char **str, int width) {
  int *int_ptr = va_arg(args, int *);
  if (int_ptr == s21_NULL) return;
  int sign = 1;
  int result = 0;
  int base = 1;
  int fail = 0;
  s21_size_t len = s21_strlen(*str);
  if (*str[0] == '-') {
    sign = -1;
    (*str)++;
    len--;
  }

  if (len >= (s21_size_t)(2) && (*str)[0] == '0' &&
      ((*str)[1] == 'x' || (*str)[1] == 'X')) {
    *str += 2;
    len -= 2;
  }
  for (s21_size_t i = len - 1; i < len && !fail; i--) {
    if ((*str)[i] >= '0' && (*str)[i] <= '9') {
      result += ((*str)[i] - '0') * base;
    } else if ((*str)[i] >= 'a' && (*str)[i] <= 'f') {
      result += ((*str)[i] - 'a' + 10) * base;
    } else if ((*str)[i] >= 'A' && (*str)[i] <= 'F') {
      result += ((*str)[i] - 'A' + 10) * base;
    } else {
      result = 0;
      fail = 1;
    }
    base *= 16;
  }
  *int_ptr = result * sign;

  *str += len;
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
  unsigned int base = 1;
  int fail = 0;
  s21_size_t len = s21_strlen(*str);

  for (s21_size_t i = len; i-- > 0 && !fail;) {
    if ((*str)[i] >= '0' && (*str)[i] <= '9') {
      result += ((*str)[i] - '0') * base;
    } else {
      result = 0;
      fail = 1;
    }
    base *= 10;
  }

  *uint_ptr = result;
  *str += len;
}

void process_p(va_list args, const char **str, int width) {
  void **ptr_ptr = va_arg(args, void **);
  if (ptr_ptr == s21_NULL) return;

  unsigned long long result = 0;
  unsigned long long base = 1;
  int fail = 0;
  s21_size_t len = s21_strlen(*str);

  if (len >= 2 && (*str)[0] == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X')) {
    *str += 2;
    len -= 2;
  }

  for (s21_size_t i = len; i-- > 0 && !fail;) {
    if ((*str)[i] >= '0' && (*str)[i] <= '9') {
      result += ((*str)[i] - '0') * base;
    } else if ((*str)[i] >= 'a' && (*str)[i] <= 'f') {
      result += ((*str)[i] - 'a' + 10) * base;
    } else if ((*str)[i] >= 'A' && (*str)[i] <= 'F') {
      result += ((*str)[i] - 'A' + 10) * base;
    } else {
      result = 0;
      fail = 1;
    }
    base *= 16;
  }

  *ptr_ptr = (void *)result;
  *str += len;
}

void process_n(va_list args, const char **str, int width) {
  int *count_ptr = va_arg(args, int *);
  if (count_ptr == s21_NULL) return;

  *count_ptr = s21_strlen(*str);
}
