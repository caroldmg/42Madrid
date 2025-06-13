
# COLORINCHIS

GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
BLUE := \033[0;36m
RESET := \033[0m

CC = cc
NAME := philo
CFLAGS := -Wextra -Wall -Werror -pthread #-fsanitize=address -g3

OBJS = $(SRC:.c=.o)

SRCS := main.c \
		check_input.c \

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)


%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<


$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilación completada con éxito.$(RESET)"


clean:
	@rm -rf $(OBJS)
	@echo "$(GREEN) Todo limpito!!! $(RESET)"

fclean:
	@echo "$(RED)Limpiando todo...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
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

.PHONY: all, clean, fclean, re