/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 12:36:17 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/18 14:35:52 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		usage(char *name)
{
	ft_puterr("usage: ");
	ft_puterr(name);
	ft_puterr(" <addr> <port>\n");
	exit(-1);
}

int			create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == 0)
	{
		ft_puterr("getprotobyname fail\n");
		return (-1);
	}
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
	{
		ft_puterr("socket fail\n");
		return (-1);
	}
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_puterr("fail to connect\n");
		exit(-1);
	}
	return (sock);
}

int			wait_ret(int sock)
{
	char				buff[4096];
	int					ret;

	ft_bzero(buff, 4096);
	if (recv(sock, buff, sizeof(buff), 0) != -1)
	{
		ft_putendl(buff);
		ft_bzero(buff, 4096);
	}
	return (1);
}

int			recall(int ret, char *buff, int sock)
{
	if (ret > 1)
	{
		buff[ret - 1] = 0;
		ft_putstr_fd((char *)buff, sock);
		if (ft_strncmp(buff, "quit", 4) == 0)
			return (0);
		if (ft_strncmp(buff, "get", 3) == 0 || !ft_strncmp(buff, "put", 3))
			file_ftp(buff, sock);
		else
			wait_ret(sock);
		ft_bzero(buff, 1024);
	}
	ft_putstr("F_TP > ");
	return (1);
}

int			main(int ac, char **av)
{
	int					port;
	int					sock;
	char				buff[1024];
	int					ret;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	ft_putstr("F_TP > ");
	while ((ret = read(0, buff, 1023)))
	{
		if (recall(ret, buff, sock))
			break ;
	}
	close(sock);
	return (0);
}
