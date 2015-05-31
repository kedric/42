#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 15:28:59 by jmancero          #+#    #+#              #
#    Updated: 2013/12/29 16:26:57 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		pushswap

SOURCE =	main.c \
			ft_lst.c \
			func.c \

OBJ =		$(SOURCE:.c=.o)

LIBDIR =	libft/

LIB =		libft.a

FLAG =		-Wall -Wextra -Werror

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
