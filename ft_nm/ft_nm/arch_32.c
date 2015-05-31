/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch_32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 08:29:44 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 08:37:32 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <stdio.h>

void	ft_swap_32(struct nlist *a, struct nlist *b)
{
	struct nlist c;

	ft_memcpy(&c , a, sizeof(struct nlist));
	ft_memcpy(a , b, sizeof(struct nlist));
	ft_memcpy(b , &c, sizeof(struct nlist));
}

struct nlist *sort_struct_32(struct nlist *tab, int nsyms, char *string_t)
{
	int i;

	i = 1;
	while (i < nsyms)
	{
		if(ft_strcmp(string_t + tab[i - 1].n_un.n_strx,
			string_t + tab[i].n_un.n_strx) > 0)
		{
			ft_swap_32(&tab[i - 1], &tab[i]);
			i = 0;
		}
		i++;
	}
	return (tab);
}

struct nlist *cpy_struct_32(int nsyms, struct nlist *orig)
{
	int i;
	struct nlist *cpy;

	i = 0;
	cpy = (struct nlist *)malloc(sizeof(struct nlist) * nsyms);
	while (i < nsyms)
	{
		ft_memcpy(&cpy[i], &orig[i], sizeof(struct nlist));
		i++;
	}
	return (cpy);
}

void	print_output_32(int nsyms, int symoff, int stroff, char *ptr)
{
	int i;
	char *string_t;
	struct nlist *el;
	char c;

	el = (void *)(ptr + symoff);
	el = cpy_struct_32(nsyms, el);
	string_t = ptr + stroff;
	el = sort_struct_32(el , nsyms, string_t);
	i = 0;
	while (i < nsyms)
	{
		c = ((el[i].n_type & N_TYPE )  == N_UNDF) ? 'U' : ' ';
		c = ((el[i].n_type & N_TYPE)  == N_SECT) ? 'T' : c;
		c = ((el[i].n_type & N_TYPE)  == N_ABS) ? ' ' : c;
		c = ((el[i].n_type & N_TYPE)  == N_PBUD) ? ' ' : c;
		c = ((el[i].n_type & N_TYPE)  == N_INDR) ? ' ' : c;
		if (el[i].n_value > 0)
			printf("0000000%08.8x", el[i].n_value);
		else
			printf("                ");
		printf(" %c %s\n",c,string_t + el[i].n_un.n_strx);
		i++;
	}
}

void	handle_32(char *ptr)
{
	int						n_cmds;
	struct mach_header		*header;
	struct load_command		*lc;
	int						i;
	struct	symtab_command	*sym;

	i = 0;
	header = (struct mach_header *) ptr;
	lc = (struct load_command *)((char *)ptr + sizeof(*header));
	n_cmds = header->ncmds;
	while (i < n_cmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			print_output_32(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
		i++;
	}
}
