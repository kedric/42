/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 10:33:36 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/12 07:56:33 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <termios.h>
#include "ft_select.h"
#include <stdlib.h>

void		ft_pntnext(t_lstsel *lst)
{
	while (lst->pnt == 0)
		lst = lst->next;
	lst->pnt = 0;
	if (lst->next)
		lst->next->pnt = 1;
	else
	{
		while (lst->prev)
			lst = lst->prev;
		lst->pnt = 1;
	}
}

t_lstsel	*ft_inilst(char **av, t_lstsel *lst)
{
	int			i;
	t_lstsel	*tmp;

	i = 0;
	while (av[++i])
	{
		tmp = (t_lstsel *)malloc(sizeof(t_lstsel));
		tmp->value = av[i];
		tmp->sel = 0;
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->pnt = (lst == NULL ? 1 : 0);
		if (lst == NULL)
			lst = tmp;
		else
		{
			lst->next = tmp;
			tmp->prev = lst;
			lst = lst->next;
		}
	}
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void		ft_pntprev(t_lstsel *lst)
{
	while (lst->pnt == 0)
		lst = lst->next;
	lst->pnt = 0;
	if (lst->prev)
		lst->prev->pnt = 1;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->pnt = 1;
	}
}

t_lstsel	*ft_read(t_sig *sig)
{
	t_lstsel	*tmp;
	char		*readc;

	tmp = sig->lst;
	readc = ft_memalloc(4);
	while (readc[0] == 0)
		read(0, readc, 4);
	if (readc[0] == 27 && readc[1] == '[')
		ft_mvflech(readc[2], tmp);
	else if (readc[0] == ' ')
		ft_selectopt(tmp);
	else if (readc[0] == '\n')
		return (0);
	else if (readc[0] == 127)
		tmp = ft_delet(tmp);
	if (readc[0] == 27 && readc[1] == '\0')
	{
		ft_close(sig);
		exit(0);
	}
	free (readc);
	return (tmp);
}

int			main(int ac, char **av)
{
	t_sig			*sig;

	if (ac > 1)
	{
		sig = ft_init_sig();
		ft_init_signal();
		sig->lst = ft_inilst(av, sig->lst);
		ft_start(sig);
	}
	return (0);
}
