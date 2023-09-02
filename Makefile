CFILES = ./srcs/singly_linked_list.c
HEADERS = ./includes/singly_linked_list.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
OFILES = ${CFILES:.c=.o}
LIB = ./bin/sll.a
EXEC = ./bin/sll

.PHONY: all clean fclean re

all: ${LIB} ${EXEC}

${LIB}: ${OFILES}
	ar rcs $@ $<

${OFILES}: ${CFILES}
	${CC} ${CFLAGS} -c $< -o $@

${EXEC}: ${LIB}
	${CC} ${CFLAGS} ./srcs/main.c $< -o $@

clean:
	rm ${OFILES}

fclean: clean
	rm ${LIB}
	rm ${EXEC}

re: fclean all
