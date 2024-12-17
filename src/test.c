#include <check.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
void s21_scanf_tests(TCase *tcase_core);
// Tests for s21_strpbrk
START_TEST(strpbrk_test) {
  // Test case 1: Character found in the middle
  const char *str1 = "hello";
  const char *str2 = "l";
  char *result_custom = s21_strpbrk(str1, str2);
  const char *result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 2: Character not found
  str1 = "hello";
  str2 = "x";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 3: Empty string as source
  str1 = "";
  str2 = "l";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 4: Empty string as set of characters
  str1 = "hello";
  str2 = "";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 5: Multiple characters in set
  str1 = "hello";
  str2 = "aeiou";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 6: Character found at the beginning
  str1 = "hello";
  str2 = "h";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 7: Character found at the end
  str1 = "hello";
  str2 = "o";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 8: Multiple occurrences of the same character
  str1 = "helloo";
  str2 = "o";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 9: Set contains all characters of the source
  str1 = "hello";
  str2 = "helo";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 10: Source is a single character
  str1 = "h";
  str2 = "h";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 11: Set is a single character
  str1 = "hello";
  str2 = "h";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 12: Source and set are the same
  str1 = "hello";
  str2 = "hello";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 13: Source is a long string
  str1 = "abcdefghijklmnopqrstuvwxyz";
  str2 = "z";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 14: Set is a long string
  str1 = "hello";
  str2 = "abcdefghijklmnopqrstuvwxyz";
  result_custom = s21_strpbrk(str1, str2);
  result_standard = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for s21_strcspn
START_TEST(s21_strcspn_test) {
  // Test case 1: Common scenario
  const char *str1 = "Hello, World!";
  const char *str2 = "aeiou";
  s21_size_t result1 = s21_strcspn(str1, str2);
  s21_size_t result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 2: No characters from str2 in str1
  str1 = "abcdefg";
  str2 = "xyz";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 3: Empty str1
  str1 = "";
  str2 = "a";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 4: Empty str2
  str1 = "Hello, World!";
  str2 = "";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 5: Both strings empty
  str1 = "";
  str2 = "";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 6: Characters from str2 at the beginning of str1
  str1 = "hello";
  str2 = "he";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 7: Characters from str2 at the end of str1
  str1 = "hello";
  str2 = "o";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 8: Multiple characters in str2
  str1 = "hello";
  str2 = "hel";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 9: str2 contains all characters of str1
  str1 = "hello";
  str2 = "helo";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 10: str1 is a single character
  str1 = "h";
  str2 = "h";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 11: str2 is a single character
  str1 = "hello";
  str2 = "h";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 12: str1 and str2 are the same
  str1 = "hello";
  str2 = "hello";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 13: str1 is a long string
  str1 = "abcdefghijklmnopqrstuvwxyz";
  str2 = "z";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);

  // Test case 14: str2 is a long string
  str1 = "hello";
  str2 = "abcdefghijklmnopqrstuvwxyz";
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Tests for s21_to_lower
START_TEST(s21_to_lower_test) {
  // Test case 1: Normal case
  const char *str = "Hello, World!";
  char *lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "hello, world!");
  free(lower_str);

  // Test case 2: Numbers and special characters
  str = "123!@#";
  lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "123!@#");
  free(lower_str);

  // Test case 3: Empty string
  str = "";
  lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "");
  free(lower_str);

  // Test case 4: All uppercase
  str = "ABC";
  lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
  free(lower_str);

  // Test case 5: All lowercase
  str = "abc";
  lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
  free(lower_str);

  // Test case 6: Mixed case
  str = "aBc";
  lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
  free(lower_str);

  // // Test case 7: Non-ASCII characters
  // такую хуйню сам обрабатывай
  // str = "ÄÖÜ";
  // lower_str = (char *)s21_to_lower(str);
  // ck_assert_str_eq(lower_str, "äöü");
  // free(lower_str);

  // Test case 8: Long string
  str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abcdefghijklmnopqrstuvwxyz");
  free(lower_str);

  // Test case 9: Single character
  str = "H";
  lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "h");
  free(lower_str);

  // Test case 10: String with multiple uppercase and lowercase
  str = "HeLlO wOrLd";
  lower_str = (char *)s21_to_lower(str);
  ck_assert_str_eq(lower_str, "hello world");
  free(lower_str);
}
END_TEST

// Tests for s21_to_upper
START_TEST(s21_to_upper_test) {
  // Test case 1: Normal case
  const char *str = "Hello, World!";
  char *upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "HELLO, WORLD!");
  free(upper_str);

  // Test case 2: Numbers and special characters
  str = "123!@#";
  upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "123!@#");
  free(upper_str);

  // Test case 3: Empty string
  str = "";
  upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "");
  free(upper_str);

  // Test case 4: All lowercase
  str = "abc";
  upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);

  // Test case 5: All uppercase
  str = "ABC";
  upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);

  // Test case 6: Mixed case
  str = "aBc";
  upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);

  // Test case 7: Non-ASCII character
  // сам такую хуйню обрабатывай
  // str = "äöü";
  // upper_str = (char *)s21_to_upper(str);
  // ck_assert_str_eq(upper_str, "ÄÖÜ");
  // free(upper_str);

  // Test case 8: Long string
  str = "abcdefghijklmnopqrstuvwxyz";
  upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(upper_str);

  // Test case 9: Single character
  str = "h";
  upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "H");
  free(upper_str);

  // Test case 10: String with multiple uppercase and lowercase
  str = "HeLlO wOrLd";
  upper_str = (char *)s21_to_upper(str);
  ck_assert_str_eq(upper_str, "HELLO WORLD");
  free(upper_str);
}
END_TEST

