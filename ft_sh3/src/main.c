/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 22:23:44 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 01:12:14 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_getenv(char **env, char *search)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(search);
	while (env[i])
	{
		if (*(env[i] + len) && !ft_strncmp(env[i], search, len))
			return (env[i]);
		i++;
	}
	return (NULL);
}

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp->file);
		free(tmp);
	}
}

void parse_ps1(t_env *env)
{
	char	*name;
	char	**ret;
	int		i;

	i = 0;
	if (env->ps1 == NULL)
	{
		if ((name = ft_getenv(env->environ, "USER")) == NULL)
			name = ft_strdup("(-_-)");
		ret = ft_strsplit(env->pwd, '/');
		while (ret[i])
			i++;
		env->ps1_len = ft_strlen(name + 5) + ft_strlen(ret[--i]) + 8;
		env->ps1 = (char *)malloc(sizeof(char) * env->ps1_len + 1);
		env->ps1 = ft_strcat(env->ps1, "\033[0m[\033[31m");
		env->ps1 = ft_strcat(env->ps1, name + 5);
		env->ps1 = ft_strcat(env->ps1, "\033[0m]-[\033[32m/");
		env->ps1 = ft_strcat(env->ps1, ret[i]);
		env->ps1 = ft_strcat(env->ps1, "\033[0m]>");
		env->ps1_len = ft_strlen(env->ps1);
		while (i > -1)
			free(ret[i--]);
		free(ret);
	}
	ft_putstr(env->ps1);
}

t_env	*return_env(void)
{
	static t_env	*env = NULL;

	if (env == NULL)
		env = (t_env *)malloc(sizeof(t_env));
	return (env);
}

int		main(int ac, char **av, char **environ)
{
	t_env	*env;

	if (ac && av)
		env = return_env();
	env->environ = environ;
	env->pid = 0;
	copy_env(env);
	parse_environ(env);
	start();
	return (0);
}
