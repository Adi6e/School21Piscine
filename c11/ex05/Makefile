SRCS = do-op.c functions.c functions2.c
OBJS = ${SRCS:.c=.o}
NAME = do-op
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

re:			fclean all	
