#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 22:10:13 by jmancero          #+#    #+#              #
#    Updated: 2014/01/25 18:24:50 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =      ft_minishell2

SOURCE =    main.c \
			ft_setenv.c \
			ft_strdelc.c \
			parse_cmd.c \
			ft_outpout.c \
			signaux.c \
			recurs.c \
			execute.c \
			parse_cmd2.c \

DEP =       ft_sh2.h

OBJ =       $(SOURCE:.c=.o)

LIBDIR =    libft/

LIB =       libft/libft.a

CC =        cc

FLAG =      -Wall -Wextra -Werror -O4

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
