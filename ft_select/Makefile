#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:04:18 by jmancero          #+#    #+#              #
#    Updated: 2014/01/11 18:31:30 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME =		ft_select

SOURCE =	main.c \
			signal.c \
			write.c \
			init.c \
			size.c \

LIBDIR =    libft/

LIB =       libft.a

OBJ =	$(SOURCE:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBDIR)
	gcc -o $(NAME) $(FLAG) $(LIBDIR)$(LIB) $^ -ltermcap

%.o : %.c
	gcc -c $(FLAG) $^

clean :
	cd $(LIBDIR) && $(MAKE) $@
	rm -f $(OBJ)

fclean : clean
	cd $(LIBDIR) && $(MAKE) $@
	rm -f $(NAME)

re : fclean all
