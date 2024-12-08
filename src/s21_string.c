#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = (const unsigned char *)str;
  void *result = s21_NULL;

  for (s21_size_t i = 0; i < n; i++) {
    if (ptr[i] == (unsigned char)c) {
      result = (void *)(ptr + i);
    }
  }

  return result;
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
  s21_size_t dest_len = s21_strlen(dest);
  for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + n] = '\0';
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
  for (s21_size_t i = 0; src[i] && i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}
//    s21_size_t s21_strcspn(const char *str1, const char *str2){}
//    char *s21_strerror(int errnum){}

s21_size_t s21_strlen(const char *str) {
  if (str == s21_NULL) {
    return 0;
  }
  s21_size_t i = 0;
  for (; str[i] != '\0'; i++) {
  }
  return i;
}

//    char *s21_strpbrk(const char *str1, const char *str2){}
char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  for (s21_size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == (unsigned char)c) result = (char *)(str + i);
  }
  return result;
}
char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }
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
    }
  }
  return result;
}
//    char *s21_strtok(char *str, const char *delim){}
//    int sscanf(const char *str, const char *format, ...){}
// dop 2
//    int sprintf(char *str, const char *format, ...){}
// dop 3
void *s21_to_upper(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t len = s21_strlen(str);
  char *dup = (char *)malloc((len + 1) * sizeof(char));
  void *result = s21_NULL;
  if (dup != s21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        dup[i] = str[i] - 32;
      } else {
        dup[i] = str[i];
      }
    }
    dup[len] = '\0';
    result = (void *)dup;
  }
  return result;
}
void *s21_to_lower(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t len = s21_strlen(str);
  char *dup = (char *)malloc((len + 1) * sizeof(char));
  void *result = s21_NULL;
  if (dup != s21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        dup[i] = str[i] + 32;
      } else {
        dup[i] = str[i];
      }
    }
    dup[len] = '\0';
    result = (void *)dup;
  }
  return result;
}
//    void *s21_insert(const char *src, const char *str, size_t start_index){}
//   void *s21_trim(const char *src, const char *trim_chars){}