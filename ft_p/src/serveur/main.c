/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 12:36:17 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/18 14:38:27 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		usage(char *name)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" <port>\n", 2);
	exit(-1);
}

int			create_serv(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == 0)
		ft_errorexit("getprotobyname fail\n");
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		ft_errorexit("socket fail\n");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sock, (struct sockaddr *)&sin, sizeof(sin));
	listen(sock, 42);
	return (sock);
}

void		ft_quit(int cs)
{
	close(cs);
	exit (0);
}

void		fork_child(int cs, int sock)
{
	int					ret;
	char				buff[1024];
	char				pwd[4096];

	getcwd(pwd, 4096);
	while ((ret = read(cs, buff, 1023)))
	{
		buff[ret] = '\0';
		if (ft_strncmp(buff, "ls", 2) == 0)
			func_ls(cs);
		else if (ft_strncmp(buff, "pwd", 3) == 0)
			func_pwd(cs);
		else if (ft_strncmp(buff, "cd", 2) == 0)
			func_cd(buff, cs, pwd);
		else if (ft_strncmp(buff, "quit", 4) == 0)
			ft_quit(cs);
		else if (ft_strncmp(buff, "get", 3) == 0
				|| ft_strncmp(buff, "put", 3) == 0)
			file_ftp(buff, cs);
		else
			send(cs, "ERROR unknow commande", 21, 0);
		ft_bzero((char *)buff, 1024);
	}
	close(cs);
}

int			main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	sock = create_serv(port);
	while ((cs = accept(sock, (struct sockaddr *)&csin, &cslen)))
	{
		if (fork() == 0)
			fork_child(cs, sock);
	}
	close(sock);
	return (0);
}
