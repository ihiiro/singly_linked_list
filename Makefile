# ░██████╗██╗███╗░░██╗░██████╗░██╗░░░░░██╗░░░██╗░░░░░░
# ██╔════╝██║████╗░██║██╔════╝░██║░░░░░╚██╗░██╔╝░░░░░░
# ╚█████╗░██║██╔██╗██║██║░░██╗░██║░░░░░░╚████╔╝░█████╗
# ░╚═══██╗██║██║╚████║██║░░╚██╗██║░░░░░░░╚██╔╝░░╚════╝
# ██████╔╝██║██║░╚███║╚██████╔╝███████╗░░░██║░░░░░░░░░
# ╚═════╝░╚═╝╚═╝░░╚══╝░╚═════╝░╚══════╝░░░╚═╝░░░░░░░░░
# ██╗░░░░░██╗███╗░░██╗██╗░░██╗███████╗██████╗░░░░░░░██╗░░░░░██╗░██████╗████████╗
# ██║░░░░░██║████╗░██║██║░██╔╝██╔════╝██╔══██╗░░░░░░██║░░░░░██║██╔════╝╚══██╔══╝
# ██║░░░░░██║██╔██╗██║█████═╝░█████╗░░██║░░██║█████╗██║░░░░░██║╚█████╗░░░░██║░░░
# ██║░░░░░██║██║╚████║██╔═██╗░██╔══╝░░██║░░██║╚════╝██║░░░░░██║░╚═══██╗░░░██║░░░
# ███████╗██║██║░╚███║██║░╚██╗███████╗██████╔╝░░░░░░███████╗██║██████╔╝░░░██║░░░
# ╚══════╝╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚══════╝╚═════╝░░░░░░░╚══════╝╚═╝╚═════╝░░░░╚═╝░░░
# Author: Hiro (ihiiro)
# Email: yassirelyakine@gmail.com
# License: MIT
# Start: 2023
# Update: 2023

CFILES = srcs/traversers.c srcs/non_traversers.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OFILES = ${CFILES:.c=.o}
LIB = sll.a
TESTS = tests
BENCHMARKS = bm

.PHONY: all clean fclean re

all: ${LIB} ${TESTS} ${BENCHMARKS}

${LIB}: ${OFILES}
	ar rcs $@ $^

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${TESTS}: ${LIB}
	${CC} ${CFLAGS} srcs/tests.c $< -o $@

${BENCHMARKS}: ${LIB}
	${CC} ${CFLAGS} srcs/benchmarks.c $< -o $@

clean:
	rm ${OFILES}

fclean: clean
	rm ${LIB}
	rm ${TESTS}
	rm ${BENCHMARKS}

re: fclean all