/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outpout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:05 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/01 09:42:43 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ex_pipe(char **av, char **path, char **env)
{
	int		i;
	int		ret_exe;
	char	*tmp;

	ret_exe = -1;
	i = 0;
	while (ret_exe < 0 && *path[i] != 0)
	{
		tmp = ft_strjoin(path[i], av[0]);
		if ((ret_exe = execve(tmp, av, env))
			&& path[i + 1] == 0 && av[0][0] != '\0')
		{
			if ((ret_exe = execve(av[0], av, env)))
			{
				ft_puterr("ft_sh2 : command invalide : ");
				ft_puterr(av[0]);
				ft_puterr("\n");
				exit(-1);
			}
		}
		i++;
		free(tmp);
	}
	return (1);
}

void	outputs_file(char *file, char **av, t_env *env, t_cmd *cmd)
{
	int	file_out;

	if (cmd->sfd == 2)
		if ((file_out = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
			ft_puterr("output fail");
	if (cmd->sfd == 6)
		if ((file_out = open(file, O_RDWR | O_CREAT | O_APPEND, 0644)) == -1)
			ft_puterr("output fail");
	dup2(file_out, 1);
	ft_sh1_relance(cmd, av, env);
	close(cmd->sfd);
}

void	inputs_file(char *file, char **av, t_env *env, t_cmd *cmd)
{
	int	file_in;
	int	input;

	input = dup(0);
	if ((file_in = open(file, O_RDONLY)) == -1)
		ft_puterr("input file not open");
	dup2(file_in, 0);
	ft_sh2_relance2(av, env, ft_parse_cmd(cmd->value), 0);
	close(file_in);
	dup2(input, 0);
	close(cmd->sfd);
}

void	ft_pipe(t_cmd *cmd, char **av, t_env *env)
{
	int		fd[2];
	int		save_fd[2];

	save_fd[0] = dup(0);
	save_fd[1] = dup(1);
	pipe(fd);
	if ((env->pid = fork()) < 0)
		ft_puterr("fork fail");
	else if (env->pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ex_pipe(ft_strsplit(cmd->value, ' '), env->path, env->environ);
		dup2(save_fd[1], 1);
		wait(NULL);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		ft_sh2_relance2(av, env, ft_parse_cmd(cmd->file), 0);
		close(fd[0]);
		dup2(save_fd[0], 0);
		wait(NULL);
	}
}
