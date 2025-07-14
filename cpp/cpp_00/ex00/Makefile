
CC := c++
NAME := megaphone
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -f

# COLORS
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \33[0;33m
RESET := \033[0m


SRCS := megaphone.cpp

OBJS := $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

obj:

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	@clear
	@echo "$(BLUE)Limpito$(RESET)"

fclean:
		$(RM) $(NAME)
		clean

re: fclean all

.PHONY: all, clean, fclean, re


23.1428571429