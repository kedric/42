# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/27 19:17:42 by jmancero          #+#    #+#              #
#    Updated: 2014/04/19 08:06:00 by jmancero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =			libft_malloc_$(HOSTTYPE).so

SOURCE =	malloc.c \
			format.c \
			free.c \
			ft_bzero.c \
			print.c

OBJ =		$(SOURCE:.c=.o)

CC =		clang

FLAG =		-Wall -Wextra -Werror -O3

RED = \033[33;31m
BLUE = \033[33;34m
GREEN = \033[33;32m
RESET = \033[0m

.PHONY: all re fclean

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) -shared -o $(NAME) $(OBJ) $(FLAG)
		@echo "[$(GREEN)Compilation $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"
		@ln -s libft_malloc_$(HOSTTYPE).so libft_malloc.so

%.o: %.c
		@$(CC) -c -o $@ $(FLAG) $^

clean:
	@rm -f $(OBJ)
	@echo "[$(RED)Supression des .o de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

fclean: clean
		@rm -f $(NAME)
		@echo "[$(RED)Supression de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"
		@rm -f libft_malloc.so

re: fclean all
