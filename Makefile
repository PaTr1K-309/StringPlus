SHELL = /bin/sh

CC = gcc

STDCFLAGS = -Wall -Wextra -Werror -std=c11
GCOVFLAG = --coverage
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHKFLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHKFLAGS = -lcheck
endif

OBJ_DIR = obj
TEST_DIR = tests
OBJ_DIR_TESTS = $(TEST_DIR)/$(OBJ_DIR)

AR = ar rcs
RAN = ranlib

SRC_FILES = $(wildcard *.c)
SRC_FILES_TESTS = $(wildcard $(TEST_DIR)/*.c)
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
OBJ_FILES_GCOV = $(patsubst %.c, $(OBJ_DIR)/%_gcov.o, $(SRC_FILES))
OBJ_FILES_TESTS = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR_TESTS)/%.o, $(SRC_FILES_TESTS))
OBJ_FILES_TESTS_GCOV = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR_TESTS)/%_gcov.o, $(SRC_FILES_TESTS))

MD = mkdir -p
RM = rm -rf

all: s21_string.a test gcov_report

s21_string.a: $(OBJ_FILES)
	$(AR) $@ $^
	$(RAN) $@

$(OBJ_DIR)/%.o: %.c
	$(MD) $(OBJ_DIR)
	$(CC) $(STDCFLAGS) -c $< -o $@

test: $(OBJ_FILES_TESTS) $(OBJ_FILES)
	$(CC) $(STDCFLAGS) $^ -o test $(CHKFLAGS)

$(OBJ_DIR_TESTS)%.o: $(TEST_DIR)/%.c
	$(MD) $(OBJ_DIR_TESTS)
	$(CC) $(STDCFLAGS) -c $< -o $@

gcov_report: $(OBJ_FILES_GCOV) $(OBJ_FILES_TESTS_GCOV)
	$(CC) $(STDCFLAGS) $(GCOVFLAG) $^ -o test $(CHKFLAGS)
	./test
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report test.info
	$(RM) $(OBJ_DIR)/*.gcno $(OBJ_DIR)/*.gcda
	$(RM) $(TEST_DIR)/$(OBJ_DIR)/*.gcno $(TEST_DIR)/$(OBJ_DIR)/*.gcda

$(OBJ_DIR)/%_gcov.o: %.c
	$(MD) $(OBJ_DIR)
	$(CC) $(STDCFLAGS) $(GCOVFLAG) -c $< -o $@

$(OBJ_DIR_TESTS)/%_gcov.o: $(TEST_DIR)/%.c
	$(MD) $(OBJ_DIR_TESTS)
	$(CC) $(STDCFLAGS) $(GCOVFLAG) -c $< -o $@

gcov_report_open:
	open report/index.html

clean:
	$(RM) $(OBJ_DIR) $(OBJ_DIR_TESTS) s21_string.a test test.info report

.PHONY: all clean gcov_report_open