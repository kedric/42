/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:00:35 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 17:09:15 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "struct.h"
#include "error.h"

static char		*ft_red(char *p, char *b)
{
	char		*s;

	if (!(s = (char *)malloc((ft_strlen(b) + ft_strlen(p) + 3) * sizeof(char))))
		return (s);
	s = ft_strcpy(s, "/");
	if (b && ft_strcmp(b, "\0") != 0)
	{
		s = ft_strcat(s, b);
		if (p && ft_strcmp(p, "\0") != 0)
			s = ft_strcat(s, "/");
	}
	s = ft_strcat(s, p);
	s = ft_trim(s);
	return (s);
}

static char		*ft_dellast(char *s)
{
	int		i;
	int		save;
	char	*ret;

	i = -1;
	save = -1;
	while (s[++i])
		if (s[i] == '/')
			save = i;
	ret = ft_strdup(s);
	ret[save] = '\0';
	return (ret);
}

static void		ft_checkaccess(char *s, t_gen *env, int ip)
{
	if (access(s, F_OK) == -1)
	{
		env->ret = ENENTR;
		ft_printf("cd: %s: no such a file or directory\n", s);
	}
	else if (access(s, X_OK) == -1)
	{
		env->ret = ENPERM;
		ft_printf("cd: %s: permission denied\n", s);
	}
	else
	{
		env = ft_setenv("OLDPWD", env->env[ip] + 4, 1, env);
		env = ft_setenv("PWD", s, 1, env);
		chdir(s);
	}
}

static t_gen	*ft_docd(char *path, t_gen *env, int ih, int ip)
{
	char		*s;
	char		*tmp;

	tmp = ft_dellast(env->env[ih] + 5);
	if (path[0] == '~' && path[1] == '/')
		s = ft_red(path + 2, env->env[ih] + 5);
	else if (path[0] == '~')
		s = ft_red(path + 1, tmp);
	else if (path[0] == '/')
		s = ft_red(path + 1, NULL);
	else if (ft_strcmp(path, "-") == 0)
		s = ft_strdup(&(env->env[ft_found("OLDPWD", env)][7]));
	else
		s = ft_red(path, env->env[ip] + 5);
	ft_checkaccess(s, env, ip);
	free(s);
	free(tmp);
	return (env);
}

t_gen			*ft_cd(char *path, t_gen *env)
{
	int	ih;
	int	ip;

	ih = ft_found("HOME", env);
	ip = ft_found("PWD", env);
	if (!path || ft_strcmp(path, "~") == 0)
	{
		if (ft_strncmp(env->env[ih], "HOME", 4) == 0)
		{
			env = ft_setenv("OLDPWD", env->env[ip] + 4, 1, env);
			chdir((env->env[ih] + 5));
			env = ft_setenv("PWD", (env->env[ih] + 5), 1, env);
		}
		return (env);
	}
	if (ft_strncmp(path, "..", 2) != 0 || ft_strcmp(env->env[ip], "PWD=/") != 0)
		env = ft_docd(path, env, ih, ip);
	return (env);
}
