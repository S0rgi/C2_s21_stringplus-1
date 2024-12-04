CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -D_POSIX_C_SOURCE=200809L  -lm  -pedantic
LIB_NAME = s21_string

all: clean clang $(LIB_NAME).a test
clean:
	rm -rf *.o *.a *.out
test: $(LIB_NAME).a
	$(CC) $(CFLAGS) test.c -L. $(LIB_NAME).a -o test.out
$(LIB_NAME).a: $(LIB_NAME).o
	 ar rcs $(LIB_NAME).a $(LIB_NAME).o
$(LIB_NAME).o: $(LIB_NAME).c
	$(CC) $(CFLAGS) -c $(LIB_NAME).c -o $(LIB_NAME).o
cpp:
	cppcheck --enable=all --suppress=checkersReport --suppress=missingIncludeSystem *.c
clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	rm -rf .clang-format
val:test
	valgrind --tool=memcheck --leak-check=yes  ./test.out
lint:
	s21lint *.c *.h
gcov_report: