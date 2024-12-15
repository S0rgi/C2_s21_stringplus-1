#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = (const unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    if (ptr[i] == (unsigned char)c) {
      return (void *)(ptr + i);
    }
  }

  return s21_NULL;
}
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; result == 0 && i < n; i++) {
    if (((const unsigned char *)str1)[i] != ((const unsigned char *)str2)[i])
      result =
          ((const unsigned char *)str1)[i] - ((const unsigned char *)str2)[i];
  }
  return result;
}
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    s[i] = (unsigned char)c;
  }
  return str;
}
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (src == NULL) {
    // Не более одного выхода из функции. Исключение составляет предварительная
    // проверка аргументов функции.
    return dest;
  }
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t i = 0;

  if (n > 0) {
    while (i < n && src[i] != '\0') {
      dest[dest_len + i] = src[i];
      i++;
    }
    dest[dest_len + i] = '\0';
  }

  return dest;
}

char *s21_strchr(const char *str, int c) {
  return (char *)s21_memchr(str, c, s21_strlen(str) + 1);
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    unsigned char c1 = (unsigned char)str1[i];
    unsigned char c2 = (unsigned char)str2[i];
    if (c1 != c2) {
      result = c1 - c2;
    }
    if (c1 == '\0' || c2 == '\0') {
      if (result == 0) {
        result = c1 - c2;
      }
    }
  }

  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (src == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  for (; i < n; i++) {
    dest[i] = '\0';
  }

  return dest;
}

char *s21_strcpy(char *dest, const char *src) {
  if (src == s21_NULL) {
    // Не более одного выхода из функции. Исключение составляет предварительная
    // проверка аргументов функции.
    return s21_NULL;
  }
  s21_size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int found = 0;

  for (s21_size_t i = 0; !found && i < s21_strlen(str1); i++) {
    if (s21_strchr(str2, str1[i]) != s21_NULL) {
      found = 1;
    }
    if (!found) result++;
  }
  return result;
}

char *s21_strerror(int errnum) {
  static char *error_messages[] = ERRORS;
  static int error_list_length =
      sizeof(error_messages) / sizeof(error_messages[0]);

  if (errnum < 0 || errnum > error_list_length) {
    return "Unknown error";
  }

  return (char *)error_messages[errnum];
}

s21_size_t s21_strlen(const char *str) {
  if (str == s21_NULL) {
    // Не более одного выхода из функции. Исключение составляет предварительная
    // проверка аргументов функции.
    return 0;
  }
  s21_size_t i = 0;
  for (; str[i] != '\0'; i++) {
  }
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  for (s21_size_t i = 0; result == s21_NULL && i < s21_strlen(str1); i++) {
    if (s21_strchr(str2, str1[i])) result = (char *)(str1 + i);
  }
  return result;
}
char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  for (s21_size_t i = 0;; i++) {
    if (str[i] == (unsigned char)c) {
      result = (char *)(str + i);
    }
    if (str[i] == '\0') {
      break;
    }
  }
  return result;
}
char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == s21_NULL || needle == s21_NULL || *haystack == '\0')
    return s21_NULL;

  if (*needle == '\0') return (char *)haystack;

  s21_size_t needle_len = s21_strlen(needle);
  s21_size_t haystack_len = s21_strlen(haystack);
  char *result = s21_NULL;

  for (s21_size_t i = 0; i <= haystack_len - needle_len; i++) {
    int match = 1;
    for (s21_size_t j = 0; j < needle_len && match; j++) {
      if (haystack[i + j] != needle[j]) {
        match = 0;
      }
    }
    if (match) {
      result = (char *)(haystack + i);
      break;
    }
  }
  return result;
}
char *s21_strtok(char *str, const char *delim) {
  static char *str_stat;
  char *token;

  if (!str) {
    if (!str_stat) {
      return NULL;
    } else {
      str = str_stat;
    }
  }

  str += s21_strspn(str, delim);

  if (!str) {
    str_stat = str;
    token = NULL;
  } else {
    token = str;
    str = s21_strpbrk(token, delim);
    if (!str) {
      str_stat = NULL;
    } else {
      *str = '\0';
      str_stat = str + 1;
    }
  }

  return token;
}
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int found = 0;

  for (s21_size_t i = 0; !found && i < s21_strlen(str1); i++) {
    if (s21_strchr(str2, str1[i]) == s21_NULL) {
      found = 1;
    } else {
      result++;
    }
  }
  return result;
}

//    int sscanf(const char *str, const char *format, ...){}
// dop 2
//    int sprintf(char *str, const char *format, ...){}
// dop 3

void *s21_to_upper(const char *str) {
  if (str == s21_NULL) return s21_NULL;
  size_t len = s21_strlen(str);
  char *upper_str = (char *)malloc(len + 1);
  if (!upper_str) return s21_NULL;
  for (size_t i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      upper_str[i] = str[i] - ('a' - 'A');
    } else {
      upper_str[i] = str[i];
    }
  }
  upper_str[len] = '\0';
  return (void *)upper_str;
}
void *s21_to_lower(const char *str) {
  if (str == s21_NULL) return s21_NULL;
  size_t len = s21_strlen(str);
  char *lower_str = (char *)malloc(len + 1);
  if (!lower_str) return s21_NULL;
  for (size_t i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      lower_str[i] = str[i] + ('a' - 'A');
    } else {
      lower_str[i] = str[i];
    }
  }
  lower_str[len] = '\0';
  return lower_str;
}

//    void *s21_insert(const char *src, const char *str, size_t start_index){}
//   void *s21_trim(const char *src, const char *trim_chars){}