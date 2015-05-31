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

void	show_alloc_mem(void)
{
	print_alloc(paye_ton_thon());
}

void	print_alloc(t_table *table)
{
	table = table->next;
	ft_putstr("TINY : ");
	ft_putpoint((unsigned long int)table);
	ft_putstr("\n");
	print_table(table->page);
	table = table->next;
	ft_putstr("SMALL : ");
	ft_putpoint((unsigned long int)table);
	ft_putstr("\n");
	print_table(table->page);
	table = table->next;
	ft_putstr("LARGE : ");
	ft_putpoint((unsigned long int)table);
	ft_putstr("\n");
	while (table)
	{
		print_table(table->page);
		table = table->next;
	}
}

void	*active_new_page(size_t size)
{
	void	*plen;
	size_t	len;

	len = size + sizeof(t_plage) + 32;
	len = (len / getpagesize()) + 1;
	if ((plen = mmap(NULL, getpagesize() * len,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (active_new_page(size + 1));
	ft_bzero(plen, getpagesize() * len);
	return (plen);
}

t_plage	*creeat_plage(size_t len, void *prev, void *next, void *addr)
{
	((t_plage *)addr)->len = len;
	((t_plage *)addr)->aloued = 0;
	((t_plage *)addr)->next = next;
	((t_plage *)addr)->prev = prev;
	return (addr);
}

void	print_table(t_plage *tmp)
{
	while (tmp)
	{
		if (tmp->aloued == 1)
		{
			ft_putpoint((unsigned long int)((char *)tmp + sizeof(t_plage)));
			ft_putstr(" - ");
			ft_putpoint((unsigned long int)((char *)tmp
				+ (sizeof(t_plage) + tmp->len)));
			ft_putstr(" : ");
			ft_putnbr(tmp->len - sizeof(t_plage));
			ft_putstr(" octets\n");
		}
		tmp = tmp->next;
	}
}
