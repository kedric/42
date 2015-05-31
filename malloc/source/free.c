/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 17:54:09 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/18 17:54:11 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;
	void	*tmp;

	tmp = (char *)ptr - (sizeof(t_plage));
	old_size = ((t_plage *)tmp)->len;
	if (old_size == (size + sizeof(t_plage)))
		return (ptr);
	new_ptr = malloc(size);
	if ((old_size - sizeof(t_plage)) > size)
		new_ptr = ft_memcpy(new_ptr, ptr, (old_size - sizeof(t_plage)));
	else
		new_ptr = ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

int		chr_ptr(t_chr *chr, t_table *table, t_plage *ptr)
{
	int i;

	i = 0;
	chr->tmp_old = table;
	chr->tmp = table->next;
	while (chr->tmp)
	{
		i++;
		chr->tmp_p = chr->tmp->page;
		while (chr->tmp_p)
		{
			if (chr->tmp_p == ptr)
				break ;
			chr->tmp_p = chr->tmp_p->next;
		}
		if (chr->tmp_p == ptr)
			break ;
		chr->tmp_old = chr->tmp;
		chr->tmp = chr->tmp->next;
	}
	return (i);
}

void		clear_alloc(t_plage *ptr, t_table *table)
{
	t_chr chr;
	int i;

	i = chr_ptr(&chr, table, ptr);
	if (((t_plage *)chr.tmp_p->next)->aloued == 1)
		return ;
	else if (chr.tmp_p->prev == NULL && ((t_plage *)ptr->next)->aloued == 0 && i > 2)
	{
		chr.tmp_old->next = chr.tmp->next;
		munmap(chr.tmp, chr.tmp->page_len);
	}
	else if ((t_plage *)chr.tmp_p->prev  != NULL && ((t_plage *)chr.tmp_p->prev)->aloued == 0)
	{
		((t_plage *)chr.tmp_p->prev)->len = ((t_plage *)chr.tmp_p->prev)->len + chr.tmp_p->len;
		if (chr.tmp->max_len < ((t_plage *)chr.tmp_p->prev)->len)
			chr.tmp->max_len = ((t_plage *)chr.tmp_p->prev)->len;
	}
	else if ((t_plage *)chr.tmp_p->next  != NULL && ((t_plage *)chr.tmp_p->next)->aloued == 0)
	{
		chr.tmp_p->len = ((t_plage *)chr.tmp_p->next)->len + chr.tmp_p->len;
		if (chr.tmp->max_len < chr.tmp_p->len)
			chr.tmp->max_len = chr.tmp_p->len;
	}
}

void		*free_me(void *ptr)
{
	size_t	len;

	ptr = ((char *)ptr) - sizeof(t_plage);
	len = ((t_plage *)ptr)->len;
	((t_plage *)ptr)->aloued = 0;
	return (ptr);
}

void		free(void *ptr)
{
	ptr = free_me(ptr);
	clear_alloc(ptr, paye_ton_thon());
}
