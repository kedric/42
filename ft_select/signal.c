/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:27:59 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/11 18:51:50 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"
#include <unistd.h>
#include <stdio.h>

void	ft_sig_pause(int x)
{
	t_sig	*sig;

	(void) x;
	sig = ft_init_sig();
	ft_close(sig);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, &sig->term.c_cc[VSUSP]);
}

void	ft_sig_cont(int x)
{
	t_sig	*sig;

	(void) x;
	sig = ft_init_sig();
	signal(SIGTSTP, &ft_sig_pause);
	tcsetattr(0, TCSANOW, &sig->term);
	tputs(tgetstr("ti", NULL), 1, ft_putc);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
	aff_lst(sig->lst, sig);
}

void	ft_sig_int(int x)
{
	t_sig	*sig;

	(void) x;
	sig = ft_init_sig();
	ft_close(sig);
	tcsetattr(0, 0, &sig->termo);
	exit(130);
}

void	ft_sig_size(int x)
{
	char	buffer[2048];
	t_sig	*sig;

	(void) x;
	sig = ft_init_sig();
	tgetent(buffer, getenv("TERM"));
	aff_lst(sig->lst, sig);
}

void	ft_init_signal(void)
{
	signal(SIGTSTP, ft_sig_pause);
	signal(SIGCONT, ft_sig_cont);
	signal(SIGINT, ft_sig_int);
	signal(SIGWINCH, ft_sig_size);
}
