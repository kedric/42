/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 17:57:51 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/12 08:15:15 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"
#include <fcntl.h>

int			ft_putc(int c)
{
	static int	fd = 0;

	if (fd == 0)
		fd= open("/dev/tty", O_WRONLY);
	write(fd, &c, 1);
	return (1);
}

void		aff_tlst(t_lstsel *lst, t_sig *sig)
{
	int	x[2];

	x[0] = 0;
	while (lst)
	{
		x[1] = 0;
		while (x[1] <= sig->y && lst)
		{
			tputs(tgoto(tgetstr("cm", NULL), x[0], x[1]++), 1, ft_putc);
			if (lst->pnt == 1)
				tputs(tgetstr("us", NULL), 1, ft_putc);
			if (lst->sel == 1)
			{
				tputs(tgetstr("mr", NULL), 1, ft_putc);
				tputs(lst->value, 1, ft_putc);
				tputs(tgetstr("me", NULL), 1, ft_putc);
			}
			else
				tputs(lst->value, 1, ft_putc);
			if (lst->pnt == 1)
				tputs(tgetstr("ue", NULL), 1, ft_putc);
			lst = lst->next;
		}
		x[0] = x[0] + sig->max_len + 2;
	}
}

void		ft_mvflech(char e, t_lstsel *lst)
{
	if (e == 'B' || e == 'C')
		ft_pntnext(lst);
	else if (e == 'A' || e == 'D')
		ft_pntprev(lst);
}

void		ft_selectopt(t_lstsel *lst)
{
	while (lst->pnt != 1)
		lst = lst->next;
	lst->sel = (lst->sel == 0) ? 1 : 0;
	ft_mvflech('B', lst);
}

t_lstsel	*ft_delet(t_lstsel *lst)
{
	t_lstsel	*tmp;

	if (lst->next == NULL && lst->prev == NULL)
		exit(ft_close(ft_init_sig()));
	while (lst->pnt != 1)
		lst = lst->next;
	tmp = lst;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else
	{
		tmp->next->prev = NULL;
		lst = lst->next;
	}
	if (tmp->next)
		tmp->next->prev = lst->prev;
	else
		tmp->prev->next = NULL;
	ft_mvflech('B', tmp);
	while (lst->prev)
		lst = lst->prev;
	free(tmp);
	return (lst);
}
