SHELL = /bin/sh
CC=gcc
INCLUDE=include
SRC=src
TEST=tests
FLAGS=-I$(INCLUDE) -I$(TEST) -Wall -lcheck -g
COMMON_TEST=$(TEST)/test_runner.c

ROUTINE_TEST_SRC=$(SRC)/routine.c
ROUTINE_TEST_INCLUDE=$(INCLUDE)/routine.h $(TEST)/routine_test.h
ROUTINE_TEST=$(ROUTINE_TEST_SRC) $(ROUTINE_TEST_INCLUDE)

CHECK_DEPS=$(ROUTINE_TEST) $(COMMON_TEST)
check: $(CHECK_DEPS)
	$(CC) $(FLAGS) $(COMMON_TEST) $(ROUTINE_TEST_SRC) -o check
