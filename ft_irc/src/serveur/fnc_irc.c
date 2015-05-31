/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_irc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 15:50:28 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/25 17:42:08 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	change_nickname(t_env *env, int cs)
{
	char *tmp;

	env->fds[cs].save[ft_strlen(env->fds[cs].save) - 1] = '\0';
	printf("client %s change nick to %s\n",
			env->fds[cs].nick, env->fds[cs].save + 6);
	free(env->fds[cs].nick);
	tmp = ft_strjoin(env->fds[cs].save, " : ");
	env->fds[cs].nick = ft_strdup(tmp + 6);
	free(tmp);
	ft_strcat(env->fds[cs].buff_write, "your nick name is now : ");
	ft_strcat(env->fds[cs].buff_write, env->fds[cs].save + 6);
	ft_strcat(env->fds[cs].buff_write, "\n");
}

void	change_chan(t_env *env, int cs)
{
	char	*tmp;
	int		i;

	i = 0;
	env->fds[cs].save[ft_strlen(env->fds[cs].save) - 1] = 0;
	tmp = ft_strtrim(env->fds[cs].save + 6);
	if (tmp[0] == '#')
	{
		while (i < 100 && env->chan[i].name != NULL
			&& ft_strcmp(env->chan[i].name, tmp) != 0)
			i++;
		if (env->chan[i].name == NULL)
		{
			env->chan[i].name = ft_strdup(tmp);
			env->chan[i].id = i;
		}
		env->fds[cs].channel = i;
		ft_strcat(env->fds[cs].buff_write, "you have changed channel to ");
		ft_strcat(env->fds[cs].buff_write, tmp);
		ft_strcat(env->fds[cs].buff_write, "\n");
		printf("client %schange channel to %s\n",
			env->fds[cs].nick, env->chan[i].name);
	}
	else
		send(cs, "channel name not valide start by #\n", 35, 0);
}

void	leave_chan(t_env *env, int cs)
{
	if (env->fds[cs].channel == -1)
		ft_strcat(env->fds[cs].buff_write, "you are not in channel\n");
	else
	{
		env->fds[cs].channel = -1;
		ft_strcat(env->fds[cs].buff_write, "you are leave channel\n");
	}
}

void	send_priv(t_env *env, int cs)
{
	char	**splt;
	int		i;

	i = 0;
	splt = ft_strsplit(env->fds[cs].save, ' ');
	while (i < env->max_fd && ft_strncmp(env->fds[i].nick, splt[1],
			ft_strlen(splt[1])) != 0)
		i++;
	if (i < env->max_fd)
	{
		ft_strcat(env->fds[i].buff_write, env->fds[cs].nick);
		ft_strcat(env->fds[i].buff_write,
				env->fds[cs].save + 7 + ft_strlen(splt[1]));
	}
	else
		ft_strcat(env->fds[cs].buff_write, "client not found\n");
}
