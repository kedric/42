/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 09:00:08 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/29 16:33:44 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

t_list		*ft_list_new(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->value = value;
		new->next = NULL;
	}
	return (new);
}

t_list		*ft_list_insert(t_list *insert, t_list *lst)
{
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = insert;
		return (lst);
	}
	return (insert);
}

void		ft_print_lst(t_list *lst)
{
	while (lst)
	{
		ft_putnbr(lst->value);
		ft_putchar(' ');
		lst = lst->next;
	}
}

void		ft_putact(t_list *lsta, t_list *lstb, char *act, int d)
{
	static int	i = 0;

	if (++i && d == 1)
	{
		ft_putstr("action (numero ");
		ft_putnbr(i);
		ft_putstr(") -> ");
		ft_putstr(act);
		ft_putstr("\nl_a : ");
		ft_print_lst(lsta);
		ft_putstr("\nl_b : ");
		ft_print_lst(lstb);
		ft_putstr("\n\n");
	}
	else
		ft_putstr(act);
}
