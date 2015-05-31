#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 22:10:13 by jmancero          #+#    #+#              #
#    Updated: 2013/12/29 10:11:45 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =      ft_minishell1

SOURCE =    main.c \
			ft_setenv.c \
			ft_strdelc.c

OBJ =       $(SOURCE:.c=.o)

LIBDIR =    libft/

LIB =       libft.a

FLAG =      -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	cd $(LIBDIR) && $(MAKE)
	gcc -c $(FLAG)  $(SOURCE)
	gcc -o $(NAME) $(FLAG) $(OBJ) $(LIBDIR)$(LIB)

clean :
	cd $(LIBDIR) && $(MAKE) $@
	rm -f $(OBJ)

fclean : clean
	cd $(LIBDIR) && $(MAKE) $@
	rm -f $(NAME)

re : fclean all
