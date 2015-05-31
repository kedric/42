/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:45:18 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/25 17:41:48 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	save_char(t_env *env, int cs, int ret)
{
	char	c[2];
	int		i;

	i = 0;
	ft_bzero(c, 2);
	while (i <= ret)
	{
		if (ft_isascii(env->fds[cs].buff_read[i]))
		{
			c[0] = env->fds[cs].buff_read[i];
			env->fds[cs].save = ft_joinfree(env->fds[cs].save, (char *)c, 1);
		}
		i++;
	}
}

int		is_cmd(t_env *env, int cs)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strtrim(env->fds[cs].save);
	if (tmp[0] == '/')
	{
		if (ft_strncmp(env->fds[cs].save, "/nick ", 6) == 0)
			change_nickname(env, cs);
		if (ft_strncmp(env->fds[cs].save, "/join ", 6) == 0)
			change_chan(env, cs);
		if (ft_strncmp(env->fds[cs].save, "/leave", 6) == 0)
			leave_chan(env, cs);
		if (ft_strncmp(env->fds[cs].save, "/send ", 6) == 0)
			send_priv(env, cs);
		return (0);
	}
	return (1);
}

int		print_pkg(t_env *env, int cs, int ret)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	if (env->fds[cs].buff_read[ret - 1] == '\n')
	{
		i = 0;
		save_char(env, cs, ret);
		if (is_cmd(env, cs) && env->fds[cs].channel != -1)
		{
			tmp = ft_strdup(env->fds[cs].nick);
			env->fds[cs].save = ft_joinfree(tmp, env->fds[cs].save, 3);
			while (i <= env->max_fd)
			{
				if ((env->fds[i].type == FD_CLIENT) && (i != cs)
					&& (env->fds[cs].channel == env->fds[i].channel))
					ft_strcat(env->fds[i].buff_write, env->fds[cs].save);
				i++;
			}
		}
		return (1);
	}
	else
		save_char(env, cs, ret);
	return (0);
}

void	client_read(t_env *env, int cs)
{
	int	ret;

	ret = recv(cs, env->fds[cs].buff_read, BUFF_SIZE, 0);
	env->fds[cs].buff_read[ret] = 0;
	if (ret <= 0)
	{
		close(cs);
		env->fds[cs].type = 0;
		env->fds[cs].fct_read = NULL;
		env->fds[cs].fct_write = NULL;
		env->fds[cs].save = NULL;
		free(env->fds[cs].nick);
		env->fds[cs].nick = NULL;
		env->fds[cs].channel = -1;
		printf("client #%d disconected\n", cs);
	}
	else
	{
		if (print_pkg(env, cs, ret))
		{
			free(env->fds[cs].save);
			env->fds[cs].save = NULL;
		}
	}
}

void	client_write(t_env *env, int cs)
{
	send(cs, env->fds[cs].buff_write, ft_strlen(env->fds[cs].buff_write), 0);
	ft_bzero(env->fds[cs].buff_write, BUFF_SIZE);
}
