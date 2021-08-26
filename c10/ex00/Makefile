SRCS = ft_display_file.c
OBJS = ${SRCS:.c=.o}
NAME = ft_display_file
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
