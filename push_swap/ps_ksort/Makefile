NAME		=	push_swap

HEADER		=	-I $(INC)

CFLAGS = -Wall -Wextra -Werror -g3 $(HEADER) #-fsanitize=address 
CC = cc

# Directories
LIBFT_DIR = libft/
SRC_DIR		= srcs/
INC			= ./includes

SRC = 	$(SRC_DIR)commands/push.c \
			$(SRC_DIR)commands/reverse_rotate.c \
			$(SRC_DIR)commands/rotate.c \
			$(SRC_DIR)commands/swap.c \
		$(SRC_DIR)push_swap.c \
		$(SRC_DIR)ps_stack_init.c \
		$(SRC_DIR)ps_stack_utils.c \
		$(SRC_DIR)small_sort.c \
		$(SRC_DIR)ps_sort.c \
		$(SRC_DIR)ps_checks.c \
		$(SRC_DIR)main.c \
		$(SRC_DIR)ps_error_free.c \

OBJ			=	$(SRC:.c=.o)

LIBFT		=	$(LIBFT_DIR)libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
