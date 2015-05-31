#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 22:10:13 by jmancero          #+#    #+#              #
#    Updated: 2014/03/08 17:43:15 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		puissance4

SRC =	src/

INCDIR =	includes/

SOURCE =	$(SRC)main.c \
			$(SRC)init_game.c \
			$(SRC)ia.c \
			$(SRC)check.c \

OBJ =		$(SOURCE:.c=.o)

LIBDIR =	libft/

LIB =		libft/libft.a

CC =		gcc

FLAG =		-Wall -Wextra -Werror -O4 -I $(INCDIR) -g

.PHONY: all re fclean

all: $(NAME)

$(LIB):
	@$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ)
	@$(CC) -o $(NAME) $(FLAG) $(LIB) $^ -ltermcap
	@rm -f $(DEP).gch
	@echo "[\033[33;32mCompilation \033[33;34m$(NAME) \
	\033[33;32mok\033[0m]"

%.o: %.c
	@$(CC) -c -o $@ $(FLAG) $^

clean:
	@cd $(LIBDIR) && $(MAKE) $@
	@rm -f $(OBJ)
	@echo "[\033[33;31mSupression des .o de \033[33;34m$(NAME) \
	\033[33;32mok\033[33;0m]"

fclean: clean
	@cd $(LIBDIR) && $(MAKE) $@
	@rm -f $(NAME)
	@echo "[\033[33;31mSupression de \033[33;34m$(NAME) \
	\033[33;32mok\033[33;0m]"

re: fclean all
