/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 19:01:00 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 13:38:46 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void	execute(t_opt *opt)
{
	if (opt->cmd[0] == NULL)
	{
		opt->cmd[0] = opt->shell;
		opt->cmd[1] = NULL;
	}
	if (execve(opt->cmd[0], opt->cmd, opt->env) == -1)
		_exit(-1);
}

int		child_fork(t_opt *opt)
{
	char	*shell;

	shell = opt->shell;
	if (setsid() == -1)
		ft_errorexit("fail setsid");
	if ((opt->fd_slave = open((char *)(&opt->fds_name), O_RDWR)) < 0)
		ft_errorexit("fail to open slave fd");
	if (ioctl(opt->fd_slave, TIOCSCTTY, 0))
		ft_errorexit("liaison fail");
	if ((ioctl(opt->fd_slave, TIOCSETA, &opt->orig)))
		ft_errorexit("imposible de set les atibues du term");
	if (ioctl(opt->fd_slave, TIOCSWINSZ, &opt->winsize) == -1)
		ft_errorexit("imposible de set les atibues winsize du term");
	if (dup2(opt->fd_slave, 0) != 0)
		ft_errorexit("impossible de dupliquer le l'entrer standard");
	if (dup2(opt->fd_slave, 1) != 1)
		ft_errorexit("impossible de dupliquer la sortie stendard");
	if (dup2(opt->fd_slave, 2) != 2)
		ft_errorexit("impossible de dupliquer la sortie d erreur");
	execute(opt);
	exit(0);
	return (0);
}

int		open_ptym(t_opt *opt)
{
	if ((opt->fd_master = open("/dev/ptmx", O_RDWR)) < 0)
		return (-1);
	if (ioctl(opt->fd_master, TIOCPTYGRANT))
		return (-1);
	if (ioctl(opt->fd_master, TIOCPTYUNLK))
		return (-1);
	if (ioctl(opt->fd_master, TIOCPTYGNAME, opt->fds_name))
		return (-1);
	return (0);
}

int		fork_pty(t_opt *opt)
{
	int	pid;

	if ((pid = fork()) < 0)
	{
		close(opt->fd_master);
		ft_errorexit("fork have fail");
	}
	if (pid > 0)
	{
		return ((opt->pid_c = pid));
	}
	else
		child_fork(opt);
	return (0);
}
