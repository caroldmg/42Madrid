# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 17:04:54 by cde-migu          #+#    #+#              #
#    Updated: 2024/03/26 18:03:14 by cde-migu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP = gcc -Wall -Werror -Wextra -fsanitize=address
NAME = gnl
OBJ = get_next_line.c get_next_line_utils.c

OBJS = $(OBJ:%.c=%.o)

%.o: %.c
	@echo " ◎ Compiling   →   $< "
	@$(CC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(OBJS) -o $(NAME)

bonus:

clean:
	@echo "Supressing binary objects"
	@rm -f $(OBJS)

fclean: clean
	@echo "Supressing binary executable"
	@rm -f $(NAME)

re: fclean all
