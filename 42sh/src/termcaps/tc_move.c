/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:14:27 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:14:30 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		count_char_to_nl(t_gen *gen, int pos)
{
	int	pos_tmp;

	pos_tmp = pos - 1;
	while (gen->hist->buff[pos_tmp] && !ft_isnl(gen, pos_tmp))
		pos_tmp--;
	return (pos - pos_tmp - 1);
}

int		ft_isnl(t_gen *gen, int pos)
{
	int pos_tmp;
	int len;

	len = tgetnum("co");
	if (gen->hist->buff[pos] == '\n')
		return (1);
	else
	{
		pos_tmp = pos;
		while (gen->hist->buff[pos_tmp] && gen->hist->buff[pos_tmp] != '\n')
			pos_tmp--;
		if (pos_tmp <= 0)
		{
			if ((pos + 1 + gen->ps1->len) % len == 0)
				return (1);
		}
		else if ((pos - pos_tmp) % len == 0)
		{
			if ((pos - pos_tmp) % len == 0)
				return (2);
		}
	}
	return (0);
}

void	tc_move_left(t_gen *gen, int i, int force)
{
	int	j;
	int	n_p;

	j = gen->hist->pose_buff - i + 1;
	while (i > 0)
	{
		if (force == 1 || !ft_isnl(gen, j - 1))
			ft_putstr_fd(tgetstr("le", NULL), gen->term->fd);
		else
		{
			n_p = count_char_to_nl(gen, j - i - 1) + 1;
			if (j - n_p - 2 <= 0)
				n_p = n_p + gen->ps1->len;
			tc_move_right(gen, n_p, 1);
			ft_putstr_fd(tgetstr("ku", NULL), gen->term->fd);
		}
		i--;
	}
}

void	tc_move_right(t_gen *gen, int i, int force)
{
	int	j;
	int n_p;

	j = 0;
	while (j < i)
	{
		if (force == 1 || !ft_isnl(gen, gen->hist->pose_buff))
			ft_putstr_fd(tgetstr("nd", NULL), gen->term->fd);
		else
		{
			n_p = count_char_to_nl(gen, gen->hist->pose_buff);
			if (gen->hist->buff[gen->hist->pose_buff - n_p] == '\0'
					|| (gen->hist->buff[gen->hist->pose_buff - n_p] + 1 != '\n'
						&& ft_isnl(gen, gen->hist->pose_buff) == 1))
				n_p = n_p + gen->ps1->len;
			tc_move_left(gen, n_p, 1);
			ft_putstr_fd(tgetstr("kd", NULL), gen->term->fd);
		}
		j++;
	}
}

void	gen_tc_move_left(t_gen *gen, int i)
{
	int	tmp;

	tmp = gen->hist->pose_buff;
	while (i--)
	{
		tc_move_left(gen, 1, 0);
		gen->hist->pose_buff--;
	}
	gen->hist->pose_buff = tmp;
}
