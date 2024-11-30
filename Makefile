# Nome do arquivo a ser testado (passado como parâmetro)
TEST ?= 

SRC_DIR = src
TEST_DIR = test
SUITE_RUNNER_DIR = test/suite_runner

CC = gcc
CFLAGS = -Wall -Wextra -g


SOURCES = ${SRC_DIR}/${TEST}/${TEST}.c ${TEST_DIR}/${TEST}.c ${SUITE_RUNNER_DIR}/suite_runner.c 
HEADERS = ${SRC_DIR}/${TEST}/${TEST}.h ${TEST_DIR}/test_helpers.h ${SUITE_RUNNER_DIR}/suite_runner.h

EXEC = ${TEST}.test

all: ${EXEC}

${EXEC}: $(SOURCES) ${HEADERS}
	${CC} $(CFLAGS) -o ${EXEC} $(SOURCES)

clean:
	rm -f *.test

rebuild: clean all
