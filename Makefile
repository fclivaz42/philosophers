SUBDIR	= srcs

OBJDIR	= objs

SRCS	=	${SUBDIR}/philo.c\
			${SUBDIR}/philo_errors.c\
			${SUBDIR}/philo_lft.c\
			${SUBDIR}/philo_utils.c\


OBJ		= $(patsubst ${SUBDIR}/%.c, ${OBJDIR}/%.o, ${SRCS})

NAME	= philo

CFLAGS	= -Wall -Werror -Wextra -O2

CC = gcc

${NAME}:	${OBJ}
			${CC} ${OBJ} -o ${NAME}

${OBJDIR}/%.o:	${SUBDIR}/%.c | ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}:
		mkdir -p $@

all:	${NAME}

debug:
		${CC} -D DEBUG=1 ${SRCS} -o ${NAME} -fsanitize=address

clean:
		rm -rf ${OBJDIR}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all fclean clean re