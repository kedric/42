/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 10:25:01 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/25 17:43:42 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		new_client(t_env *env, int s)
{
	int					cs;
	struct sockaddr_in	csock_in;
	socklen_t			csock_len;

	csock_len = sizeof(csock_in);
	cs = X(-1, accept(s, (struct sockaddr *)&csock_in, &csock_len), "accept");
	env->fds[cs].type = FD_CLIENT;
	env->fds[cs].fct_read = client_read;
	env->fds[cs].fct_write = client_write;
	env->fds[cs].nick = ft_joinfree("guest", ft_itoa(cs - 3), 2);
	env->fds[cs].nick = ft_joinfree(env->fds[cs].nick, " : ", 1);
	printf("New client %sfrom %s:%d\n", env->fds[cs].nick
		, inet_ntoa(csock_in.sin_addr), ntohs(csock_in.sin_port));
}

void		init_serv(t_env *env)
{
	int					sock;
	struct sockaddr_in	sock_in;
	struct protoent		*prot;

	prot = (struct protoent *)XV(NULL, getprotobyname("tcp"), "getprotobyname");
	sock = X(-1, socket(PF_INET, SOCK_STREAM, prot->p_proto), "socket");
	sock_in.sin_family = AF_INET;
	sock_in.sin_addr.s_addr = INADDR_ANY;
	sock_in.sin_port = htons(env->port);
	X(-1, bind(sock, (struct sockaddr *)&sock_in, sizeof(sock_in)), "bind");
	X(-1, listen(sock, 42), "listen");
	env->fds[sock].type = FD_SERV;
	env->fds[sock].fct_read = new_client;
}

void		init_env(t_env *env)
{
	int				i;
	struct rlimit	rlp;

	if (getrlimit(RLIMIT_NOFILE, &rlp))
		fprintf(stderr, "%s, fail to get limit\n", env->prg_name);
	env->max_fd = rlp.rlim_cur;
	if ((env->fds = (t_fd *)malloc(sizeof(t_fd) * env->max_fd)) == NULL)
		fprintf(stderr, "%s, fail to malloc env->fds\n", env->prg_name);
	i = 0;
	while (i < env->max_fd)
	{
		env->fds[i].type = 0;
		env->fds[i].fct_read = NULL;
		env->fds[i].fct_write = NULL;
		env->fds[i].save = NULL;
		env->fds[i].nick = NULL;
		env->fds[i].channel = -1;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		env->chan[i].id = i;
		env->chan[i++].name = NULL;
	}
}
