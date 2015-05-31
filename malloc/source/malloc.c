/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 16:55:21 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/19 07:33:55 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

void		*alloc_memmory(t_plage *page, size_t size)
{
	void	*tmp;

	while (page->next && (page->aloued == 1 || size > page->len))
		page = (t_plage *)page->next;
	if (page->next == NULL)
	{
		tmp = ((char *)page) + (sizeof(t_plage) + size + 1);
		page->next = creeat_plage(page->len - (size + sizeof(t_plage)),
		(void *)page, NULL, tmp);
		page->len = size + sizeof(t_plage);
		page->aloued = 1;
	}
	else
	{
		page->len = size + sizeof(t_plage);
		page->aloued = 1;
	}
	return (page);
}

t_table		*return_page_to_alloc(t_table *table, size_t size)
{
	table = table->next;
	if (size < TINY_MAX && (size_t)(size + sizeof(t_plage)) < table->max_len)
		return (table);
	else
		table = table->next;
	if (size > TINY_MAX && size < SMALL_MAX\
		&& (size + sizeof(t_plage)) <= table->max_len)
		return (table);
	else if (table->next != NULL)
		table = table->next;
	while (size > table->max_len && table->next)
		table = table->next;
	if (table->next == NULL || size > table->max_len)
	{
		table->next = (t_table *)active_new_page(size);
		table = table->next;
		table->max_len = (getpagesize() * (((size + sizeof(t_plage) + 32)
		/ getpagesize()) + 1)) - (sizeof(t_table) + 64);
		table->page_len = size;
		table->next = NULL;
		table->page = creeat_plage(table->max_len, NULL, NULL,
		(char *)table + sizeof(t_table));
	}
	return (table);
}

void		first_call(t_table *table)
{
	struct rlimit	limit;
	int				page;

	page = getpagesize();
	limit.rlim_cur = RLIM_INFINITY;
	limit.rlim_max = RLIM_INFINITY;
	getrlimit(RLIMIT_AS, &limit);
	getrlimit(RLIMIT_STACK, &limit);
	getrlimit(RLIMIT_RSS, &limit);
	getrlimit(RLIMIT_DATA, &limit);
	getrlimit(RLIMIT_MEMLOCK, &limit);
	table->max_len = 0;
	table->next = (t_table *)active_new_page((TINY_MAX + 32) * 120);
	table = table->next;
	table->max_len = page * (((TINY_MAX + 32) * 120 / page) + 1);
	table->page_len = (TINY_MAX + 32);
	table->page = creeat_plage(table->max_len,
	NULL, NULL, (char *)table + sizeof(t_table));
	table->next = (t_table *)active_new_page((SMALL_MAX + 32) * 120);
	table = table->next;
	table->max_len = page * (((TINY_MAX + 32) * 120 / page) + 1);
	table->page_len = (SMALL_MAX + 32);
	table->next = NULL;
	table->page = creeat_plage(table->max_len, NULL,
	NULL, (char *)table + sizeof(t_table));
}

t_table		*paye_ton_thon(void)
{
	static t_table	table;
	static int		call = 0;

	if (call == 0)
	{
		first_call(&table);
		call++;
	}
	return (&table);
}

void		*malloc(size_t size)
{
	t_table	*table;
	t_table	*tmp;
	void	*ret;

	table = paye_ton_thon();
	if (size < 1)
		return (NULL);
	tmp = return_page_to_alloc(table, size + sizeof(t_plage));
	ret = alloc_memmory(tmp->page, size);
	tmp->max_len = tmp->max_len - (size + sizeof(t_plage));
	ret = (char *)ret + sizeof(t_plage);
	return (ret);
}
