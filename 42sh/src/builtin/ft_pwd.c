/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 20:00:37 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 17:10:12 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "struct.h"
#include "error.h"
#include "parser.h"

char	*ft_glue(char **tmp)
{
	char	*s;
	int		len;
	int		i;

	if (!tmp)
		return (NULL);
	len = 1;
	i = -1;
	while (tmp[++i])
		len = len + ft_strlen(tmp[i]) + 1;
	if (!(s = (char *)malloc(len * sizeof(char))))
		return (s);
	i = 1;
	s = ft_strcpy(s, "/");
	s = ft_strcat(s, tmp[0]);
	while (tmp[i])
	{
		s = ft_strcat(s, "/");
		s = ft_strcat(s, tmp[i]);
		i++;
	}
	return (s);
}

char	*ft_news(char **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	return (ft_strdup("/"));
}

void	ft_destroy(char **tmp)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}
}

char	*ft_trim(char *s)
{
	char		**tmp;
	int			i;

	tmp = ft_strsplit(s, '/');
	if ((i = 0) == 0 && tmp[1] && ft_strcmp(tmp[1], "..") == 0 && !tmp[2])
		return (ft_news(tmp));
	while (tmp[i] && ft_strcmp(tmp[i], "..") != 0)
		i++;
	if (i != 0 && tmp[i])
	{
		while (tmp[i + 1])
		{
			free(tmp[i - 1]);
			tmp[i - 1] = ft_strdup(tmp[i + 1]);
			i++;
		}
		free(tmp[i - 1]);
		tmp[i - 1] = '\0';
		free(tmp[i]);
		free (s);
		s = ft_glue(tmp);
		s = ft_trim(s);
	}
	ft_destroy(tmp);
	return (s);
}

void	ft_pwd(t_gen *env, t_process *p)
{
	int	i;

	i = ft_found("PWD", env);
	if (ft_strncmp(env->env[i], "PWD=", 4) == 0)
		ft_dprintf(p->FD_OUT, "%s\n", (env->env[i] + 4));
	else
		env->ret = EBDENV;
}
