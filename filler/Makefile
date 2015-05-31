#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 22:10:13 by jmancero          #+#    #+#              #
#    Updated: 2014/01/25 10:07:58 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =      filler

SOURCE =    main.c \
			parser.c \

DEP =       filler.h

OBJ =       $(SOURCE:.c=.o)

LIBDIR =    libft/

LIB =       libft/libft.a

CC =        clang

FLAG =      -Wall -Wextra -Werror

.PHONY: re fclean

all: $(NAME)

$(LIB):
	@$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ)
	@$(CC) -o $(NAME) $(FLAG) $(LIB) $^ -ltermcap
	@rm -f $(DEP).gch
	@echo "[\033[33;32mCompilation \033[33;34m$(NAME) \
	\033[33;32mok\033[33;0m]"

%.o: $(DEP) %.c
	@$(CC) -c $(FLAG) $^

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
