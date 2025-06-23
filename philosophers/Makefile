
# COLORINCHIS

GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
BLUE := \033[0;36m
RESET := \033[0m

CC = cc
NAME := philo
CFLAGS := -Wextra -Wall -Werror -pthread -g3 #-fsanitize=address 

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
	@$(CC) $(OBJS) -o $(NAME)
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

norma: 
	@echo "$(CIAN)SCRIPTS\n$(COLOREND)"
	@for file in $(SRC); do \
		norminette $$file | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$file: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$file; \
			echo "$(COLOREND)"; \
		fi \
	done
	@echo "$(CIAN)\nHEADERS\n$(COLOREND)"
	@for header in $(HEADERS); do \
		norminette $$header | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$header: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$header; \
			echo "$(COLOREND)"; \
		fi \
	done

re: fclean all

.PHONY: all, clean, fclean, re, exec