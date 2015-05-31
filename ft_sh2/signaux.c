/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:22:54 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/25 09:18:46 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

void	ft_sig_int(int x)
{
	t_env	*env;

	env = return_env();
	(void)x;
	ft_putchar(8);
	ft_putchar(8);
	ft_putstr("  ");
	ft_putchar(8);
	ft_putchar(8);
	ft_putchar('\n');
	ft_putstr("ft_sh2 ~>");
	if (env->pid > 0)
	{
		kill (SIGINT, env->pid);
	}
}

void	ft_sig_segv(int x)
{
	t_env	*env;

	env = return_env();
	if (x == SIGSEGV)
		ft_putstr("ft_sh2 : segmentation fault\n");
	exit(0);
}

void	ft_init_signal(void)
{
	signal(SIGINT, &ft_sig_int);
	signal(SIGSEGV, ft_sig_segv);
}
