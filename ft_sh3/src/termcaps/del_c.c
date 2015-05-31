/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 20:06:41 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 16:50:14 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
void	rm_special_char(t_term *term, char c)
{
	if (c == '\'')
		press_quote(term);
	if (c == '\"')
		press_dquote(term);
}

void	put_strdel(t_term *term)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	clean_line(term);
	if (i < term->hist->len)
	{
		while (i < term->hist->len)
		{
			if (i == term->hist->pose_cursor - 1)
			{
				rm_special_char(term, term->hist->buff[j]);
				j++;
			}
			term->hist->buff[i++] = term->hist->buff[j++];
		}
		term->hist->len--;
		term->hist->pose_cursor--;
		ft_putstr(term->hist->buff);
		i = term->hist->len + 1;
		while (--i != term->hist->pose_cursor)
			ft_putstr_fd(term->key[4], term->fd);
		term->hist->modif = 1;
	}
}

void	clean_line(t_term *term)
{
	int	i;

	i = term->hist->pose_cursor;
	while (i < term->hist->len)
	{
		ft_putstr_fd(term->key[3], term->fd);
		i++;
	}
	i++;
	while (--i > 0)
	{
		ft_putstr_fd(term->key[4], term->fd);
		ft_putstr_fd(tgetstr("dc", NULL), term->fd);
	}
}

void	put_stradd(t_term *term, char *buff)
{
	int		i;
	int		j;
	char	tmp[BUFF_SIZE];

	i = 0;
	j = 0;
	ft_bzero(tmp, BUFF_SIZE);
	ft_strcpy(tmp, term->hist->buff);
	term->hist->len++;
	clean_line(term);
	while (i < term->hist->len)
	{
		if (i == term->hist->pose_cursor)
			term->hist->buff[i++] = buff[0];
		term->hist->buff[i++] = tmp[j++];
	}
	i = term->hist->len;
	ft_putstr(term->hist->buff);
	while (i - 1 != term->hist->pose_cursor)
	{
		ft_putstr_fd(term->key[4], term->fd);
		i--;
	}
	term->hist->pose_cursor++;
	term->hist->modif = 1;
}
