NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Wall -I. -c

SRC =	ft_printf.c \
		checkers.c \
		format.c \
		trance1.c \
		trance2.c \
		utils.c \

LIBFTC =	libft/ft_isdisit.c \
			libft/ft_itoa.c \
			libft/ft_strudup.c \
			libft/ft_memset.c \
			libft/ft_strlen.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

	
$ (OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
