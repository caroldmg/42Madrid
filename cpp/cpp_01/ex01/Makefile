CC := c++
NAME := brainz
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -f

# COLORS
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \33[0;33m
RESET := \033[0m

SRCS := main.cpp \
		Zombie.cpp \
		zombieHorde.cpp \

OBJS := $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

obj:

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	@clear
	@echo "$(YELLOW)\t 🧹 Limpito 🧽$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@clear
	@echo "$(YELLOW)\t 🧹 Limpito! 🧽 $(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re
