/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 08:10:01 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 17:21:32 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	clear(t_term *term)
{
	t_env	*env;

	while (term->hist->next)
		term->hist = term->hist->next;
	ft_bzero(term->hist->buff, BUFF_SIZE);
	ft_bzero(term->hist->value, BUFF_SIZE);
	env = return_env();
	ft_putstr_fd(tgetstr("cl", NULL), term->fd);
	term->hist->pose_cursor = 0;
	term->hist->len = 0;
	parse_ps1(env);
}

void	arrow_left(t_term *term)
{
	if (term->hist->pose_cursor > 0)
	{
		ft_putstr_fd(term->key[4], term->fd);
		term->hist->pose_cursor--;
		term->hist->modif = 1;
	}
	else
		ft_putstr(bell);
}

void	arrow_right(t_term *term)
{
	if (term->hist->pose_cursor < term->hist->len)
	{
		ft_putstr_fd(term->key[3], term->fd);
		term->hist->modif = 1;
		term->hist->pose_cursor++;
	}
	else
		ft_putstr(bell);
}

void	arrow_up(t_term *term)
{
	int	i;

	i = term->hist->pose_cursor - 1;
	if (term->hist->prev != NULL && term->wait_fermeture == 0)
	{
		clean_line(term);
		term->hist->exec = 0;
		term->hist = term->hist->prev;
		term->hist->exec = 1;
		ft_putstr(term->hist->buff);
		i = term->hist->len + 1;
		while (--i != term->hist->pose_cursor)
			ft_putstr_fd(term->key[4], term->fd);
	}
	else
		ft_putstr(bell);
}

void	arrow_down(t_term *term)
{
	int	i;

	i = term->hist->pose_cursor - 1;
	if (term->hist->next != NULL && term->wait_fermeture == 0)
	{
		clean_line(term);
		term->hist->exec = 0;
		term->hist = term->hist->next;
		term->hist->exec = 1;
			ft_putstr(term->hist->buff);
		i = term->hist->len + 1;
		while (--i != term->hist->pose_cursor)
			ft_putstr_fd(term->key[4], term->fd);
	}
	else
		ft_putstr(bell);
}
