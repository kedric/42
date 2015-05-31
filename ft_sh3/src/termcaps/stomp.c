/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stomp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:04:24 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 17:35:43 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	(*act[11])(t_term *) =
{
	clear,
	arrow_up,
	arrow_down,
	arrow_right,
	arrow_left,
	put_strdel,
	arrow_right,
	ft_moove_w_left,
	ft_moove_w_right,
	press_ctrld,
};

int		verif_key(char *buff)
{
	int			i;
	t_term		*term;

	i = 0;
	term = recup_term();
	while (term->key[i] && ft_strcmp(term->key[i], buff))
		i++;
	if (term->key[i])
		return (i);
	return (-1);
}

void	ft_add_char(char *buff, t_term *term)
{
	if (buff[0] >= 32 && buff[0] <= 126 && buff[1] == 0)
	{
		if (term->hist->len == term->hist->pose_cursor)
		{
			term->hist->buff[term->hist->pose_cursor] = buff[0];
			term->hist->buff[term->hist->pose_cursor + 1] = '\0';
			term->hist->len++;
			term->hist->pose_cursor++;
			if (term->hist->next == NULL)
				ft_strcpy(term->hist->value, term->hist->buff);
			ft_putstr(buff);
		}
		else
			put_stradd(term, buff);
	}
}

int		ft_break_read(t_term *term)
{
	ft_putchar('\n');
	if (term->quote == 1 || term->dquote == 1)
	{
		if (term->dquote == 1)
			ft_putstr("dquote>");
		else if (term->quote == 1)
			ft_putstr("quote>");
		ft_add_char("\n", term);
		term->wait_fermeture = 1;
		return (1);
	}
	term->wait_fermeture = 0;
	return (0);
}

int		ft_stomp(char *buff, t_term *term)
{
	int	i;

	i = 0;
	if (buff[0] == '\n')
	{
		return (ft_break_read(term));
	}
	else if ((i = verif_key(buff)) != -1)
	{
		act[i](term);
		return (1);
	}
	else
	{
		if (buff[0] == 39)
			press_quote(term);
		if (buff[0] == 34)
			press_dquote(term);
		ft_add_char(buff, term);
	}
	return (1);
}
