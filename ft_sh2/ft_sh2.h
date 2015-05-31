/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 22:44:05 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/25 09:13:16 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH2_H
# define FT_SH2_H
# define BUFF_SIZE 4096
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <signal.h>

typedef struct		s_env
{
	char	**path;
	char	*ps1;
	char	*home;
	char	*pwd;
	char	**environ;
	int		pid;
}					t_env;

typedef struct		s_cmd
{
	char			*name;
	char			*value;
	char			*file;
	int				sfd;
	struct s_cmd	*next;
}					t_cmd;

void	sh_cd(char **av, t_env *env);
void	copy_env(t_env *env);
void	parse_environ(t_env *env);
void	start(void);
char	*ft_strdelc(const char *s, char c);
int		assign_file_out(t_cmd *cmd);
t_cmd	*ft_parse_cmd(char *av);
t_cmd	*parse_cmd(char **tmpstr, t_cmd *start);
t_cmd	*clean_cmd(t_cmd *start);
void	parse_name(t_cmd *cmd);
t_env	*return_env(void);
void	ft_sh1_relance(t_cmd *cmd, char **av, t_env *env);
void	ft_sh2_relance2(char **av, t_env *env, t_cmd *cmd, int i);
t_cmd	*sh_wait_new_commande(char *buff, t_env *env, t_cmd *cmd);
void	ft_setenv(char **av, t_env *env);
void	ft_pipe(t_cmd *cmd, char **av, t_env *env);
void	ft_init_signal(void);
t_cmd	*sh_wait_new_commande(char *buff, t_env *env, t_cmd *cmd);
void	ft_init_prompte(char *name, char **av, t_env *env, int i);
int		sh_execute(char *name, char **av, t_env *env);
void	ft_unsetenv(char **av, t_env *env);
void	outputs_file(char *file, char **av, t_env *env, t_cmd *cmd);
void	inputs_file(char *file, char **av, t_env *env, t_cmd *cmd);
void	ft_free_cmd(t_cmd *cmd);
void	fg(void);
char	*ft_getenv(t_env *env, char *search);

#endif /*!FT_SH2_H*/
