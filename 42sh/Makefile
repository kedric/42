# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/27 19:17:42 by pdjamei           #+#    #+#              #
#    Updated: 2014/03/27 19:47:52 by mcassagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			42sh

SRC			=	src/

SRCTERM		=	$(SRC)termcaps/

SRCENV		=	$(SRC)parsing_env/

SRCPARSER	=	$(SRC)parser/

SRCCMD		=	$(SRC)command/

SRCBULT		=	$(SRC)builtin/

SRCERR		=	$(SRC)error/

INCDIR =	includes/

SOURCE =	main.c \
			$(SRCBULT)ft_pwd.c \
			$(SRCBULT)ft_cd.c \
			$(SRCBULT)ft_echo.c \
			$(SRCBULT)builtin.c \
			$(SRCBULT)ft_builtin.c \
			$(SRCBULT)ft_env.c \
			$(SRCBULT)ft_putenv.c \
			$(SRCBULT)ft_found.c \
			$(SRCBULT)ft_help.c \
			$(SRCBULT)ft_setenv.c \
			$(SRCCMD)ft_command.c \
			$(SRCCMD)ft_close_pipe.c \
			$(SRCCMD)ft_fork.c \
			$(SRCCMD)launch_job.c \
			$(SRCCMD)launch_process.c \
			$(SRCCMD)check_redirection.c \
			$(SRCCMD)find_path.c \
			$(SRCCMD)free_all.c \
			$(SRCCMD)get_and_put_env.c \
			$(SRCCMD)know_access.c \
			$(SRCCMD)ft_run_builtin.c \
			$(SRCERR)error.c \
			$(SRCTERM)termcaps.c \
			$(SRCTERM)init_term.c \
			$(SRCTERM)hist.c \
			$(SRCTERM)modif_buff2.c \
			$(SRCTERM)modif_buff.c \
			$(SRCTERM)arrow.c \
			$(SRCTERM)tc_move.c \
			$(SRCTERM)signal.c \
			$(SRCTERM)tc_move2.c \
			$(SRCENV)init_env.c \
			$(SRCENV)prompt.c \
			$(SRCENV)destroy_gen.c \
			$(SRCTERM)debug.c \
			$(SRCPARSER)check_exp.c \
			$(SRCPARSER)check_exp2.c \
			$(SRCPARSER)command_lst_add.c \
			$(SRCPARSER)command_lst_free.c \
			$(SRCPARSER)command_lst_print.c \
			$(SRCPARSER)create_command.c \
			$(SRCPARSER)create_job.c \
			$(SRCPARSER)create_process.c \
			$(SRCPARSER)get_token.c \
			$(SRCPARSER)get_token2.c \
			$(SRCPARSER)is_operator.c \
			$(SRCPARSER)is_word.c \
			$(SRCPARSER)job_lst_add.c \
			$(SRCPARSER)job_lst_free.c \
			$(SRCPARSER)job_lst_print.c \
			$(SRCPARSER)parser.c \
			$(SRCPARSER)make_command_lst.c \
			$(SRCPARSER)make_job_lst.c \
			$(SRCPARSER)make_process_lst.c \
			$(SRCPARSER)parse_error.c \
			$(SRCPARSER)process_lst_add.c \
			$(SRCPARSER)process_lst_free.c \
			$(SRCPARSER)process_lst_print.c \
			$(SRCPARSER)token_lst_add.c \
			$(SRCPARSER)token_lst_free.c \
			$(SRCPARSER)token_lst_print.c \
			$(SRCPARSER)update_fd.c

OBJ =		$(SOURCE:.c=.o)

LIBDIR =	libft/

LIB =		$(LIBDIR)libft.a

LIB_COMP =	-L ./$(LIBDIR) -lft

CC =		gcc

FLAG =		-I $(INCDIR) -Wall -Wextra -Werror -g

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
