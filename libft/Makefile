NAME		= libft.a

SRCS = 	ft_strrchr.c ft_isalnum.c ft_memset.c ft_strnstr.c ft_putchar_fd.c \
		ft_striteri.c ft_split.c ft_memchr.c ft_substr.c ft_strlcat.c ft_strjoin.c \
		ft_bzero.c ft_strncmp.c ft_strmapi.c ft_putstr_fd.c ft_isdigit.c ft_isalpha.c \
		ft_memcpy.c ft_isprint.c ft_atoi.c ft_strlcpy.c ft_toupper.c ft_itoa.c \
		ft_strtrim.c ft_putendl_fd.c ft_strchr.c ft_memmove.c ft_strdup.c ft_strlen.c \
		ft_tolower.c ft_isascii.c ft_calloc.c ft_putnbr_fd.c ft_memcmp.c \
		ft_lstlast.c ft_lstadd_front.c ft_lstnew.c ft_lstmap.c ft_lstclear.c \
		ft_lstadd_back.c ft_lstsize.c ft_lstdelone.c ft_lstiter.c \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror 

OFILES = $(SRCS:.c=.o)

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OFILES}
	ar rc ${NAME} ${OFILES}

clean:
	rm -rf ${OFILES}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