// Tests for s21_strrchr
START_TEST(s21_strrchr_test) {
  char str1[27] = "\0";  // Увеличим размер буфера до 27, чтобы хватило для
                         // "abcdefghijklmnopqrstuvwxyz"
  const char *result_custom = s21_strrchr(str1, 'o');
  const char *result_standard = strrchr(str1, 'o');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr(str1, 'x');
  result_standard = strrchr(str1, 'x');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr(str1, 'H');
  result_standard = strrchr(str1, 'H');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr(str1, 'z');
  result_standard = strrchr(str1, 'z');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr(str1, 'l');
  result_standard = strrchr(str1, 'l');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr("", 'l');
  result_standard = strrchr("", 'l');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr("H", 'H');
  result_standard = strrchr("H", 'H');
  ck_assert_ptr_eq(result_custom, result_standard);

  strcpy(str1, "abcdefghijklmnopqrstuvwxyz");
  result_custom = s21_strrchr(str1, 'z');
  result_standard = strrchr(str1, 'z');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr("Hello, World!", ',');
  result_standard = strrchr("Hello, World!", ',');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr("Hello\0World", '\0');
  result_standard = strrchr("Hello\0World", '\0');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr("Hello\0World", 'W');
  result_standard = strrchr("Hello\0World", 'W');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr("Hello\0World", 'H');
  result_standard = strrchr("Hello\0World", 'H');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr("Hello\0World", 'l');
  result_standard = strrchr("Hello\0World", 'l');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strrchr("Hello\0World", 'x');
  result_standard = strrchr("Hello\0World", 'x');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strcat
START_TEST(strncat_test) {
  char dest1[50];
  char dest2[50];
  const char *str;

  // Test case 1: Normal concatenation
  strcpy(dest1, "Hello ");
  strcpy(dest2, "Hello ");
  str = "world";

  s21_strncat(dest1, str, 5);
  strncat(dest2, str, 5);

  ck_assert_str_eq(dest1, dest2);

  // Test case 2: Empty source string
  strcpy(dest1, "Foo");
  strcpy(dest2, "Foo");
  str = "";

  s21_strncat(dest1, str, 3);
  strncat(dest2, str, 3);

  ck_assert_str_eq(dest1, dest2);

  // Test case 3: Empty destination string
  strcpy(dest1, "");
  strcpy(dest2, "");
  str = "Bar";

  s21_strncat(dest1, str, 3);
  strncat(dest2, str, 3);

  ck_assert_str_eq(dest1, dest2);

  // Test case 4: Source is longer than destination
  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  str = "WorldThisIsALongString";

  s21_strncat(dest1, str, 10);
  strncat(dest2, str, 10);

  ck_assert_str_eq(dest1, dest2);

  // Test case 5: Source is a single character
  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  str = "W";

  s21_strncat(dest1, str, 1);
  strncat(dest2, str, 1);

  ck_assert_str_eq(dest1, dest2);

  // Test case 6: Destination is a single character
  strcpy(dest1, "H");
  strcpy(dest2, "H");
  str = "ello";

  s21_strncat(dest1, str, 4);
  strncat(dest2, str, 4);

  ck_assert_str_eq(dest1, dest2);

  // Test case 7: Source and destination are the same
  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  str = "Hello";

  s21_strncat(dest1, str, 5);
  strncat(dest2, str, 5);

  ck_assert_str_eq(dest1, dest2);

  // Test case 8: Source is a long string
  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  str = "ThisIsAVeryLongStringThatWillBeTruncated";

  s21_strncat(dest1, str, 20);
  strncat(dest2, str, 20);

  ck_assert_str_eq(dest1, dest2);

  // Test case 9: Source is an empty string
  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  str = "";

  s21_strncat(dest1, str, 0);
  strncat(dest2, str, 0);

  ck_assert_str_eq(dest1, dest2);

  // Test case 10: Source is a null pointer
  strcpy(dest1, "Hello");
  strcpy(dest2, "Hello");
  str = NULL;

  // Expected behavior: no change to dest1
  s21_strncat(dest1, str, 5);
  // No corresponding strncat call because it does not handle NULL

  // Check that dest1 is still "Hello"
  ck_assert_str_eq(dest1, "Hello");
}
END_TEST

// Tests for memset
START_TEST(memset_test) {
  char buffer1[20];
  char buffer2[20];

  s21_memset(buffer1, 'A', sizeof(buffer1) - 1);
  memset(buffer2, 'A', sizeof(buffer2) - 1);

  buffer1[sizeof(buffer1) - 1] = '\0';
  buffer2[sizeof(buffer2) - 1] = '\0';

  ck_assert_str_eq(buffer1, buffer2);

  s21_memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));

  // Test case 3: Fill with a negative value
  s21_memset(buffer1, -1, sizeof(buffer1));
  memset(buffer2, -1, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));

  // Test case 5: Fill with a single character
  s21_memset(buffer1, 'A', 1);
  memset(buffer2, 'A', 1);

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));

  // Test case 6: Fill with a large value
  s21_memset(buffer1, 255, sizeof(buffer1));
  memset(buffer2, 255, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));

  // Test case 7: Fill with a small value
  s21_memset(buffer1, 1, sizeof(buffer1));
  memset(buffer2, 1, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));

  // Test case 8: Fill with a negative value that wraps around
  s21_memset(buffer1, -2, sizeof(buffer1));
  memset(buffer2, -2, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

// Tests for memcpy
START_TEST(memcpy_test) {
  char src[20] = "Hello, world!";
  char dest1[20];
  char dest2[20];

  s21_memcpy(dest1, src, sizeof(src));
  memcpy(dest2, src, sizeof(src));

  ck_assert_str_eq(dest1, dest2);

  // Test case 3: Copy a single character
  s21_memcpy(dest1, src, 1);
  memcpy(dest2, src, 1);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));

  // Test case 4: Copy a zero-length buffer
  s21_memcpy(dest1, src, 0);
  memcpy(dest2, src, 0);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));

  // Test case 5: Copy a large buffer
  s21_memcpy(dest1, src, 20);
  memcpy(dest2, src, 20);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));

  // Test case 6: Copy a buffer with a null terminator
  s21_memcpy(dest1, src, strlen(src) + 1);
  memcpy(dest2, src, strlen(src) + 1);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));

  // Test case 7: Copy a buffer with overlapping regions
  s21_memcpy(dest1 + 5, dest1, 5);
  memcpy(dest2 + 5, dest2, 5);

  ck_assert_mem_eq(dest1, dest2, sizeof(dest1));
}
END_TEST

