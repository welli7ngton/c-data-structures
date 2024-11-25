# Nome do arquivo a ser testado (passado como parâmetro)
TEST ?= 

SRC_DIR = src
TEST_DIR = test

CC = gcc
CFLAGS = -Wall -Wextra -g


SOURCES = ${SRC_DIR}/${TEST}/${TEST}.c ${TEST_DIR}/${TEST}.c
HEADERS = ${SRC_DIR}/${TEST}/${TEST}.h

EXEC = ${TEST}.test

all: ${EXEC}

${EXEC}: $(SOURCES) ${HEADERS}
	${CC} $(CFLAGS) -o ${EXEC} $(SOURCES)

clean:
	rm -f *.test

rebuild: clean all
