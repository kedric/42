/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 19:18:20 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/18 14:41:22 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <fcntl.h>

void		send_file(char *name, int cs)
{
	int				fd_open;
	unsigned char	buff[4096];
	int				ret;
	t_pkg			pkg;

	pkg.brk = 0;
	ft_bzero(pkg.buff, 4096);
	ft_strcpy(pkg.name, name);
	fd_open = open(name, O_RDONLY);
	while ((ret = read(fd_open, buff, 4095)) > 0)
	{
		pkg.len = ret;
		buff[ret] = '\0';
		ft_memcpy(pkg.buff, buff, ret);
		send(cs, (char *)&pkg, sizeof(t_pkg), 0);
		ft_bzero(pkg.buff, 4096);
	}
	if (ret == -1)
		pkg.len = -1;
	pkg.brk = 1;
	send(cs, (char *)&pkg, sizeof(t_pkg), 0);
	if (ret != -1)
		close(fd_open);
}

int			fd_init(int *fd, t_pkg *pkg, int cs)
{
	if (*fd == 0 && (*fd = open(pkg->name, O_RDWR | O_CREAT, 00644)) < 0)
	{
		pkg->len = -1;
		while (pkg->len > 0)
			recv(cs, (char *)pkg, sizeof(t_pkg), 0);
		return (-1);
	}
	return (0);
}

void		receive_file(int cs)
{
	int				fd_open;
	int				ret;
	unsigned char	buff[sizeof(t_pkg)];
	t_pkg			*pkg;

	fd_open = 0;
	while (1)
	{
		if ((ret = recv(cs, buff, sizeof(t_pkg), 0)) > 0)
			pkg = (t_pkg *)buff;
		if ((char)(pkg->brk) == 1 || pkg->len == -1)
			break ;
		if (fd_init(&fd_open, pkg, cs))
			break ;
		write(fd_open, (unsigned char *)pkg->buff, pkg->len);
		ft_bzero(buff, 4096);
	}
	if (pkg->len == -1 || ret == -1)
		return ;
	else
		close(fd_open);
}

int			file_ftp(char *buff, int cs)
{
	if (ft_strncmp(buff, "get", 3) == 0)
		send_file(buff + 4, cs);
	if (ft_strncmp(buff, "put", 3) == 0)
		receive_file(cs);
	return (0);
}
