
# COLORINCHIS

GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
BLUE := \033[0;36m
RESET := \033[0m

CC = cc
NAME := philo
CFLAGS := -Wextra -Wall -Werror -g3 #-pthread 

OBJ_DIR = obj

SRCS := main.c \
		check_input.c \
		monitor.c \
		utils.c \
		routine.c \
		philo_death.c \
		libft_utils.c \
		init_philo.c \
		philo_states.c \
		error_check.c \

OBJ_NAMES = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<


$(NAME): $(OBJS)
	@$(CC) $(OBJS) -fsanitize=thread -o $(NAME)
	@echo "$(GREEN)Compilación completada con éxito.$(RESET)"


clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN) Todo limpito!!! $(RESET)"

fclean: clean
	@echo "$(RED)Limpiando todo...$(RESET)"
	@rm -rf $(NAME)
	@echo "$(GREEN) ¡Todo limpio! $(RESET)"

exec:
	./$(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, exec