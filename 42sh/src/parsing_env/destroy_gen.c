/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:22:13 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:22:17 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	destroy_gen_hist(t_gen *gen)
{
	t_hist	*current;
	t_hist	*to_del;

	if (gen->hist)
	{
		current = gen->hist;
		while (current)
		{
			to_del = current;
			current = current->next;
			to_del->pose_buff = 0;
			to_del->len = 0;
			to_del->modif = 0;
			to_del->number = 0;
			to_del->next = NULL;
			to_del->prev = NULL;
			free(to_del);
			to_del = NULL;
		}
	}
}

void	destroy_gen_term(t_gen *gen)
{
	if (gen->term)
	{
		gen->term->fd = 0;
		gen->term->wait = 0;
		if (gen->term->key)
			free_split(&(gen->term->key));
		free(gen->term);
		gen->term = NULL;
	}
}

void	destroy_gen(void)
{
	t_gen	*gen;

	gen = recup_gen();
	erase_list(gen->builtin);
	gen->ret = 0;
	gen->status = 0;
	gen->pid_fork = 0;
	if (gen->ps1)
	{
		if (gen->ps1->aff)
			ft_strdel(&(gen->ps1->aff));
		if (gen->ps1->env)
			ft_strdel(&(gen->ps1->env));
		gen->ps1->len = 0;
		free(gen->ps1);
		gen->ps1 = NULL;
	}
	destroy_gen_term(gen);
	destroy_gen_hist(gen);
	ft_freetmpenv(gen);
}
