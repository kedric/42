/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smoove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 08:26:59 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 09:43:17 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_moove_w_left(t_term *term)
{
	int	i;

	i = term->hist->pose_cursor;
	if (i > 0)
	{
		while (term->hist->buff[--i])
		{
			if ((term->hist->buff[i - 1] == ' '
				&& ft_isprint(term->hist->buff[i])) || (i == 0))
				break ;
		}
		while (term->hist->pose_cursor-- != i)
			ft_putstr_fd(term->key[4], term->fd);
		term->hist->pose_cursor = i;
	}
	else
		ft_putstr(bell);
}

void	ft_moove_w_right(t_term *term)
{
	int	i;

	i = term->hist->pose_cursor;
	if (term->hist->buff[i++])
	{
		while (term->hist->buff[i++])
		{
			if (term->hist->buff[i - 1] == ' '
				&& ft_isprint(term->hist->buff[i]))
				break ;
		}
		while (term->hist->pose_cursor++ != i)
			ft_putstr_fd(term->key[3], term->fd);
		term->hist->pose_cursor = i;
	}
	else
		ft_putstr(bell);
}

void	press_ctrld(t_term *term)
{
	ft_putstr("\n");
	parse_ps1(return_env());
	term->quote = 0;
	term->dquote = 0;
	while (term->hist->next)
		term->hist = term->hist->next;
	ft_bzero(term->hist->buff, BUFF_SIZE);
	ft_bzero(term->hist->value, BUFF_SIZE);
	term->hist->exec = 1;
	term->hist->len = 0;
	term->hist->pose_cursor = 0;
}