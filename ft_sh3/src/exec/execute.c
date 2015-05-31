/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:48:02 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 11:08:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_cmd	*sh_wait_new_commande(t_env *env, t_cmd *cmd)
{
	int		ret;
	t_term	*term;
	char	buff[6];

	ret = 0;
	init_term();
	term = recup_term();
		parse_ps1(env);
	term->ps1_len = env->ps1_len;
	term->hist = add_or_clean(term->hist);
	ft_bzero(buff, 5);
	while (ft_stomp(buff, term))
	{
		ft_bzero(buff, 5);
		ret = read(term->fd, buff, 5);
		buff[ret + 1] = '\0';
	}
	cmd = ft_parse_cmd(term->hist->buff);
	close_term();
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
			av[1] = getenv("OLDPWD=");
		if (chdir(av[1]))
			ft_puterr("cd : Dossier innaxesible\n");
		else
			env_change_dir(av, env);
	}
	else
	{
		av[1] = env->home;
		if (chdir(av[1]))
			ft_puterr("cd : Dossier innaxesible\n");
		else
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
