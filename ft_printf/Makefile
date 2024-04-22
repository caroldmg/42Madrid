# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 13:00:50 by cde-migu          #+#    #+#              #
#    Updated: 2024/04/22 13:00:53 by cde-migu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c \
         printf_puts.c \

OBJECTS = $(SOURCE:.c=.o)
NAME = libftprintf.a

#LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
#$(NAME): $(LIBFT) $(OBJECTS)
#	cp $(LIBFT) ./$(NAME)
	ar rcs $(NAME) $(OBJECTS)

#$(LIBFT):
#	@make -C ./libft

clean:
#	@make fclean -C ./libft
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re