/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:23:56 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:24:01 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_sig_int(int x)
{
	t_gen	*gen;

	gen = recup_gen();
	if (gen->pid_fork > 0)
	{
		go_end(gen, NULL);
		ft_putchar('\n');
		ft_putstr(gen->ps1->aff);
		while (gen->hist->next)
			gen->hist = gen->hist->next;
		ft_bzero(gen->hist->buff, BUFF_SIZE);
		gen->hist->pose_buff = 0;
		gen->hist->len = 0;
		gen->hist->modif = 0;
		ft_bzero(gen->hist->value, BUFF_SIZE);
	}
	else
		kill(gen->pid_fork, x);
}

void	ft_sig_tstp(int x)
{
	t_gen	*gen;

	gen = recup_gen();
	if (gen->pid_fork > 0)
	{
		ft_putstr_fd(bell, gen->term->fd);
	}
	else
	{
		kill(gen->pid_fork, x);
	}
}

void	go_kill(t_gen *gen, char *buff)
{
	(void)buff;
	go_end(gen, NULL);
	destroy_gen();
	exit(0);
}
