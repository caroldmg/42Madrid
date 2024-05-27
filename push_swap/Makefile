CFLAGS = -Wall -Wextra -Werror
CC = gcc
SOURCE = push_swap.c
OBJECTS = $(SOURCE:.c=.o)
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(OBJECTS): $(SOURCE)
	$(CC) $(CFLAGS) -c $(SOURCE)

$(LIBFT):
	$(MAKE) -C ./libft

$(PRINTF):
	$(MAKE) -C ./ft_printf

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)

re: fclean all