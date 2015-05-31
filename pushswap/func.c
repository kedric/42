/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 08:59:49 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/29 16:35:12 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_placeend(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp_mv;

	tmp_mv = lst[0]->next;
	tmp = lst[0]->next;
	lst[0]->next = NULL;
	while (tmp_mv->next)
		tmp_mv = tmp_mv->next;
	tmp_mv->next = lst[0];
	lst[0] = tmp;
}

void	ft_placestart(t_list **lst)
{
	t_list	*first;
	t_list	*prelast;

	first = lst[0];
	prelast = lst[0];
	while (prelast->next->next)
		prelast = prelast->next;
	lst[0] = prelast->next;
	lst[0]->next = first;
	prelast->next = NULL;
}

void	ft_changelist(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = src[0]->next;
		src[0]->next = dest[0];
		dest[0] = src[0];
		src[0] = tmp;
	}
}
