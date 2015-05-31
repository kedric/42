/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 10:02:23 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/25 18:52:28 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

t_env	*ft_sigleton(void)
{
	static t_env save;

	return (&save);
}

void	ft_sig_int(int i)
{
	t_env	*env;
	int		serv;

	env = ft_sigleton();
	i = 0;
	while (i <= env->max_fd)
	{
		if (env->fds[i].type && env->fds[i].type == FD_CLIENT)
			close(i);
		else if (env->fds[i].type && env->fds[i].type == FD_SERV)
			serv = i;
		i++;
	}
	close(serv);
	exit (0);
}

void	usage(char *s)
{
	printf("%s, Usage %s <port>\n", s, s);
	exit (-1);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		usage(av[0]);
	env = ft_sigleton();
	env->prg_name = av[0];
	if ((env->port = ft_atoi(av[1])) == 0)
		usage(av[0]);
	init_env(env);
	init_serv(env);
	signal(SIGINT, ft_sig_int);
	while (1)
	{
		init_fd(env);
		do_select(env);
		check_fd(env);
	}
	return (0);
}
