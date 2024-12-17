CC = cc
NAME := pipex
NAME_BONUS := pipex_bonus
CFLAGS := -g3 -Wextra -Werror -Wall

MAKEFLAGS = --no-print-directory

GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
PURPLE := \033[0;35m
BLUE := \033[0;36m
CYAN := \033[1;36m
RESET := \033[0m

LIBFT_DIR := ./libft/
PRINTF_DIR := ./ft_printf/

INCL_DIR := ./incl
SRC_DIR := ./src
BONUS_DIR := ./src_bonus
OBJ_DIR := ./obj
OBJ_BONUS_DIR := ./obj_bonus

HEADERS := \
    -I $(LIBFT_DIR) \
    -I $(PRINTF_DIR) \
    -I $(INCL_DIR)

LIBFT := $(LIBFT_DIR)libft.a 
PRINTF := $(PRINTF_DIR)libftprintf.a

SRCS := utils.c \
        pipex.c \
        main.c \

SRC_BONUS := main_bonus.c \
            pipex_bonus.c \
            utils_bonus.c \
			proccess_bonus.c \
            here_doc_bonus.c \

OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
BONUS_OBJS := $(addprefix $(OBJ_BONUS_DIR)/,$(SRC_BONUS:.c=.o))
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
BONUS := $(addprefix $(BONUS_DIR)/,$(SRC_BONUS))
BONUS_EXEC := $(OBJ_BONUS_DIR)/$(NAME_BONUS).built

all: $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

obj_bonus:
	mkdir -p $(OBJ_BONUS_DIR)

$(LIBFT):
	@echo "$(CYAN)Compilando libft $(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "$(PURPLE)Compilando ft_printf $(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/pipex.h
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(INCL_DIR)/pipex.h
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): obj $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)Compilación completada con éxito.$(RESET)"

$(BONUS_EXEC): $(BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(BONUS_OBJS) $(LIBFT) $(PRINTF) -o $(NAME_BONUS)
	@touch $(BONUS_EXEC)

bonus: obj_bonus $(BONUS_EXEC)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean:
	@echo "$(RED)Limpiando todo...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@rm -f $(BONUS_EXEC)
	@rm -f here_doc
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(GREEN) ¡Todo limpio! $(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
