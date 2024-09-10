#In order to use the functions in MLX, you'll need to link it with your application.
# 	-ldl -lglfw(3) -pthread -lm

NAME := fractol
CFLAGS := -g3 -Wextra -Wall -Werror  #-Wunreachable-code -Ofast

MAKEFLAGS = --no-print-directory

LIBMLX := ./MLX42/
LIBFT_DIR := ./libft/
PRINTF_DIR := ./ft_printf/

HEADERS	:=	 \
			 -I $(LIBFT_DIR) $(OBJ) $(LIBFT) \
			 -I $(PRINTF_DIR) $(OBJ) $(PRINTF) \
			 -I $(LIBMLX)include/MLX42 \
			 

MLX	:= $(LIBMLX)build/libmlx42.a
MLX_FLAGS	:= -ldl -lglfw -pthread -lm 


LIBFT :=	$(LIBFT_DIR)libft.a 

PRINTF :=	$(PRINTF_DIR)libftprintf.a

SRCS := 	complex_maths.c \
			draw.c \
			fractal_init.c \
			mandelbrot.c \
			main.c \
			parse.c \

# SRCS := 	key_hooks.c

OBJS := ${SRCS:.c=.o}

all: $(MLX) $(LIBFT) $(PRINTF) $(NAME)

$(MLX):
	cmake $(LIBMLX) -B $(LIBMLX)build && make -C $(LIBMLX)build -j4 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(OBJS) $(MLX) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx