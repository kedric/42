/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 20:53:28 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 18:08:37 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "error.h"
#include "parser.h"
#include <sys/wait.h>
#include <sys/types.h>

static int	ft_s(char *s, char c)
{
	int		i;

	i = -1;
	if (s && s[0] == '.' && s[1] == '/')
		return (-1);
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

char		**ft_environ(char **environ)
{
	char	**env;
	int		len;
	int		i;

	len = ft_strstrlen(environ);
	env = (char **)malloc((len + 1) * sizeof(char *));
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[len] = '\0';
	return (env);
}

t_gen		*ft_tmpenv(char **com, t_gen *env, int use_env, int i)
{
	t_gen	*tmpenv;
	int		j;
	int		eg;
	char	*s;

	if (!(tmpenv = (t_gen *)malloc(sizeof(t_gen))))
	{
		env->ret = EALLOC;
		return (NULL);
	}
	tmpenv->env = NULL;
	j = 0;
	if (use_env == 0)
		tmpenv->env = ft_environ(env->env);
	else
		j++;
	while (++j < i)
	{
		eg = ft_s(com[j], '=');
		s = ft_strsub(com[j], 0, eg);
		tmpenv = ft_setenv(s, &(com[j][eg + 1]), 1, tmpenv);
		if (s)
			free(s);
	}
	return (tmpenv);
}

void		ft_launch(char **com, t_gen *env, int i, int use_env)
{
	pid_t	father;
	t_gen	*tmpenv;

	if (access(com[i], F_OK) != -1 && com[i][0] == '.' && com[i][1] == '/')
		if (access(com[i], X_OK) != -1)
		{
			tmpenv = ft_tmpenv(com, env, use_env, i);
			father = fork();
			if (father > 0)
			{
				wait(0);
				ft_freetmpenv(tmpenv);
			}
			else if (father == 0)
				execve(com[i], &(com[i]), tmpenv->env);
		}
		else
			env->ret = ENPERM;
	else
		env->ret = ENENTR;
	if (env->ret != 0)
		ft_dprintf(2, "env: %s: %s\n", com[i], strror(env->ret));
}

void		ft_env(t_process *p, t_gen *env)
{
	int	i;
	int	use_env;

	use_env = 0;
	i = 1;
	if (p->av[i] && ft_strcmp(p->av[i], "-i") == 0)
		use_env = i++;
	while (p->av[i] && ft_s(p->av[i], '=') != -1)
		i++;
	if (p->av[i] == NULL)
	{
		if (use_env == 0)
		{
			i = -1;
			while (env && env->env && env->env[++i] != NULL)
				ft_dprintf(p->FD_OUT, "%s\n", env->env[i]);
			i = 1;
		}
		else
			i = 2;
		while (p->av[i])
			ft_dprintf(p->FD_OUT, "%s\n", p->av[i++]);
	}
	else
		ft_launch(p->av, env, i, use_env);
}
