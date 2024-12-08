NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror 

SRCS	= push_swap.c

OFILES = $(SRCS:.c=.o)

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OFILES}
	cd libft && ${MAKE} && cp libft.a ../
#	ar rc ${NAME} ${OFILES}


clean:
	rm -rf ${OFILES}

fclean: clean
	cd libft && ${MAKE} fclean && cd ..
	rm -rf ${NAME} && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re
