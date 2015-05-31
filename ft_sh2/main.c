/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 22:23:44 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/25 18:24:31 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

char	*ft_getenv(t_env *env, char *search)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(search);
	while (env->environ[i])
	{
		if (!ft_strncmp(env->environ[i], search, len))
			return (env->environ[i]);
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

t_env	*return_env(void)
{
	static t_env	*env = NULL;

	if (env == NULL)
	{
		env = (t_env *)malloc(sizeof(t_env));
	}
	return (env);
}

int		main(int ac, char **av, char **environ)
{
	t_env	*env;

	env = return_env();
	if ((ac && av == NULL) || env == NULL)
		return (0);
	if (environ[0] == NULL)
	{
		ft_puterr("env not found\n");
		return (0);
	}
	env->ps1 = "ft_sh2 ~>";
	env->environ = environ;
	env->pid = 0;
	copy_env(env);
	parse_environ(env);
	start();
}
