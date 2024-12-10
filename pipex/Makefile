CC = cc
NAME := pipex
NAME_BONUS := pipex
CFLAGS := -g3 -Wextra -Werror -Wall

MAKEFLAGS = --no-print-directory


GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
BLUE := \033[0;34m
RESET := \033[0m

LIBFT_DIR := ./libft/
PRINTF_DIR := ./ft_printf/

INCL_DIR := ./incl
SRC_DIR := ./src
BONUS_DIR := ./src_bonus
OBJ_DIR := ./obj

HEADERS :=	\
			-I $(LIBFT_DIR) $(OBJ) $(LIBFT) \
			-I $(PRINTF_DIR) $(OBJ) $(PRINTF) \

LIBFT :=	$(LIBFT_DIR)libft.a 

PRINTF :=	$(PRINTF_DIR)libftprintf.a

SRCS :=		utils.c \
			pipex.c \
			main.c \

SRC_BONUS := main_bonus.c \
			pipex_bonus.c \
			utils_bonus.c \
			here_doc_bonus.c \


OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
BONUS := $(addprefix $(BONUS_DIR)/,$(SRC_BONUS))
BONUS_OBJ := $(addprefix $(OBJ_DIR)/,$(SRC_BONUS:.c=.o))

all: $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/pipex.h
	$(CC) $(CFLAGS) $(HEADERS) -I $(INCL_DIR) -o $@ -c $<

$(NAME): obj $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)Compilación completada con éxito.$(RESET)"

test:
	echo $(BONUS)

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(INCL_DIR)/pipex.h
	$(CC) $(CFLAGS) $(HEADERS) -I $(INCL_DIR) -o $@ -c $<

bonus: obj $(OBJS) $(BONUS_OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(BONUS_OBJ) $(LIBFT) $(PRINTF) -o $(NAME_BONUS)
	@echo "$(GREEN)Compilación completada con éxito.$(RESET)"
# @rm -f pipex

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean:
	@echo "$(RED)Limpiando todo...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf $(OBJ_DIR)
	@rm -f here_doc
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(GREEN) ¡Todo limpio! $(RESET)"

re: clean all