// Tests for s21_strncpy
START_TEST(strncpy_test) {
  const char str[] = "Hellol";
  char dest[10] = {0};

  s21_strncpy(dest, str, 5);
  ck_assert_str_eq(dest, "Hello");

  s21_strncpy(dest, str, 0);
  ck_assert_str_eq(dest, "Hello");

  s21_strncpy(dest, str, 10);
  ck_assert_str_eq(dest, "Hellol");
  ck_assert_int_eq(dest[6], '\0');

  char dest2[10] = {0};
  s21_strncpy(dest2, str, 6);
  ck_assert_str_eq(dest2, "Hellol");

  char empty_dest[10] = {0};
  s21_strncpy(empty_dest, "", 5);
  ck_assert_str_eq(empty_dest, "");

  ck_assert_ptr_eq(s21_strncpy(dest, NULL, 5), s21_NULL);

  char dest3[10] = {0};
  s21_strncpy(dest3, "Hi", 5);
  ck_assert_str_eq(dest3, "Hi");
  ck_assert_int_eq(dest3[2], '\0');
  ck_assert_int_eq(dest3[3], '\0');
  ck_assert_int_eq(dest3[4], '\0');

  // Test case 8: Source is a single character
  s21_strncpy(dest, "H", 5);
  ck_assert_str_eq(dest, "H");

  // Test case 9: Source is an empty string
  s21_strncpy(dest, "", 5);
  ck_assert_str_eq(dest, "");
}
END_TEST
// Tests for s21_strcpy
START_TEST(strcpy_test) {
  const char *src = "Hello";
  char dest[10] = {0};

  // Test case 1: Normal copy
  s21_strcpy(dest, src);
  ck_assert_str_eq(dest, "Hello");

  // Test case 2: Copy empty string
  s21_strcpy(dest, "");
  ck_assert_str_eq(dest, "");

  // Test case 3: Source is shorter than destination buffer
  s21_strcpy(dest, "Hi");
  ck_assert_str_eq(dest, "Hi");

  // Test case 4: Source is a single character
  s21_strcpy(dest, "H");
  ck_assert_str_eq(dest, "H");

  // Test case 5: Source is an empty string (again to check overwriting)
  s21_strcpy(dest, "");
  ck_assert_str_eq(dest, "");

  // Test case 6: Source and destination are the same
  s21_strcpy(dest, dest);
  ck_assert_str_eq(dest, "");

  // Test case 7: Source is NULL
  ck_assert_ptr_eq(s21_strcpy(dest, NULL), s21_NULL);

  // Test case 8: Destination buffer is exactly the size of the source string
  char dest2[6] = {0};
  s21_strcpy(dest2, "Hello");
  ck_assert_str_eq(dest2, "Hello");

  // Test case 9: Copy a longer string into a larger buffer
  char long_dest[50] = {0};
  s21_strcpy(long_dest, "This is a long string test.");
  ck_assert_str_eq(long_dest, "This is a long string test.");

  // Test case 10: Source string has spaces
  s21_strcpy(dest, "Hi there");
  ck_assert_str_eq(dest, "Hi there");
}
END_TEST

// Tests for null_check
START_TEST(null_test) { ck_assert_ptr_eq(s21_NULL, NULL); }
END_TEST

// Tests for size_t_check
START_TEST(size_t_test) {
  ck_assert_int_eq(sizeof(size_t), sizeof(s21_size_t));
}
END_TEST

// Tests for memcmp
START_TEST(memcmp_test) {
  char str1[20] = "Hellol";
  char str2[20] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 6);
  int result_standard = memcmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);

  result_custom = s21_memcmp(str1, str2, 0);
  result_standard = memcmp(str1, str2, 0);

  ck_assert_int_eq(result_custom, result_standard);

  result_custom = s21_memcmp(str1, str1, 6);
  result_standard = memcmp(str1, str1, 6);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 4: Compare different lengths
  result_custom = s21_memcmp(str1, str2, 5);
  result_standard = memcmp(str1, str2, 5);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 5: Compare with a null terminator
  result_custom = s21_memcmp(str1, str2, 7);
  result_standard = memcmp(str1, str2, 7);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 6: Compare with a single character
  result_custom = s21_memcmp(str1, str2, 1);
  result_standard = memcmp(str1, str2, 1);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 7: Compare with a zero-length buffer
  result_custom = s21_memcmp(str1, str2, 0);
  result_standard = memcmp(str1, str2, 0);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 8: Compare with a large buffer
  result_custom = s21_memcmp(str1, str2, 20);
  result_standard = memcmp(str1, str2, 20);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

