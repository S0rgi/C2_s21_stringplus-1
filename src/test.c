#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// Tests for s21_strpbrk
START_TEST(strpbrk_test) {
  // Test case 1: Character found in the middle
  const char *str1 = "hello";
  const char *str2 = "l";
  char *result_custom = s21_strpbrk(str1, str2);
  char *result_standard = strpbrk(str1, str2);
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
}
END_TEST

// Tests for s21_to_lower
START_TEST(s21_to_lower_test) {
  // Test case 1: Normal case
  const char *str = "Hello, World!";
  char *lower_str = s21_to_lower(str);
  ck_assert_str_eq(lower_str, "hello, world!");
  free(lower_str);

  // Test case 2: Numbers and special characters
  str = "123!@#";
  lower_str = s21_to_lower(str);
  ck_assert_str_eq(lower_str, "123!@#");
  free(lower_str);

  // Test case 3: Empty string
  str = "";
  lower_str = s21_to_lower(str);
  ck_assert_str_eq(lower_str, "");
  free(lower_str);

  // Test case 4: All uppercase
  str = "ABC";
  lower_str = s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
  free(lower_str);

  // Test case 5: All lowercase
  str = "abc";
  lower_str = s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
  free(lower_str);

  // Test case 6: Mixed case
  str = "aBc";
  lower_str = s21_to_lower(str);
  ck_assert_str_eq(lower_str, "abc");
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
  upper_str = s21_to_upper(str);
  ck_assert_str_eq(upper_str, "123!@#");
  free(upper_str);

  // Test case 3: Empty string
  str = "";
  upper_str = s21_to_upper(str);
  ck_assert_str_eq(upper_str, "");
  free(upper_str);

  // Test case 4: All lowercase
  str = "abc";
  upper_str = s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);

  // Test case 5: All uppercase
  str = "ABC";
  upper_str = s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);

  // Test case 6: Mixed case
  str = "aBc";
  upper_str = s21_to_upper(str);
  ck_assert_str_eq(upper_str, "ABC");
  free(upper_str);
}
END_TEST

// Tests for s21_strrchr
START_TEST(s21_strrchr_test) {
  // Test case 1: Normal case, character found
  char str1[] = "Hellol";
  char *result_custom = s21_strrchr(str1, 'o');
  char *result_standard = strrchr(str1, 'o');
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 2: Character not found
  result_custom = s21_strrchr(str1, 'x');
  result_standard = strrchr(str1, 'x');
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 3: Character found at the beginning
  result_custom = s21_strrchr(str1, 'H');
  result_standard = strrchr(str1, 'H');
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 4: Character found at the end
  result_custom = s21_strrchr(str1, 'l');
  result_standard = strrchr(str1, 'l');
  ck_assert_ptr_eq(result_custom, result_standard);

  // Test case 5: Empty string
  result_custom = s21_strrchr("", 'l');
  result_standard = strrchr("", 'l');
  ck_assert_ptr_eq(result_custom, result_standard);

  // // Test case 6: Null character
  // result_custom = s21_strrchr(str1, '\0');
  // result_standard = strrchr(str1, '\0');
  // ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strcat
START_TEST(strcat_test) {
  char dest1[20] = "Hello ";
  char dest2[20] = "Hello ";
  const char *str = "world";

  s21_strncat(dest1, str, 5);
  strncat(dest2, str, 5);

  ck_assert_str_eq(dest1, dest2);

  strcpy(dest1, "Foo");
  strcpy(dest2, "Foo");
  str = "";

  s21_strncat(dest1, str, 3);
  strncat(dest2, str, 3);

  ck_assert_str_eq(dest1, dest2);

  strcpy(dest1, "");
  strcpy(dest2, "");
  str = "Bar";

  s21_strncat(dest1, str, 3);
  strncat(dest2, str, 3);

  ck_assert_str_eq(dest1, dest2);
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
}
END_TEST

// Tests for memcpy
START_TEST(memcpy_test) {
  char src[] = "Hello, world!";
  char dest1[20];
  char dest2[20];

  s21_memcpy(dest1, src, sizeof(src));
  memcpy(dest2, src, sizeof(src));

  ck_assert_str_eq(dest1, dest2);

  const char *src_null = NULL;
  s21_memcpy(dest1, src_null, 0);
  memcpy(dest2, src_null, 0);

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
  char str1[] = "Hellol";
  char str2[] = "Helloh";
  int result_custom = s21_memcmp(str1, str2, 6);
  int result_standard = memcmp(str1, str2, 6);

  ck_assert_int_eq(result_custom, result_standard);

  result_custom = s21_memcmp(str1, str2, 0);
  result_standard = memcmp(str1, str2, 0);

  ck_assert_int_eq(result_custom, result_standard);

  result_custom = s21_memcmp(str1, str1, 6);
  result_standard = memcmp(str1, str1, 6);

  ck_assert_int_eq(result_custom, result_standard);
}
END_TEST

// Tests for memchr
START_TEST(memchr_test) {
  char str1[] = "Hellol";
  void *result_custom = s21_memchr(str1, 'o', 6);
  void *result_standard = memchr(str1, 'o', 6);

  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_memchr(str1, 'x', 6);
  result_standard = memchr(str1, 'x', 6);

  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_memchr(str1, 'H', 6);
  result_standard = memchr(str1, 'H', 6);

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strlen
START_TEST(strlen_test) {
  const char str1[] = "Hellol";
  int result_custom = s21_strlen(str1);
  int result_standard = strlen(str1);

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
}
END_TEST

// Tests for s21_strchr
START_TEST(s21_strchr_test) {
  const char str1[] = "Hellol";
  char *result_custom = s21_strchr(str1, 'o');
  char *result_standard = strchr(str1, 'o');

  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr(str1, 'x');
  result_standard = strchr(str1, 'x');

  ck_assert_ptr_eq(result_custom, result_standard);

  result_custom = s21_strchr(str1, 'H');
  result_standard = strchr(str1, 'H');

  ck_assert_ptr_eq(result_custom, result_standard);
}
END_TEST

// Tests for strstr
START_TEST(strstr_test) {
  const char *haystack = "Hello, world!";
  const char *needle = "world";

  char *result_custom = s21_strstr(haystack, needle);
  char *result_standard = strstr(haystack, needle);

  ck_assert_ptr_eq(result_custom, result_standard);

  needle = "xyz";
  result_custom = s21_strstr(haystack, needle);
  result_standard = strstr(haystack, needle);

  ck_assert_ptr_eq(result_custom, result_standard);

  needle = "";
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

  if (!(file = fopen(filename, "r"))) {
    ck_assert_int_eq(errno, ENOENT);
    const char *error_message = s21_strerror(errno);
    ck_assert_str_eq(error_message, "No such file or directory");
  }

  if (file) {
    fclose(file);
  }
}
END_TEST

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
  tcase_add_test(tcase_core, strcat_test);
  tcase_add_test(tcase_core, memset_test);
  tcase_add_test(tcase_core, memcpy_test);
  tcase_add_test(tcase_core, strncpy_test);
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

  suite_add_tcase(suite, tcase_core);

  runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
