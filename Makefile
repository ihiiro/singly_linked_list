CFILES = ./srcs/singly_linked_list.c
HEADERS = ./includes/singly_linked_list.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
OFILES = ${CFILES:.c=.o}
LIB = ./bin/sll.a
TESTS = ./bin/tests
BENCHMARKS = ./bin/bm

.PHONY: all clean fclean re

all: ${LIB} ${TESTS} ${BENCHMARKS}

${LIB}: ${OFILES}
	ar rcs $@ $<

${OFILES}: ${CFILES}
	${CC} ${CFLAGS} -c $< -o $@

${TESTS}: ${LIB}
	${CC} ${CFLAGS} ./srcs/tests.c $< -o $@

${BENCHMARKS}: ${LIB}
	${CC} ${CFLAGS} ./srcs/benchmarks.c $< -o $@

clean:
	rm ${OFILES}

fclean: clean
	rm ${LIB}
	rm ${TESTS}
	rm ${BENCHMARKS}

re: fclean all
