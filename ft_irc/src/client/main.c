/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 10:02:12 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/25 19:26:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	say_usage(char *name)
{
	fprintf(stderr, "usage : %s <adresse> <port>\n", name);
}

void	check_fd(t_env *env)
{
	if (FD_ISSET(env->sock, &env->fd_read))
		fct_read(env);
	if (FD_ISSET(0, &env->fd_read))
		fct_write(env);
	if (FD_ISSET(env->sock, &env->fd_read) || FD_ISSET(0, &env->fd_read))
		env->ret--;
}

void	ft_irc(t_env *env)
{
	FD_ZERO(&env->fd_read);
	FD_ZERO(&env->fd_write);
	FD_SET(env->sock, &env->fd_read);
	FD_SET(0, &env->fd_read);
	if (strlen(env->buff_write) > 0)
		FD_SET(0, &env->fd_write);
	if (env->aff_prompt == 1)
		ft_printf("%s :", env->pseudo);
	env->ret = select(env->sock + 1, &env->fd_read, &env->fd_write, NULL, NULL);
	env->aff_prompt = 1;
	check_fd(env);
}

void	create_client(t_env *env)
{
	struct protoent		*prot;
	struct sockaddr_in	sin;
	char				*nick;

	prot = (struct protoent *)XV(NULL, getprotobyname("tcp"), "getprotobyname");
	env->sock = X(-1, socket(PF_INET, SOCK_STREAM, prot->p_proto), "socket");
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(env->addr);
	sin.sin_port = htons(env->port);
	X(-1, connect(env->sock, (struct sockaddr *)&sin, sizeof(sin)), "connect");
	nick = ft_strjoin("/nick ", env->pseudo);
	send(env->sock, nick, ft_strlen(nick), 0);
	send(env->sock, "\n", 1, 0);
}



char	*get_pseudo(char **e)
{
	int i;

	if (e[0] == NULL)
	{
		ft_putstr_fd("env not found\n", 2);
		exit (-1);
	}
	i = 0;
	while (e[i] && ft_strncmp(e[i], "USER=", 5))
		i++;
	return (e[i] + 5);
}

int		main(int ac, char **av, char **e)
{
	t_env env;

	if (ac != 3)
		say_usage(av[0]);
	if (!ft_strncmp(av[1], "localhost", 9))
		av[1] = "127.0.0.1";
	ft_bzero(env.buff_write, BUFF_SIZE);
	ft_bzero(env.buff_read, BUFF_SIZE);
	env.aff_prompt = 0;
	if ((env.port = ft_atoi(av[2])) == 0)
		say_usage(av[0]);
	env.addr = av[1];
	env.pseudo = get_pseudo(e);
	create_client(&env);
	while (1)
		ft_irc(&env);
	return (0);
}