// Tests for memchr
START_TEST(memchr_test) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'o', 6);
  const void *result_standard = memchr(str1, 'o', 6);

  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_memchr(str1, 'x', 6);
  result_standard = memchr(str1, 'x', 6);

  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_memchr(str1, 'H', 6);
  result_standard = memchr(str1, 'H', 6);

  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 4: Character not found
  result_custom = s21_memchr(str1, 'z', 6);
  result_standard = memchr(str1, 'z', 6);

  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 5: Character found at the end
  result_custom = s21_memchr(str1, 'l', 6);
  result_standard = memchr(str1, 'l', 6);

  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 6: Character found at the beginning
  result_custom = s21_memchr(str1, 'H', 6);
  result_standard = memchr(str1, 'H', 6);

  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 7: Zero-length buffer
  result_custom = s21_memchr(str1, 'o', 0);
  result_standard = memchr(str1, 'o', 0);

  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 8: Single character buffer
  result_custom = s21_memchr("H", 'H', 1);
  result_standard = memchr("H", 'H', 1);

  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 9: Large buffer
  result_custom = s21_memchr("abcdefghijklmnopqrstuvwxyz", 'z', 26);
  result_standard = memchr("abcdefghijklmnopqrstuvwxyz", 'z', 26);

  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 10: Null character
  result_custom = s21_memchr("Hello\0World", '\0', 11);
  result_standard = memchr("Hello\0World", '\0', 11);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strlen
