/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 13:00:19 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 13:00:19 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*curr;
	t_list	*save;

	if (lst && f)
	{
		curr = (t_list *)malloc(sizeof(t_list));
		curr = f(lst);
		save = curr;
		tmp = lst->next;
		while (tmp != NULL)
		{
			new = (t_list *)malloc(sizeof(t_list));
			new = f(tmp);
			tmp = tmp->next;
			curr->next = new;
			curr = curr->next;
			new = NULL;
		}
		return (save);
	}
	return (lst);
}
