/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:48:02 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/24 19:11:57 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

t_cmd	*sh_wait_new_commande(char *buff, t_env *env, t_cmd *cmd)
{
	int		ret;

	ret = 0;
	ft_putstr(env->ps1);
	ret = read(1, buff, BUFF_SIZE);
		buff[ret] = '\0';
	cmd = ft_parse_cmd(buff);
	return (cmd);
}

void	env_change_dir(char **av, t_env *env)
{
	char	*tmp;

	av[1] = ft_strjoin("OLDPWD=", env->pwd);
	ft_setenv(av, env);
	getcwd(av[1], BUFF_SIZE);
	tmp = ft_strjoin("PWD=", av[1]);
	free(av[1]);
	av[1] = tmp;
	ft_setenv(av, env);
	free(av[1]);
}

void	sh_cd(char **av, t_env *env)
{
	char	*tmp;

	if (av[1])
	{
		if (av[1][0] == '~')
		{
			tmp = ft_strjoin(env->home, av[1] + 1);
			av[1] = tmp;
			free(tmp);
		}
		else if (av[1][0] == '-')
			av[1] = ft_getenv(env, "OLDPWD") + 7;
		if (chdir(av[1]))
			ft_puterr("cd : Dossier innaxesible\n");
		else
			env_change_dir(av, env);
	}
	else
	{
		av[1] = env->home;
		env_change_dir(av, env);
	}
}

int		sh_exec(char *name, char **av, t_env *env)
{
	int		ret_exe;
	int		i;
	char	*tmp;
	char	**path;

	ret_exe = -1;
	i = 0;
	path = env->path;
	while (ret_exe < 0 && *path[i] != 0)
	{
		tmp = ft_strjoin(path[i], name);
		if ((ret_exe = execve(tmp, av, env->environ))
				&& path[++i] == 0 && name[0] != '\0'
				&& (ret_exe == execve(av[0], av, env->environ)))
		{
			ft_puterr("ft_sh2 : command invalide : ");
			ft_puterr(name);
			ft_puterr("\n");
			free(tmp);
			exit (-1);
		}
	free(tmp);
	}
	return (0);
}

int		sh_execute(char *name, char **av, t_env *env)
{
	if ((env->pid = fork()) < 0)
		ft_puterr("fork fail");
	else if (env->pid == 0)
	{
		sh_exec(name, av , env);
	}
	else
	{
		wait(NULL);
	}
	return (1);
}
