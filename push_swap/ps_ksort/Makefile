CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address 
CC = cc
SRC = 	push_swap.c \
		ps_stack_init.c \
		ps_stack_utils.c \
		ps_push.c \
		ps_swap.c \
		ps_reverse_rotate.c \
		ps_rotate.c \
		small_sort.c \
		ps_sort.c \
		ps_checks.c \
		main.c \
#		ps_split.c \

OBJ			=	$(SRC:.c=.o)
HEADER		=	push_swap.h

LIBFT_DIR	=	../libft/
LIBFT		=	$(LIBFT_DIR)/libft.a

# PRINTF_DIR	=	ft_printf
# PRINTF		=	$(PRINTF_DIR)/libftprintf.a

NAME		=	push_swap

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)

# $(PRINTF):
# 	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR)  -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
#	@$(MAKE) -C $(PRINTF_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
#	@$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all
