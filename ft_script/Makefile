#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 22:10:13 by jmancero          #+#    #+#              #
#    Updated: 2014/04/30 00:29:18 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME 		=	ft_script

SRC			=	src/

INCDIR 		=	includes/

SOURCE 		=	$(SRC)main.c \
				$(SRC)open_pty.c\
				$(SRC)set_master.c\
					$(SRC)wait_fd.c\

OBJ 		=	$(SOURCE:.c=.o)

LIBDIR 		=	libft/

LIB 		=	$(LIBDIR)libft.a

LIB_COMP 	=	-L ./$(LIBDIR) -lft

CC 			=	gcc

FLAG 		=	-I $(INCDIR) -g

RED = \033[33;31m
BLUE = \033[33;34m
GREEN = \033[33;32m
RESET = \033[0m

.PHONY: all re fclean

all: $(NAME)

$(LIB):
		@$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ)
		@$(CC) -o $(NAME) $(FLAG) $^ -ltermcap $(LIB_COMP)
		@rm -f $(DEP).gch
		@echo "[$(GREEN)Compilation $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

%.o: %.c
		@$(CC) -c -o $@ $(FLAG) $^

clean:
	@cd $(LIBDIR) && $(MAKE) $@
	@rm -f $(OBJ)
	@echo "[$(RED)Supression des .o de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

fclean: clean
		@cd $(LIBDIR) && $(MAKE) $@
		@rm -f $(NAME)
		@echo "[$(RED)Supression de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

re: fclean all
