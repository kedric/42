/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 12:58:59 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/25 19:23:28 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	fct_read(t_env *env)
{
	if (recv(env->sock, env->buff_read, BUFF_SIZE, 0) <= 0)
	{
		close(env->sock);
		exit(0);
	}
	ft_printf("\n%s", env->buff_read);
	ft_bzero(env->buff_read, BUFF_SIZE);
}

void	checkcmd(t_env *env, char *tmp, int ret)
{
	env->aff_prompt = 0;
	tmp[ret - 1] = '\0';
	if (ft_strncmp(tmp, "/nick ", 6) == 0)
		env->pseudo = ft_strdup(tmp + 6);
	else if (!ft_strncmp(tmp, "/exit", 5) || !ft_strncmp(tmp, "/quit",5))
	{
		close(env->sock);
		exit(0);
	}
	else if (ft_strncmp(tmp, "/join ", 6) == 0
		|| ft_strncmp(tmp, "/leave", 6) == 0
		|| ft_strncmp(tmp, "/send ", 6) == 0)
		env->aff_prompt = 0;
	else
		env->aff_prompt = 1;
	tmp[ret - 1] = '\n';
}

void	fct_write(t_env *env)
{
	int		ret;
	char	*tmp;

	ret = read(0, env->buff_write, BUFF_SIZE - 1);
	env->buff_write[ret] = 0;
	tmp = ft_strtrim(env->buff_write);
	if (tmp[0] == '/')
		checkcmd(env, tmp, ret);
	send(env->sock, env->buff_write, ret, 0);
	ft_bzero(env->buff_write, ret);
	free(tmp);
}
