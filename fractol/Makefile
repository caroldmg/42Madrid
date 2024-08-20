#In order to use the functions in MLX, you'll need to link it with your application.
# 	-ldl -lglfw(3) -pthread -lm

NAME := fractol
CFLAGS := -Wextra -Wall -Werror #-Wunreachable-code -Ofast
LIBMLX := ./MLX42/
LIBFT := ./libft/
PRINTF := ./ft_printf/

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)build/libmlx42.a -ldl -lglfw -pthread -lm \
			$(LIBFT)libft.a \
			$(PRINTF)libftprintf.a

SRCS := key_hooks.c \
OBJS := ${SRCS:.c=.o}

all: libmlx libft ft_printf $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

ft_printf:
	@make -C $(PRINTF)


%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) libft ft_printf
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(PRINTF) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx