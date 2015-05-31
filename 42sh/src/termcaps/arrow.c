/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:23:05 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:23:10 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	fn_curs_left(t_gen *gen, char *buff)
{
	(void)buff;
	if (gen->hist->pose_buff > 0)
	{
		gen_tc_move_left(gen, 1);
		gen->hist->pose_buff--;
	}
	else
		ft_putstr_fd(bell, gen->term->fd);
}

void	fn_curs_right(t_gen *gen, char *buff)
{
	(void)buff;
	if (gen->hist->pose_buff < gen->hist->len)
	{
		gen_tc_move_right(gen, 1);
		gen->hist->pose_buff++;
	}
	else
		ft_putstr_fd(bell, gen->term->fd);
}

int		possibility_to_up(t_gen *gen)
{
	int	j;

	j = gen->hist->pose_buff - 1;
	while (gen->hist->buff[j] && gen->hist->buff[j] != '\n')
		j--;
	if (j > 0)
		return (gen->hist->pose_buff - j);
	return (0);
}

void	fn_curs_up(t_gen *gen, char *buff)
{
	(void)buff;
	if (gen->hist->prev && possibility_to_up(gen) == 0)
	{
		tc_clean_line(gen);
		gen->hist = gen->hist->prev;
		gen->hist->pose_buff = gen->hist->len;
		ft_putstr_fd(gen->hist->buff, gen->term->fd);
	}
	else if (possibility_to_up(gen))
	{
		gen_tc_move_left(gen, possibility_to_up(gen));
		gen->hist->pose_buff = \
						gen->hist->pose_buff - possibility_to_up(gen);
	}
	else
		ft_putstr(bell);
}

void	fn_curs_down(t_gen *gen, char *buff)
{
	(void)buff;
	if (gen->hist->next)
	{
		tc_clean_line(gen);
		gen->hist = gen->hist->next;
		gen->hist->pose_buff = gen->hist->len;
		ft_putstr_fd(gen->hist->buff, gen->term->fd);
	}
	else
		ft_putstr(bell);
}
