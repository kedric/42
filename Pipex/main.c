/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcharign <qcharign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 07:43:20 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/31 17:45:38 by qcharign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int		sh_execute(char **av, char **path, char **env)
{
	int		i;
	int		ret_exe;

	ret_exe = -1;
	i = 0;
	while (ret_exe < 0 && *path[i] != 0)
	{
		if ((ret_exe = execve(ft_strjoin(path[i], av[0]), av, env))
			&& path[i + 1] == 0 && av[0][0] != '\0')
		{
			if ((ret_exe = execve(av[0], av, env)))
			{
				ft_puterr("pipex : command invalide : ", -1);
				ft_puterr(av[0], -1);
				ft_puterr("\n", -1);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	ft_parents(int fd[2], char **av, char **env, char **path)
{
	int	file_d;

	file_d = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ft_puterr("open file2 fail\n", file_d) == -1)
		return ;
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(file_d, 1);
	close(fd[0]);
	if (!sh_execute(ft_strsplit(av[3], ' '), path, env))
		return ;
	close(file_d);
	wait(NULL);
}

void	ft_pipex(char **av, char **env, char **path, int in)
{
	int	fd[2];
	int	pid;

	if (ft_puterr("pipe fail\n", pipe(fd) == -1))
		return ;
	if (ft_puterr("fork fail\n", (pid = fork())) == -1)
		return ;
	if (pid == 0)
		ft_parents(fd, av, env, path);
	else
	{
		dup2(in, 0);
		close(in);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		if (!sh_execute(ft_strsplit(av[2], ' '), path, env))
			return ;
		wait(NULL);
	}
}

char	**ft_path(char **env)
{
	int		i;
	int		j;
	char	*tmp;
	char	**path;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			tmp = ft_strjoin(env[i] + 5, ":./");
			path = ft_strsplit(tmp, ':');
			free(tmp);
			while (path[j] != 0)
			{
				tmp = ft_strjoin(path[j], "/");
				free(path[j]);
				path[j] = tmp;
				j++;
			}
		}
		i++;
	}
	return (path);
}

int		main(int ac, char **av, char **env)
{
	char	**path;
	int		in;

	if (ac != 5)
		ft_puterr("usage : ./pipex file1 cmd1 cmd2 file2\n", -1);
	else
	{
		path = ft_path(env);
		if (ft_puterr("open file1 fail\n", (in = open(av[1], O_RDONLY))) != -1)
			ft_pipex(av, env, path, in);
	}
	return (0);
}
