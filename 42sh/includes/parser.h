/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 12:16:53 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:57:05 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PARSER_H
# define	PARSER_H

# define	FD_IN			fd[0]
# define	FD_OUT			fd[1]
# define	FD_ERR			fd[2]
# define	NEED_NO_SUCCESS	0
# define	NEED_SUCCESS	1
# define	NO_CARE_SUCCESS	2
# define	BACKGROUND		1
# define	FOREGROUND		0

typedef enum			e_bool
{
	TRUE = 1, FALSE = 0
}						t_bool;

typedef enum			e_sym
{
	redir_in, redir_out, redir_err, append, pipes, log_and, log_or, bg, colon, \
	word, redir_dest, unknown
}						t_sym;

typedef struct			s_token
{
	t_sym				type;
	char				*str;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct			s_process
{
	char				**av;
	int					fd[3];
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

typedef struct			s_job
{
	t_token				*token_lst;
	char				need_success;
	t_process			*first_process;
	struct s_job		*next;
	struct s_job		*prev;
}						t_job;

typedef struct			s_command
{
	t_token				*token_lst;
	t_job				*first_job;
	char				background;
	struct s_command	*next;
	struct s_command	*prev;
}						t_command;

t_bool					is_op_char(char c);
t_bool					is_ok_char(char c);
t_sym					is_word(char *str);
t_sym					is_redir_operator(char *str);
t_sym					is_separator(char *str);
t_sym					is_background_operator(char *str);
t_sym					is_logical_operator(char *str);
t_sym					is_operator(char *str);
char					*get_token_str(char **str);
t_sym					get_token_type(char *str);
t_token					*get_token_lst(char *str);
t_token					*create_token(void);

t_token					*token_lst_add(t_token *new_token, t_token *token_list);
t_token					*token_add(char *str, t_sym type, t_token *token_list);
void					token_lst_free(t_token **token_lst);
t_token					*token_lst_print(t_token *token_lst);
void					token_free(t_token **token);

t_bool					check_exp(t_token *token_lst);
t_bool					check_command(t_token *token_lst);
t_bool					check_redir(t_token *token_lst);
t_bool					check_pipe(t_token *token_lst);
t_bool					check_colon(t_token *token_lst);
t_bool					check_logical(t_token *token_lst);
t_bool					check_background(t_token *token_lst);

t_command				*parser(char *str);
t_command				*create_command(t_token *token_lst);
t_command				*command_lst_add(t_command *command_lst, \
											t_token *token, char background);
t_command				*make_command_lst(t_token *token_lst);
t_job					*create_job(t_token *token_lst, char need_success);
t_job					*make_job_lst(t_token *token_lst);
t_job					*job_lst_add(t_job *lst, t_token *token_lst, \
									char need_success);
t_process				*create_process(char *str);
t_process				*make_process_lst(t_token *token);
t_process				*process_lst_add(t_process *process, char *str);
t_process				*update_fd(t_token *token, t_process **current);
void					command_lst_free(t_command *command_lst);
void					job_lst_free(t_job *job_lst);
void					process_lst_free(t_process *process_lst);

void					command_lst_print(t_command *command_lst);
void					job_lst_print(t_job *job_lst);
void					process_lst_print(t_process *process_lst);
t_bool					parse_error(char *str);

#endif
