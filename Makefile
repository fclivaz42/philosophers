SUBDIR	= srcs

OBJDIR	= objs

SRCS	=	${SUBDIR}/philo.c\
			${SUBDIR}/philo_lft.c\
			${SUBDIR}/philo_utils.c\
			${SUBDIR}/philo_moment.c\
			${SUBDIR}/philo_output.c\

OBJ		= $(patsubst ${SUBDIR}/%.c, ${OBJDIR}/%.o, ${SRCS})

NAME	= philo

CFLAGS	= -Wall -Werror -Wextra -O2

LFLAGS = -lpthread

CC = gcc

${NAME}:	${OBJ}
			${CC} ${OBJ} -o ${NAME} ${LFLAGS}

${OBJDIR}/%.o:	${SUBDIR}/%.c | ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}:
		mkdir -p $@

all:	${NAME}

debug:
		${CC} -D DEBUG=1 ${SRCS} -o ${NAME} -g3 -fsanitize=address

tdbug:
		${CC} -D DEBUG=1 ${SRCS} -o ${NAME} -g3 -fsanitize=thread

extra:
		${CC} -D EXTRAL=5 -D EXTRAR=6 ${SRCS} -o ${NAME} ${LFLAGS} 

clean:
		rm -rf ${OBJDIR}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all fclean clean re