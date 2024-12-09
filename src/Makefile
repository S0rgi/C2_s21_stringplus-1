ifeq ($(origin CC), default)
CC = gcc
endif

TARGET ?= ../src

CFLAGS ?= -Wall -Werror -Wextra -std=c11

SRC_TEST = s21_string.c strtok_test.c

OBJ_TEST = $(SRC_TEST:.c=.o)

.PHONY: s21_strtok_test
s21_strtok_test: $(TARGET)/s21_strtok_test

$(TARGET)/%: $(OBJ_TEST)
	$(CC) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_TEST) $(TARGET)/s21_strtok_test
