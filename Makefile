
SRC_DIR = src/static-list
TEST_DIR = test

CC = gcc
CFLAGS = -Wall -Wextra -g

# Nome do teste (passado como parâmetro)
TEST ?= 

SOURCES = ${SRC_DIR}/sequential_list.c ${TEST_DIR}/test_static_list.c
HEADERS = ${SRC_DIR}/sequential_list.h

EXEC = ${TEST}.test

all: ${EXEC}

${EXEC}: $(SOURCES) ${HEADERS}
	${CC} $(CFLAGS) -o ${EXEC} $(SOURCES)

clean:
	rm -f ${EXEC}

rebuild: clean all
