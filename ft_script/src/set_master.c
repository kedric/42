/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_master.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 14:09:39 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/30 13:31:15 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int		set_master(void)
{
	struct termios term;

	if (ioctl(0, TIOCGETA, &term))
		return (-1);
	term.c_lflag &= ~(ICANON | ECHONL | ISIG | IEXTEN | ECHO);
	term.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
					| INLCR | IGNCR | ICRNL | IXON);
	term.c_cflag &= ~(CSIZE | PARENB);
	term.c_cflag |= CS8;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	ioctl(0, TIOCSETA, &term);
	return (0);
}

void	reset_exit(t_opt *opt)
{
	if (opt->opt_q == 0)
		say_stop(opt);
	ioctl(0, TIOCSETA, &opt->orig);
	close(opt->fd_file);
	close(opt->fd_slave);
	close(opt->fd_master);
	_Exit(0);
}
