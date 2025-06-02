
# COLORINCHIS

GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
BLUE := \033[0;36m
RESET := \033[0m

CC = cc
NAME := philo
CFLAGS := -g3 -Wextra -Wall -Werror -pthread #-fsanitize=address

INCL_DIR := ./inc
SRC_DIR := ./srcs
OBJ_DIR := ./obj
LIBFT_DIR := ./libft

HEADERS	:=	-I $(LIBFT_DIR) $(OBJ) $(LIBFT) \

LIBFT :=	$(LIBFT_DIR)libft.a

SRCS := main.c \
		check_input.c \

OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -I $(INCL_DIR) -o $@ -c $<


$(NAME): obj $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compilación completada con éxito.$(RESET)"


clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@echo "$(RED)Limpiando todo...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN) ¡Todo limpio! $(RESET)"

norma: 
	norminette $(SRCS) $(INCL_DIR)

re: clean all

.PHONY: all, clean, fclean, re