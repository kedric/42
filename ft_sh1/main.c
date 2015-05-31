/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 22:23:44 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/29 11:14:17 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh1.h"

char	*sh_wait_new_commande(char *buff, t_env *env)
{
	int		ret;

	ret = 0;
	ft_putstr(env->ps1);
	if ((ret = read(1, buff, BUFF_SIZE)) > 0)
		buff[ret - 1] = '\0';
	return (buff);
}

void	env_change_dir(char **av, t_env *env)
{
	char *tmp;

	env = env;
	av[1] = ft_strjoin("OLDPWD=",env->pwd);
	ft_setenv(av, env);
	getcwd(av[1], BUFF_SIZE);
	tmp = ft_strjoin("PWD=",av[1]);
	free(av[1]);
	av[1] = tmp;
	ft_setenv(av, env);
	free(av[1]);
}

void	sh_cd(char **av, t_env *env)
{
	int		i;
	char	*tmp;

	i = 0;
	if (av[1])
	{
		if (av[1][0] == '~')
		{
			tmp = ft_strjoin(env->home, av[1] + 1);
			av[1] = tmp;
			free(tmp);
		}
		if (chdir(av[1]))
		{
			ft_puterr("cd : Dossier innaxesible\n");
			return ;
		}
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

int		sh_execute(char *name, char **av, char **path, t_env *env)
{
	int		i;
	int		ret_exe;
	pid_t	ret;

	ret_exe = -1;
	i = 0;
	if ((ret = fork()) < 0)
		ft_putstr("fork fail");
	else if (ret == 0)
	{
		while (ret_exe < 0 && *path[i] != 0)
		{
			if ((ret_exe = execve(ft_strjoin(path[i], name), av, env->environ))
				&& path[i + 1] == 0 && name[0] != '\0')
			{
				ft_puterr("ft_sh1 : command invalide : ");
				ft_puterr(name);
				ft_puterr("\n");
			}
			i++;
		}
	}
	else
		wait(NULL);
	return (1);
}

void	ft_sh1_relance(char *name, char **av, t_env *env)
{
		sh_wait_new_commande(name, env);
		if (!ft_strcmp(name, "exit"))
			exit(0);
		av = ft_strsplit(name, ' ');
		free (name);
		name = *av;
		if (!ft_strcmp(name, "cd"))
			sh_cd(av, env);
		else if (!ft_strcmp(name, "setenv"))
			ft_setenv(av, env);
		else if (!ft_strcmp(name, "unsetenv"))
			ft_unsetenv(av, env);
		else
			sh_execute(name, av, env->path, env);
		free(av);
}

int		main(int ac, char **av, char **environ)
{
	char	*name;
	t_env	*env;

	if (ac)
		env = (t_env *)malloc(sizeof(t_env));
	env->ps1 = "ft_sh1 >";
	env->environ = environ;
	copy_env(env);
	parse_environ(env);
	while (1)
	{
		name = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		ft_sh1_relance(name, av, env);
	}
}
