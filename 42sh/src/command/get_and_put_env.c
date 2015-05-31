/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_put_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:21:11 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:21:16 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "exec.h"

void		ft_print_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_putendl(envp[i]);
		i++;
	}
}

char		*get_var_env(char *var, char **envp)
{
	char	*find;
	int		i;

	i = 0;
	while (envp[i])
	{
		find = NULL;
		if ((ft_strncmp(envp[i], var, ft_strlen(var))) == 0)
		{
			find = ft_strstr(envp[i], var);
			break ;
		}
		i++;
	}
	return (find);
}
