/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:26:54 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/12 08:20:23 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"

void	aff_err(void)
{
		tputs(tgetstr("mr", NULL), 1, ft_putc);
		tputs("term to small", 1, ft_putc);
		tputs(tgetstr("me", NULL), 1, ft_putc);
}

void	aff_lst(t_lstsel *lst, t_sig *sig)
{
	int	i[2];
	int	last_len;

	i[0] = 0;
	sig->y = tgetnum("li");
	sig->x = tgetnum("co");
	while (lst)
	{
		i[1] = 0;
		last_len = 0;
		while (i[1]++ < sig->y && lst)
		{
			if ((int)ft_strlen(lst->value) > sig->max_len)
				sig->max_len = (int)ft_strlen(lst->value);
			if ((int)ft_strlen(lst->value) > last_len)
				last_len = (int)ft_strlen(lst->value);
			lst = lst->next;
			i[0]++;
		}
	}
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	if ((i[0] / sig->y) * (sig->max_len + 2) + last_len > sig->x)
		aff_err();
	else
		aff_tlst(sig->lst, sig);
}

void	affret(t_lstsel *lst)
{
	while (lst)
	{
		if (lst->sel == 1)
		{
			ft_putstr(lst->value);
			ft_putchar(' ');
		}
		lst = lst->next;
	}
}
