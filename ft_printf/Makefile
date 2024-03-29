CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c \

OBJECTS = $(SOURCE:.c=.o)
NAME = libftprintf.a

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) ./$(NAME)
	ar rcs $(NAME) $(OBJECTS)

$(LIBFT):
	@make -C ./libft

clean:
	@make fclean -C ./libft
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re