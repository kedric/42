/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:22:54 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/01 17:45:38 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"


void	ft_sig_int(int x)
{
	x = x;
	ft_putstr(bell);
}

void	ft_sig_tstp(int x)
{
	t_env	*env;

	env = return_env();
	(void)x;
	if (env->pid > 0)
	{
		start();
	}
}

void	ft_sig_segv(int x)
{
	t_env	*env;

	env = return_env();
	if (x == SIGSEGV)
		ft_putstr("ft_sh : segmentation fault\n");
	if (env->pid > 0)
		exit (0);
	start();
}

void	ft_init_signal(void)
{
	signal(SIGINT, &ft_sig_int);
	signal(SIGTSTP, ft_sig_tstp);
	signal(SIGSEGV, ft_sig_segv);
}
