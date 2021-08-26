SRCS = ft_tail.c ft_atoi.c funcs.c
OBJS = ${SRCS:.c=.o}
NAME = ft_tail
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}:	${OBJS}

${OBJS}:	${SRCS}
			${CC} ${CFLAGS} -c ${SRCS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
