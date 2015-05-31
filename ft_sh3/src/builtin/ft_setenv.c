/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:38:27 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/02 12:05:36 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	copy_env(t_env *env)
{
	char	**tmp;
	int		i;

	i = 0;
	while (env->environ[i])
		i++;
	i++;
	tmp = (char **)malloc(sizeof(char *) * i);
	if (tmp)
	{
		while (i >= 0)
		{
			tmp[i] = ft_strdup(env->environ[i]);
			i--;
		}
	env->environ = tmp;
	}
}

void	parse_environ(t_env *env)
{
	int		i[2];
	char	*tmp;

	i[0] = 0 * (i[1] = 0);
	while (env->environ[i[0]])
	{
		if (!ft_strncmp(env->environ[i[0]], "PATH=", 5))
		{
			tmp = ft_strjoin(env->environ[i[0]] + 5, ":./");
			env->path = ft_strsplit(tmp, ':');
			free(tmp);
			while (env->path[i[1]] != 0)
			{
				tmp = ft_strjoin(env->path[i[1]], "/");
				free(env->path[i[1]]);
				env->path[i[1]] = tmp;
				i[1]++;
			}
		}
		else if (!ft_strncmp(env->environ[i[0]], "HOME=", 5))
			env->home = ft_strdup(env->environ[i[0]] + 5);
		i[0]++;
	}
	getcwd(env->pwd, BUFF_SIZE);
}

void	ft_unsetenv(char **av, t_env *env)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env->environ[j])
		j++;
	tmp = (char **)malloc(sizeof(char *) * j);
	j = 0;
	i = 0;
	while (env->environ[j])
	{
		if (ft_strncmp(env->environ[j], av[1], ft_strlen(av[1])))
		{
			tmp[i] = env->environ[j];
			i++;
		}
		j++;
	}
	tmp[i + 1] = NULL;
	free(env->environ);
	env->environ = tmp;
	parse_environ(env);
}

void	create_env(t_env *env, int j, char *add)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (j + 2));
	if (tmp)
	{
		j = 0;
		while (env->environ[j])
		{
			tmp[j] = env->environ[j];
			j++;
		}
		tmp[j] = add;
		tmp[j + 1] = NULL;
		free(env->environ);
		env->environ = tmp;
	}
}

void	ft_setenv(char **av, t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (av[1][i] != '=' && av[1][i] != '\0')
		i++;
	if (av[1][i] == '\0')
	{
		ft_puterr("setenv : usage VAR=VALEUR\n");
		return ;
	}
	while (env->environ[j] && ft_strncmp(env->environ[j], av[1], i))
		j++;
	if (env->environ[j])
	{
		free(env->environ[j]);
		env->environ[j] = ft_strdelc(av[1], '"');
	}
	else
		create_env(env, j, ft_strdelc(av[1], '"'));
	parse_environ(env);
}
