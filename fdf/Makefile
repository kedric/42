#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 15:32:07 by mgaspail          #+#    #+#              #
#    Updated: 2013/12/21 15:25:10 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = cc

FLAG = -Werror -Wextra -Wall

SRC =	main.c \
		fdf_line.c \
		fdf_tab.c \
		fdf_took.c \

LIB = -L./libft -lft -L/usr/X11/lib -lXext -lX11 -lmlx

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAG) -O1 -o $(NAME) $^ $(LIB)

%.o: %.c
	$(CC) $(FLAG) -I libft/includes/ -c $<

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
