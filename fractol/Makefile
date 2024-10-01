
CC = cc
NAME := fractol
CFLAGS := -g3 -Wextra -Wall -Werror  #-Wunreachable-code -Ofast

MAKEFLAGS = --no-print-directory

# COLORINCHIS

GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
BLUE := \033[0;34m
RESET := \033[0m

LIBMLX := ./MLX42/
LIBFT_DIR := ./libft/
PRINTF_DIR := ./ft_printf/

INCL_DIR := ./incl
SRC_DIR := ./srcs
OBJ_DIR := ./obj

HEADERS	:=	 \
			 -I $(LIBFT_DIR) $(OBJ) $(LIBFT) \
			 -I $(PRINTF_DIR) $(OBJ) $(PRINTF)

MLX_HEADER := -I $(LIBMLX)include/MLX42 

MLX	:= $(LIBMLX)build/libmlx42.a
MLX_FLAGS	:= -ldl -lglfw -pthread -lm 


LIBFT :=	$(LIBFT_DIR)libft.a 

PRINTF :=	$(PRINTF_DIR)libftprintf.a

SRCS := 	complex_maths.c \
			julia_mandel.c \
			init.c \
			main.c \
			hooks.c \
			ft_errors.c \
			phoenix.c \
			colors.c \

OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))

all: $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(MLX):
	cmake $(LIBMLX) -B $(LIBMLX)build && make -C $(LIBMLX)build -j4 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) $(MLX_HEADER) -I $(INCL_DIR) -o $@ -c $<

$(NAME): obj $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(OBJS) $(MLX) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Compilación completada con éxito.$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean:
	@echo "$(RED)Limpiando todo...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(GREEN) ¡Todo limpio! $(RESET)"

norma: 
	norminette $(SRCS) $(HEADERS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx