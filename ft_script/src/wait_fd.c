/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 15:14:51 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/02 17:40:47 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include <sys/time.h>

void	say_started(t_opt *opt)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	ft_putstr_fd("Script started, output file is ", 1);
	ft_putstr_fd(opt->file_name, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Script started on ", opt->fd_file);
	ft_putstr_fd(ctime(&tv.tv_sec), opt->fd_file);
}

void	say_stop(t_opt *opt)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	ft_putstr_fd("\nScript done, output file is ", 1);
	ft_putendl_fd(opt->file_name, 1);
	ft_putstr_fd("Script done on ", opt->fd_file);
	ft_putstr_fd(ctime(&tv.tv_sec), opt->fd_file);
}

void	wait_fd(t_opt *opt)
{
	char	buff[4096];
	int		nb_read;
	fd_set	fd;

	FD_SET(0, &fd);
	FD_SET(opt->fd_master, &fd);
	if (select(opt->fd_master + 1, &fd, NULL, NULL, NULL) == -1)
		ft_errorexit("select");
	if (FD_ISSET(0, &fd))
	{
		if ((nb_read = read(0, buff, 4095)) <= 0)
			reset_exit(opt);
		write(opt->fd_master, buff, nb_read);
	}
	if (FD_ISSET(opt->fd_master, &fd))
	{
		if ((nb_read = read(opt->fd_master, buff, 4095)) <= 0)
			reset_exit(opt);
		write(1, buff, nb_read);
		write(opt->fd_file, buff, nb_read);
	}
}