START_TEST(strlen_test) {
  const char str1[] = "Hellol";
  s21_size_t result_custom = s21_strlen(str1);
  s21_size_t result_standard = strlen(str1);

  ck_assert_int_eq(result_custom, result_standard);

  result_custom = s21_strlen("");
  result_standard = strlen("");

  ck_assert_int_eq(result_custom, result_standard);

  const char *null_str = NULL;
  s21_size_t length = s21_strlen(null_str);

  ck_assert_int_eq(length, 0);
  result_custom = s21_strlen("1234567890");
  result_standard = strlen("1234567890");

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 4: Single character string
  result_custom = s21_strlen("H");
  result_standard = strlen("H");

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 5: Long string
  result_custom = s21_strlen("abcdefghijklmnopqrstuvwxyz");
  result_standard = strlen("abcdefghijklmnopqrstuvwxyz");

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 6: String with spaces
  result_custom = s21_strlen("Hello World");
  result_standard = strlen("Hello World");

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 7: String with special characters
  result_custom = s21_strlen("Hello, World!");
  result_standard = strlen("Hello, World!");

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 8: String with non-ASCII characters
  result_custom = s21_strlen("ÄÖÜ");
  result_standard = strlen("ÄÖÜ");

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

// Tests for strcmp
START_TEST(strcmp_test) {
  const char str1[] = "Hellol";
  const char str2[] = "Helloh";
  int result_custom = s21_strncmp(str1, str2, 6);
  int result_standard = strncmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);

  result_custom = s21_strncmp(str1, str1, 6);
  result_standard = strncmp(str1, str1, 6);

  ck_assert_int_eq(result_custom, result_standard);

  result_custom = s21_strncmp("", "", 1);
  result_standard = strncmp("", "", 1);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 4: Different lengths
  result_custom = s21_strncmp(str1, str2, 5);
  result_standard = strncmp(str1, str2, 5);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 5: Single character strings
  result_custom = s21_strncmp("H", "H", 1);
  result_standard = strncmp("H", "H", 1);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 6: Long strings
  result_custom = s21_strncmp("abcdefghijklmnopqrstuvwxyz",
                              "abcdefghijklmnopqrstuvwxyz", 26);
  result_standard =
      strncmp("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz", 26);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 7: Strings with spaces
  result_custom = s21_strncmp("Hello World", "Hello World", 11);
  result_standard = strncmp("Hello World", "Hello World", 11);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 8: Strings with special characters
  result_custom = s21_strncmp("Hello, World!", "Hello, World!", 13);
  result_standard = strncmp("Hello, World!", "Hello, World!", 13);

  ck_assert_int_eq(result_custom, result_standard);

  // Test case 9: Strings with non-ASCII characters
  result_custom = s21_strncmp("ÄÖÜ", "ÄÖÜ", 3);
  result_standard = strncmp("ÄÖÜ", "ÄÖÜ", 3);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

// Tests for s21_strchr
START_TEST(s21_strchr_test) {
  const char str1[] = "Hellol";
  const char *result_custom = s21_strchr(str1, 'o');
  const char *result_standard = strchr(str1, 'o');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr(str1, 'x');
  result_standard = strchr(str1, 'x');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr(str1, 'H');
  result_standard = strchr(str1, 'H');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr(str1, 'z');
  result_standard = strchr(str1, 'z');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr(str1, 'l');
  result_standard = strchr(str1, 'l');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("", 'l');
  result_standard = strchr("", 'l');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("H", 'H');
  result_standard = strchr("H", 'H');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("abcdefghijklmnopqrstuvwxyz", 'z');
  result_standard = strchr("abcdefghijklmnopqrstuvwxyz", 'z');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("Hello, World!", ',');
  result_standard = strchr("Hello, World!", ',');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("Hello\0World", '\0');
  result_standard = strchr("Hello\0World", '\0');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("Hello\0World", 'W');
  result_standard = strchr("Hello\0World", 'W');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("Hello\0World", 'H');
  result_standard = strchr("Hello\0World", 'H');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("Hello\0World", 'l');
  result_standard = strchr("Hello\0World", 'l');
  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr("Hello\0World", 'x');
  result_standard = strchr("Hello\0World", 'x');
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strstr
START_TEST(strstr_test) {
  const char *haystack = "Hello, world!";
  const char *needle = "world";

  const char *result_custom = s21_strstr(haystack, needle);
  const char *result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  needle = "xyz";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  needle = "";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  needle = "w";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  needle = "Hello";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  needle = "world!";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "H";
  needle = "H";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "";
  needle = "H";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello, world!";
  needle = "";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello, world!";
  needle = "Hello, world!";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "abcdefghijklmnopqrstuvwxyz";
  needle = "def";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello, world!";
  needle = ", wo";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "ÄÖÜ";
  needle = "ÖÜ";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello\0World";
  needle = "World";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello\0World";
  needle = "Hello";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello\0World";
  needle = "Hello\0World";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello\0World";
  needle = "Hello\0";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello\0World";
  needle = "World\0";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);

  haystack = "Hello\0World";
  needle = "\0";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);
  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for s21_strtok
START_TEST(strtok_test) {
  const char str_1[] = "Hello World";
  const char str_1_[] = "Goodbye Cruel World";

  char *str = malloc(20);
  char *str_ = malloc(30);

  memset(str, 0, 20);
  memset(str_, 0, 30);

  strcpy(str, str_1);
  strcpy(str_, str_1_);

  char *token;

  token = s21_strtok(NULL, " ");
  ck_assert_ptr_eq(token, NULL);

  token = s21_strtok(str, " ");
  ck_assert_str_eq(token, "Hello");

  token = s21_strtok(NULL, " ");
  ck_assert_str_eq(token, "World");

  token = s21_strtok(NULL, " ");
  ck_assert_ptr_eq(token, NULL);

  token = s21_strtok(str_, " ");
  ck_assert_str_eq(token, "Goodbye");

  token = s21_strtok(NULL, " ");
  ck_assert_str_eq(token, "Cruel");

  token = s21_strtok(NULL, " ");
  ck_assert_str_eq(token, "World");

  token = s21_strtok(NULL, " ");
  ck_assert_ptr_eq(token, NULL);
  free(str);
  free(str_);
}

END_TEST

// Test for s21_strerror with a non-existent file
START_TEST(test_s21_strerror_nonexistent_file) {
  FILE *file;
  char filename[512] = {0};
  strcpy(filename, "nofile.txt");

  const char *error_message = s21_strerror(-1);
  ck_assert_str_eq(error_message, "Unknown error");

  if (!(file = fopen(filename, "r"))) {
    ck_assert_int_eq(errno, ENOENT);
    error_message = s21_strerror(errno);
    ck_assert_str_eq(error_message, "No such file or directory");
  }

  if (file) {
    fclose(file);
  }
}

END_TEST
// Tests for s21_insert
START_TEST(insert_test) {
  char *result;

  // Test case 1: Normal insertion
  result = s21_insert("Hello World", "Beautiful ", 6);
  ck_assert_str_eq(result, "Hello Beautiful World");
  free(result);

  // Test case 2: Insert at the beginning
  result = s21_insert("World", "Hello ", 0);
  ck_assert_str_eq(result, "Hello World");
  free(result);

  // Test case 3: Insert at the end
  result = s21_insert("Hello", " World", 5);
  ck_assert_str_eq(result, "Hello World");
  free(result);

  // Test case 4: Insert into an empty string
  result = s21_insert("", "Hello", 0);
  ck_assert_str_eq(result, "Hello");
  free(result);

  // Test case 5: Insert an empty string
  result = s21_insert("Hello", "", 2);
  ck_assert_str_eq(result, "Hello");
  free(result);

  // Test case 6: Insert with NULL source
  result = s21_insert(NULL, "Hello", 0);
  ck_assert_ptr_eq(result, NULL);

  // Test case 7: Insert with NULL string to insert
  result = s21_insert("Hello", NULL, 0);
  ck_assert_ptr_eq(result, NULL);

  // Test case 8: Insert with out-of-bounds start_index
  result = s21_insert("Hello", " World", 10);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST
// Tests for s21_trim
START_TEST(trim_test) {
  char *result;

  // Test case 1: Trimming spaces from both ends
  result = s21_trim("  Hello World  ", " ");
  ck_assert_str_eq(result, "Hello World");
  free(result);

  // Test case 2: Trimming specific characters from both ends
  result = s21_trim("!!!Hello World!!!", "!");
  ck_assert_str_eq(result, "Hello World");
  free(result);

  // Test case 3: No trimming characters specified (default to spaces)
  result = s21_trim("   Hello World   ", NULL);
  ck_assert_str_eq(result, "Hello World");
  free(result);

  // Test case 4: Source string is empty
  result = s21_trim("", " ");
  ck_assert_str_eq(result, "");
  free(result);

  // Test case 5: Source string has no trimming characters
  result = s21_trim("Hello World", "!");
  ck_assert_str_eq(result, "Hello World");
  free(result);

  // Test case 6: Source string is all trimming characters
  result = s21_trim("!!!", "!");
  ck_assert_str_eq(result, "");
  free(result);

  // Test case 7: Trimming multiple characters
  result = s21_trim("abcHello Worldabc", "abc");
  ck_assert_str_eq(result, "Hello World");
  free(result);

  // Test case 8: Trimming characters with NULL source
  result = s21_trim(NULL, " ");
  ck_assert_ptr_eq(result, NULL);

  // Test case 9: Trimming NULL characters with valid source
  result = s21_trim("   Hello World   ", NULL);
  ck_assert_str_eq(result, "Hello World");
  free(result);
}
END_TEST
// Tests for s21_sprintf
START_TEST(sprintf_test) {
  char buffer[10512];
  char expected[10512];

  // Test case 0: % format
  s21_sprintf(buffer, "%%");
  sprintf(expected, "%%");
  ck_assert_str_eq(buffer, expected);

  // Test case 1: Basic integer formatting
  s21_sprintf(buffer, "%d", 123);
  sprintf(expected, "%d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 2: Basic float formatting
  s21_sprintf(buffer, "%f", 123.456);
  sprintf(expected, "%f", 123.456);
  ck_assert_str_eq(buffer, expected);

  // Test case 2.1: Float minus
  s21_sprintf(buffer, "%f", -123.456);
  sprintf(expected, "%f", -123.456);
  ck_assert_str_eq(buffer, expected);

  // Test case 2.2: Float space
  s21_sprintf(buffer, "% f", 123.456);
  sprintf(expected, "% f", 123.456);
  ck_assert_str_eq(buffer, expected);

  // Test case 2.3: Float null prec
  s21_sprintf(buffer, "%.0f", 123.456);
  sprintf(expected, "%.0f", 123.456);
  ck_assert_str_eq(buffer, expected);

  // Test case 2.4: Float null prec > 0,5
  s21_sprintf(buffer, "%.0f", 123.6);
  sprintf(expected, "%.0f", 123.6);
  ck_assert_str_eq(buffer, expected);

  // Test case 2.3: Float > 0.5
  s21_sprintf(buffer, "% f", 123.6);
  sprintf(expected, "% f", 123.6);
  ck_assert_str_eq(buffer, expected);

  // Test case 3: Basic string formatting
  s21_sprintf(buffer, "%s", "Hello, World!");
  sprintf(expected, "%s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);

  // Test case 4: Basic character formatting
  s21_sprintf(buffer, "%c", 'A');
  sprintf(expected, "%c", 'A');
  ck_assert_str_eq(buffer, expected);

  // Test case 4.1: Basic character formatting
  s21_sprintf(buffer, "%-c", 'A');
  sprintf(expected, "%-c", 'A');
  ck_assert_str_eq(buffer, expected);

  // Test case 5: Basic unsigned integer formatting
  s21_sprintf(buffer, "%u", 12345);
  sprintf(expected, "%u", 12345);
  ck_assert_str_eq(buffer, expected);

  // Test case 6: Width specification
  s21_sprintf(buffer, "%5d", 123);
  sprintf(expected, "%5d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 7: Precision specification for integers
  s21_sprintf(buffer, "%.5d", 123);
  sprintf(expected, "%.5d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 8: Precision specification for floats
  s21_sprintf(buffer, "%.2f", 123.456);
  sprintf(expected, "%.2f", 123.456);
  ck_assert_str_eq(buffer, expected);

  // Test case 9: Precision specification for strings
  s21_sprintf(buffer, "%.5s", "Hello, World!");
  sprintf(expected, "%.5s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);

  // Test case 9.1: Wide minus
  s21_sprintf(buffer, "%-ls", L"Hello, World!");
  sprintf(expected, "%-ls", L"Hello, World!");
  ck_assert_str_eq(buffer, expected);

  // Test case 9.2: Minus
  s21_sprintf(buffer, "%-s", "Hello, World!");
  sprintf(expected, "%-s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);

  // Test case 9.3: Minus + width
  s21_sprintf(buffer, "%-20s", "Hello, World!");
  sprintf(expected, "%-20s", "Hello, World!");
  ck_assert_str_eq(buffer, expected);

  // Test case 10: Left justification
  s21_sprintf(buffer, "%-5d", 123);
  sprintf(expected, "%-5d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 11: Sign specification
  buffer[0] = '\0';
  s21_sprintf(buffer, "%+d", -123);
  sprintf(expected, "%+d", -123);
  ck_assert_str_eq(buffer, expected);

  // Test case 12: Space specification
  s21_sprintf(buffer, "% d", 123);
  sprintf(expected, "% d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 14: Combination of width and precision
  s21_sprintf(buffer, "%5.2f", 123.456);
  sprintf(expected, "%5.2f", 123.456);
  ck_assert_str_eq(buffer, expected);

  // Test case 15: Combination of width, precision, and left justification
  s21_sprintf(buffer, "%-5.2f", 123.456);
  sprintf(expected, "%-5.2f", 123.456);
  ck_assert_str_eq(buffer, expected);

  // Test case 16: Combination of width, precision, and zero padding
  s21_sprintf(buffer, "%05.2f", 123.456);
  sprintf(expected, "%05.2f", 123.456);
  ck_assert_str_eq(buffer, expected);

  // Test case 17: Long integer
  s21_sprintf(buffer, "%ld", 1234567890L);
  sprintf(expected, "%ld", 1234567890L);
  ck_assert_str_eq(buffer, expected);

  // Test case 18: Long long integer
  s21_sprintf(buffer, "%lld", 1234567890123456789LL);
  sprintf(expected, "%lld", 1234567890123456789LL);
  ck_assert_str_eq(buffer, expected);

  // Test case 19: Short integer
  s21_sprintf(buffer, "%hd", (short)123);
  sprintf(expected, "%hd", (short)123);
  ck_assert_str_eq(buffer, expected);

  // Test case 20: Short short integer
  s21_sprintf(buffer, "%hhd", (signed char)123);
  sprintf(expected, "%hhd", (signed char)123);
  ck_assert_str_eq(buffer, expected);

  // Test case 21: Unsigned long integer
  s21_sprintf(buffer, "%lu", 1234567890UL);
  sprintf(expected, "%lu", 1234567890UL);
  ck_assert_str_eq(buffer, expected);

  // Test case 22: Unsigned long long integer
  s21_sprintf(buffer, "%llu", 1234567890123456789ULL);
  sprintf(expected, "%llu", 1234567890123456789ULL);
  ck_assert_str_eq(buffer, expected);

  // Test case 23: Unsigned short integer
  s21_sprintf(buffer, "%hu", (unsigned short)123);
  sprintf(expected, "%hu", (unsigned short)123);
  ck_assert_str_eq(buffer, expected);

  // Test case 24: Unsigned short short integer
  s21_sprintf(buffer, "%hhu", (unsigned char)123);
  sprintf(expected, "%hhu", (unsigned char)123);
  ck_assert_str_eq(buffer, expected);

  // Test case 26: Float with very small value
  s21_sprintf(buffer, "%f", 1e-10);
  sprintf(expected, "%f", 1e-10);
  ck_assert_str_eq(buffer, expected);

  // Test case 27: Float with very large value
  s21_sprintf(buffer, "%f", 1e10);
  sprintf(expected, "%f", 1e10);
  ck_assert_str_eq(buffer, expected);

  // Test case 28: Float with NaN
  s21_sprintf(buffer, "%f", 0.0 / 0.0);
  sprintf(expected, "%f", 0.0 / 0.0);
  ck_assert_str_eq(buffer, expected);

  // Test case 29: Float with infinity
  s21_sprintf(buffer, "%f", 1.0 / 0.0);
  sprintf(expected, "%f", 1.0 / 0.0);
  ck_assert_str_eq(buffer, expected);

  // Test case 30: Float with negative infinity
  s21_sprintf(buffer, "%f", -1.0 / 0.0);
  sprintf(expected, "%f", -1.0 / 0.0);
  ck_assert_str_eq(buffer, expected);

  // Test case 31: String with wide characters
  wchar_t wstr[] = L"Hello, World!";
  s21_sprintf(buffer, "%ls", wstr);
  sprintf(expected, "%ls", wstr);
  ck_assert_str_eq(buffer, expected);

  // Test case 32: Character with wide character
  wchar_t wc = L'A';
  s21_sprintf(buffer, "%lc", wc);
  sprintf(expected, "%lc", wc);
  ck_assert_str_eq(buffer, expected);

  // Test case 32.1: Character with wide character
  wchar_t wc1 = L'A';
  s21_sprintf(buffer, "%10lc", wc1);
  sprintf(expected, "%10lc", wc1);
  ck_assert_str_eq(buffer, expected);

  // Test case 32.2: Character with wide character and minus
  wchar_t wc2 = L'A';
  s21_sprintf(buffer, "%-10lc", wc2);
  sprintf(expected, "%-10lc", wc2);
  ck_assert_str_eq(buffer, expected);

  // Test case 32.3: Character with wide character and minus
  wchar_t wc3 = L'A';
  s21_sprintf(buffer, "%-lc", wc3);
  sprintf(expected, "%-lc", wc3);
  ck_assert_str_eq(buffer, expected);

  // Test case 33: Multiple format specifiers
  s21_sprintf(buffer, "%d %f %s", 123, 123.456, "Hello, World!");
  sprintf(expected, "%d %f %s", 123, 123.456, "Hello, World!");
  ck_assert_str_eq(buffer, expected);

  // Test case 35: Format string with no arguments
  s21_sprintf(buffer, "Hello, World!");
  sprintf(expected, "Hello, World!");
  ck_assert_str_eq(buffer, expected);

  // Test case 37: Format string with invalid width
  s21_sprintf(buffer, "%-d", 123);
  sprintf(expected, "%-d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 38: Format string with invalid precision
  s21_sprintf(buffer, "%.d", 123);
  sprintf(expected, "%.d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 40: Format string with invalid combination of flags
  s21_sprintf(buffer, "%+-d", 123);
  sprintf(expected, "%+-d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 41: Format string with invalid combination of width and precision
  s21_sprintf(buffer, "%5.0d", 123);
  sprintf(expected, "%5.0d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 42: Format string with invalid combination of width, precision,
  // and flags
  s21_sprintf(buffer, "%-5.0d", 123);
  sprintf(expected, "%-5.0d", 123);
  ck_assert_str_eq(buffer, expected);

  // Test case 43: Resize
  char *str =
      "To represent the character you can use Universal Character Names "
      "(UCNs). The character 'ф' has the Unicode value U+0444 and so in C++ "
      "you could write it . Also if the source code encoding supports this "
      "character then you can just write it literally in your source code.";
  s21_sprintf(buffer, "%s", str);
  sprintf(expected, "%s", str);

  // Test case 44: Resize wchar
  wchar_t *str1 =
      L"1To represent the character you can use Universal Character Names To "
      L"2represent the character you can use Universal Character Names  To "
      L"3represent the character you can use Universal Character Names To "
      L"4represent the character you can use Universal Character Names To "
      L"5represent the character you can use Universal Character Names To "
      L"6represent the character you can use Universal Character Names To "
      L"7represent the character you can use Universal Character Names To ";

  s21_sprintf(buffer, "%ls", str1);
  sprintf(expected, "%ls", str1);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тесты s21_sscanf
START_TEST(test_sscanf_char) {
  char str[] = "A";
  char customCharValue, originalCharValue;
  int count_custom = s21_sscanf(str, "%c", &customCharValue);
  int count_original = sscanf(str, "%c", &originalCharValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customCharValue, originalCharValue);
}
END_TEST

START_TEST(test_sscanf_signed_integer) {
  char str[] = "123";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%d", &customIntValue);
  int count_original = sscanf(str, "%d", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);
}
END_TEST

START_TEST(test_sscanf_integer_in_any_format) {
  char str[] = "0173";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%i", &customIntValue);
  int count_original = sscanf(str, "%i", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);  // 0173 -> 0153 in octal
}
END_TEST

START_TEST(test_sscanf_scientific_notation_lowercase_e) {
  char str[] = "3.14e5";
  float customFloatValue, originalFloatValue;
  int count_custom = s21_sscanf(str, "%e", &customFloatValue);
  int count_original = sscanf(str, "%e", &originalFloatValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_float_eq(customFloatValue, originalFloatValue);
}
END_TEST

START_TEST(test_sscanf_scientific_notation_uppercase_E) {
  char str[] = "1.23E+3";
  float customFloatValue, originalFloatValue;
  int count_custom = s21_sscanf(str, "%E", &customFloatValue);
  int count_original = sscanf(str, "%E", &originalFloatValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_float_eq(customFloatValue, originalFloatValue);
}
END_TEST

START_TEST(test_sscanf_float) {
  char str[] = "45.67";
  float customFloatValue, originalFloatValue;
  int count_custom = s21_sscanf(str, "%f", &customFloatValue);
  int count_original = sscanf(str, "%f", &originalFloatValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_float_eq(customFloatValue, originalFloatValue);
}
END_TEST

START_TEST(test_sscanf_unsigned_octal) {
  char str[] = "075";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%o", &customIntValue);
  int count_original = sscanf(str, "%o", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);  // 075 -> 75 in decimal
}
END_TEST

START_TEST(test_sscanf_string) {
  char str[] = "HelloWorld";
  char customStringValue[50], originalStringValue[50];
  int count_custom = s21_sscanf(str, "%s", customStringValue);
  int count_original = sscanf(str, "%s", originalStringValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_str_eq(customStringValue, originalStringValue);
}
END_TEST

START_TEST(test_sscanf_unsigned_integer) {
  char str[] = "12345";
  unsigned int customUintValue, originalUintValue;
  int count_custom = s21_sscanf(str, "%u", &customUintValue);
  int count_original = sscanf(str, "%u", &originalUintValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customUintValue, originalUintValue);
}
END_TEST

START_TEST(test_sscanf_unsigned_hex) {
  char str[] = "FF";
  int customIntValue, originalIntValue;
  int count_custom = s21_sscanf(str, "%x", &customIntValue);
  int count_original = sscanf(str, "%x", &originalIntValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customIntValue, originalIntValue);  // FF -> 255 in decimal
}
END_TEST

START_TEST(test_sscanf_pointer) {
  char str[] = "0x7ffeeeb13b70";
  void *customPointerValue, *originalPointerValue;
  int count_custom = s21_sscanf(str, "%p", &customPointerValue);
  int count_original = sscanf(str, "%p", &originalPointerValue);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_ptr_eq(customPointerValue,
                   originalPointerValue);  // Pointer address should match
}
END_TEST

START_TEST(test_sscanf_n_format) {
  char str[] = "Hello";
  int customN, originalN;

  int count_custom = s21_sscanf(str, "%n", &customN);
  int count_original = sscanf(str, "%n", &originalN);

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(customN, 5);  // The number of characters parsed should be 5
}
END_TEST

START_TEST(test_sscanf_percent) {
  char str[] = "%";
  int count_custom = s21_sscanf(str, "%%");
  int count_original = sscanf(str, "%%");

  ck_assert_int_eq(count_custom, count_original);
  ck_assert_int_eq(count_custom, 1);  // Should match 1 since '%' is valid
}
END_TEST
void s21_ss+canf_tests(TCase *tcase_core) {
  tcase_add_test(tcase_core, test_sscanf_char);
  tcase_add_test(tcase_core, test_sscanf_signed_integer);
  tcase_add_test(tcase_core, test_sscanf_integer_in_any_format);
  tcase_add_test(tcase_core, test_sscanf_scientific_notation_lowercase_e);
  tcase_add_test(tcase_core, test_sscanf_scientific_notation_uppercase_E);
  tcase_add_test(tcase_core, test_sscanf_float);
  tcase_add_test(tcase_core, test_sscanf_unsigned_octal);
  tcase_add_test(tcase_core, test_sscanf_string);
  tcase_add_test(tcase_core, test_sscanf_unsigned_integer);
  tcase_add_test(tcase_core, test_sscanf_unsigned_hex);
  tcase_add_test(tcase_core, test_sscanf_pointer);
  tcase_add_test(tcase_core, test_sscanf_n_format);
  tcase_add_test(tcase_core, test_sscanf_percent);
}
// Add the new test to the main function
int main(void) {
  Suite *suite;
  SRunner *runner;

  suite = suite_create("String Tests");

  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, strpbrk_test);
  tcase_add_test(tcase_core, s21_strcspn_test);
  tcase_add_test(tcase_core, s21_to_lower_test);
  tcase_add_test(tcase_core, s21_to_upper_test);
  tcase_add_test(tcase_core, s21_strrchr_test);
  tcase_add_test(tcase_core, strncat_test);
  tcase_add_test(tcase_core, memset_test);
  tcase_add_test(tcase_core, memcpy_test);
  tcase_add_test(tcase_core, strncpy_test);
  tcase_add_test(tcase_core, strcpy_test);
  tcase_add_test(tcase_core, null_test);
  tcase_add_test(tcase_core, size_t_test);
  tcase_add_test(tcase_core, memcmp_test);
  tcase_add_test(tcase_core, memchr_test);
  tcase_add_test(tcase_core, strlen_test);
  tcase_add_test(tcase_core, strcmp_test);
  tcase_add_test(tcase_core, s21_strchr_test);
  tcase_add_test(tcase_core, strstr_test);
  tcase_add_test(tcase_core, strtok_test);
  tcase_add_test(tcase_core, test_s21_strerror_nonexistent_file);
  tcase_add_test(tcase_core, sprintf_test);
  tcase_add_test(tcase_core, insert_test);
  tcase_add_test(tcase_core, trim_test);

  s21_scanf_tests(tcase_core);
  suite_add_tcase(suite, tcase_core);

  runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}