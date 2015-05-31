#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 22:10:13 by jmancero          #+#    #+#              #
#    Updated: 2014/02/08 13:20:10 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		ft_minishell3

SRCBUILT =	src/builtin/

SRCEXEC = src/exec/

SRCOUTP = src/output/

SRCPARS = src/parse/

SRCTERM = src/termcaps/

SRCCOLO = src/color/

INCDIR =	include/

SOURCE =	src/main.c \
			$(SRCBUILT)ft_setenv.c \
			$(SRCPARS)parse_cmd.c \
			$(SRCOUTP)ft_outpout.c \
			$(SRCBUILT)signaux.c \
			$(SRCBUILT)hist.c \
			$(SRCEXEC)recurs.c \
			$(SRCEXEC)execute.c \
			$(SRCPARS)parse_cmd2.c \
			$(SRCTERM)termcaps.c \
			$(SRCTERM)stomp.c \
			$(SRCTERM)del_c.c \
			$(SRCTERM)smoove.c \
			$(SRCTERM)arrow.c \
			$(SRCCOLO)print_color.c \
			$(SRCPARS)quote.c \

DEP =       ft_sh.h

OBJ =       $(SOURCE:.c=.o)

LIBDIR =    libft/

LIB =       libft/libft.a

CC =        gcc

FLAG =      -Wall -Wextra -Werror -O3  -I $(INCDIR)

.PHONY: re fclean

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
