#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:04:18 by jmancero          #+#    #+#              #
#    Updated: 2013/12/31 11:54:58 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME =		pipex

SOURCE =	main.c \
			ft_strsplit.c \
			ft_puterr.c \
			ft_strlen.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strncmp.c \

OBJ =	$(SOURCE:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $^

%.o : %.c
	gcc -c $(FLAG) $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
