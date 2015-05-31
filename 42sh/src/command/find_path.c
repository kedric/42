/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:10:49 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:11:23 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "exec.h"
#include "error.h"
#include "struct.h"

char			*check_and_get_path(char *var, t_gen *envp)
{
	char		*path;

	path = NULL;
	if (var[0] == '.')
	{
		path = var + 2;
		if ((envp->ret = check_access(path)) != 0)
			return (NULL);
	}
	else if (var[0] == '/' ||
			!(ft_strcmp("/", get_var_env("PWD=", envp->env))))
	{
		path = var;
		if ((envp->ret = check_access(path)) != 0)
			return (NULL);
	}
	else
		path = find_path_exec(var, envp);
	return (path);
}

char			*concat_path(char *split, char *exec)
{
	size_t		len;
	char		*path;

	len = (ft_strlen(split) + ft_strlen(exec) + 2);
	if ((path = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	path = ft_strcpy(path, split);
	path = ft_strcat(path, "/");
	path = ft_strcat(path, exec);
	return (path);
}

char			*find_path_exec(char *exec, t_gen *envp)
{
	char		*path;
	char		**split;
	int			i;

	i = -1;
	if ((path = get_var_env("PATH=", envp->env)) == NULL)
		return (NULL);
	split = ft_strsplit(path, ':');
	while (split[++i])
	{
		path = concat_path(split[i], exec);
		if ((access(path, F_OK) != -1) &&
				((envp->ret = check_access(path)) == 0))
			break ;
		else
		{
			envp->ret = check_access(path);
			ft_strdel(&path);
			if (envp->ret == ENPERM)
				break ;
		}
	}
	free_split(&split);
	return (path);
}
