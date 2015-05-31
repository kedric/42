/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 08:08:50 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/29 16:39:54 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_trie(t_list *lsta, int d)
{
	int		min;
	t_list	*lstb;

	lstb = NULL;
	while (lsta)
	{
		min = ft_srch_min(&lsta, lstb, d);
		while (lsta->value != min)
		{
			ft_placeend(&lsta);
			ft_putact(lsta, lstb,"ra ", d);
		}
		ft_changelist(&lstb, &lsta);
		ft_putact(lsta, lstb,"pb ", d);
	}
	while (lstb)
	{
		ft_changelist(&lsta, &lstb);
		ft_putact(lsta, lstb, "pa ", d);
	}
	ft_putchar('\n');
}

int		ft_srch_min(t_list **lsta, t_list *lstb, int d)
{
	int		min;
	t_list	*lstav;

	lstav = *lsta;
	min = lstav->value;
	while (lstav->next)
	{
		if (lstav->value < min)
			min = lstav->value;
		lstav = lstav->next;
	}
	if (lstav->value < min)
	{
		min = lstav->value;
		ft_placestart(&*lsta);
		ft_putact(lstav, lstb, "rra ", d);
	}
	return (min);
}

int		ft_vdigit(int c, int n, int j)
{
	if ((c >= 48 && c <= 57) || ((c == 45 && j == 0) && n != 0))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	int		d;
	t_list	*lsta;

	i = 1 + (d = 0);
	lsta = NULL;
	if (ac > 1)
	{
		if (ft_strcmp(av[i], "-d") == 0)
			d = i++;
		while (i < ac && (j = -1) == -1)
		{
			while (av[i][++j] != '\0')
			{
				if (!ft_vdigit(av[i][j], av[i][j + 1], j))
				{
					ft_puterr("error\n");
					return (0);
				}
			}
			lsta = ft_list_insert(ft_list_new(ft_atoi(av[i++])), lsta);
		}
		ft_trie(lsta, d);
	}
}
