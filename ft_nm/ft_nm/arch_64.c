/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch_64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 13:46:16 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/27 11:59:01 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	ft_swap(struct nlist_64 *a, struct nlist_64 *b)
{
	struct nlist_64 c;

	ft_memcpy(&c , a, sizeof(struct nlist_64));
	ft_memcpy(a , b, sizeof(struct nlist_64));
	ft_memcpy(b , &c, sizeof(struct nlist_64));
}

struct nlist_64 *sort_struct(struct nlist_64 *tab, int nsyms, char *string_t)
{
	int i;

	i = 1;
	while (i < nsyms)
	{
		if(ft_strcmp(string_t + tab[i - 1].n_un.n_strx,
			string_t + tab[i].n_un.n_strx) > 0)
		{
			ft_swap(&tab[i - 1], &tab[i]);
			i = 0;
		}
		i++;
	}
	return (tab);
}

struct nlist_64 *cpy_struct(int nsyms, struct nlist_64 *orig)
{
	int i;
	struct nlist_64 *cpy;

	i = 0;
	cpy = (struct nlist_64 *)malloc(sizeof(struct nlist_64) * nsyms);
	while (i < nsyms)
	{
		ft_memcpy(&cpy[i], &orig[i], sizeof(struct nlist_64));
		i++;
	}
	return (cpy);
}

int	ft_put_exa(long long unsigned int n)
{
	if (n < 16)
	{
		if (n < 10)
			return (ft_putchar(n + '0'));
		else
			return (ft_putchar(n - 10 + 'a'));
	}
	else
	{
		if ((n % 16) < 10)
			return (ft_put_exa((n / 16)) + ft_putchar((n % 16) + '0'));
		else
			return (ft_put_exa((n / 16)) + ft_putchar((n % 16) - 10 + 'a'));
	}
}
int	ft_count_exa(long long unsigned int n, int i)
{
	if (n < 16)
	{
		if (n < 10)
			return (i + 1);
		else
			return (i + 1);
	}
	else
	{
		if ((n % 16) < 10)
			return (ft_count_exa((n / 16), i + 1));
		else
			return (ft_count_exa((n / 16), i + 1));
	}
}
void ft_print_struct(struct nlist_64 *el, int i, char *string_t)
{
	char c;
	int j;

	c = ((el[i].n_type & N_TYPE )  == N_UNDF) ? 'U' : ' ';
	c = ((el[i].n_type & N_TYPE)  == N_SECT) ? 'T' : c;
	c = ((el[i].n_type & N_TYPE)  == N_ABS) ? 'A' : c;
	c = ((el[i].n_type & N_TYPE)  == N_PBUD) ? ' ' : c;
	c = ((el[i].n_type & N_TYPE)  == N_INDR) ? ' ' : c;
	if (el[i].n_value > 1
		&& strncmp(string_t + el[i].n_un.n_strx, "radr", 4))
	{
		j = ft_count_exa(el[i].n_value, 0);
		while (j++ < 16)
			ft_putchar('0');
		ft_put_exa(el[i].n_value);
	}
	else if (strncmp(string_t + el[i].n_un.n_strx, "radr", 4))
		ft_printf("                ");
	if (strncmp(string_t + el[i].n_un.n_strx, "radr", 4))
		ft_printf(" %c %s\n", c, string_t + el[i].n_un.n_strx);
}

void	print_output(int nsyms, int symoff, int stroff, char *ptr)
{
	int i;
	char *string_t;
	struct nlist_64 *el;

	el = cpy_struct(nsyms, (void *)(ptr + symoff));
	string_t = ptr + stroff;
	el = sort_struct(el , nsyms, string_t);
	i = 0;
	while (i < nsyms)
	{
		ft_print_struct(el, i, string_t);
		i++;
	}
}

int	handle_64(char *ptr)
{
	int						n_cmds;
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						i;
	struct	symtab_command	*sym;

	i = 0;
	header = (struct mach_header_64 *) ptr;
	lc = (struct load_command *)((char *)ptr + sizeof(*header));
	n_cmds = header->ncmds;
	while (i < n_cmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *) lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
		i++;
	}
	if (header->filetype == MH_EXECUTE)
		return (1);
	return (0);
}
