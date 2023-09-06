CFILES = ./srcs/singly_linked_list.c
HEADERS = ./includes/singly_linked_list.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
OFILES = ${CFILES:.c=.o}
LIB = ./bin/sll.a
DEMO = ./bin/sll
BENCHMARKS = ./bin/bm

.PHONY: all clean fclean re

all: ${LIB} ${DEMO} ${BENCHMARKS}

${LIB}: ${OFILES}
	ar rcs $@ $<

${OFILES}: ${CFILES}
	${CC} ${CFLAGS} -c $< -o $@

${DEMO}: ${LIB}
	${CC} ${CFLAGS} ./srcs/main.c $< -o $@

${BENCHMARKS}: ${LIB}
	${CC} ${CFLAGS} ./srcs/benchmarks.c $< -o $@

clean:
	rm ${OFILES}

fclean: clean
	rm ${LIB}
	rm ${DEMO}
	rm ${BENCHMARKS}

re: fclean all
