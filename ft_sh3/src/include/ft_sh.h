/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 22:44:05 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 10:59:17 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# define BUFF_SIZE 4096
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include "color.h"



typedef struct		s_env
{
	char	**path;
	char	*ps1;
	int		ps1_len;
	char	*home;
	char	pwd[BUFF_SIZE];
	char	**environ;
	int		pid;
}					t_env;

typedef struct		s_hist
{
	char			value[BUFF_SIZE];
	int				pose_cursor;
	int				len;
	int				modif;
	char			buff[BUFF_SIZE];
	int				exec;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

typedef struct		s_term
{
	struct termios	term;
	struct termios	term_ori;
	int				fd;
	int				ps1_len;
	char			**key;
	int				quote;
	int				dquote;
	int				wait_fermeture;
	t_hist			*hist;
}					t_term;

typedef struct		s_cmd
{
	char			*name;
	char			*value;
	char			*file;
	int				sfd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_config
{
	char				param[BUFF_SIZE];
	char				value[BUFF_SIZE];
	struct	s_config	*next;
}					t_config;

t_term	*recup_term(void);
void	sh_cd(char **av, t_env *env);
void	copy_env(t_env *env);
void	parse_environ(t_env *env);
void	start(void);
int		assign_file_out(t_cmd *cmd);
t_cmd	*ft_parse_cmd(char *av);
t_cmd	*parse_cmd(char **tmpstr, t_cmd *start);
t_cmd	*clean_cmd(t_cmd *start);
void	parse_name(t_cmd *cmd);
t_env	*return_env(void);
void	ft_sh1_relance(t_cmd *cmd, char **av, t_env *env);
void	ft_sh2_relance2(char **av, t_env *env, t_cmd *cmd, int i);
void	ft_setenv(char **av, t_env *env);
void	ft_pipe(t_cmd *cmd, char **av, t_env *env);
void	ft_init_signal(void);
t_cmd	*sh_wait_new_commande(t_env *env, t_cmd *cmd);
void	ft_init_prompte(char **av, t_env *env, int i);
int		sh_execute(char *name, char **av, t_env *env);
void	ft_unsetenv(char **av, t_env *env);
void	outputs_file(char *file, char **av, t_env *env, t_cmd *cmd);
void	inputs_file(char *file, char **av, t_env *env, t_cmd *cmd);
void	ft_free_cmd(t_cmd *cmd);
void	init_term(void);
void	close_term(void);
int		ft_stomp(char *buff, t_term *term);
void	enter_key(char *key);
void	parse_ps1(t_env *env);
char	*ft_getenv(char **env, char *search);
void	press_quote(t_term *term);
void	press_dquote(t_term *term);
void	press_ctrld(t_term *term);


/*
** term cap
*/
void	arrow_left(t_term *term);
void	clear(t_term *term);
void	arrow_right(t_term *term);
void	arrow_up(t_term *term);
void	arrow_down(t_term *term);

t_hist	*add_ellement_hist(t_hist *hist);
t_hist	*add_or_clean(t_hist *hist);
int		clean_hist(t_hist *hist);
void	put_strdel(t_term *term);
void	reset_buffer(t_term *term);
void	put_stradd(t_term *term, char *buff);
void	clean_line(t_term *term);
void	ft_moove_w_left(t_term *term);
void	ft_moove_w_right(t_term *term);
void	ft_add_char(char *buff, t_term *term);

#endif /*!FT_SH_H*/
