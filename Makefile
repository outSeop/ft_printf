NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -c

SRC =	ft_printf.c \
		checkers.c \
		format.c \
		trance1.c \
		trance2.c \
		utils.c \

LIBFTC =	libft/ft_itoa.c \
			libft/ft_strdup.c \
			libft/ft_memset.c \
			libft/ft_strlen.c \
			libft/ft_isdigit.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
