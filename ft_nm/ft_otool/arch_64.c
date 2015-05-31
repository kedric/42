/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch_64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 10:04:36 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/27 12:46:11 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <unistd.h>
#include <stdio.h>

void	segment_print(struct segment_command_64 *seg, char *ptr)
{
	int i;
	int j;
	char *cmd;
	struct section_64 *a;
	cmd = ptr;
	i = 0;
	while (ft_strncmp(seg[i].segname,"__TEXT", 6) != 0)
		i++;

	j = 0;
	while (*ptr & 0x55){
	ptr++;
}
	a = (struct section_64 *)ptr;
	ft_putstr(a->sectname);
	cmd =(char *)a->addr;
	while (j < seg[i].cmdsize)
	{
		printf("%x ", cmd[j]);
		j++;
	}

}

void	handle_64(char *ptr)
{
	int							n_cmds;
	struct mach_header_64		*header;
	struct load_command			*lc;
	int							i;
	struct segment_command_64	*seg;

	i = 0;
	header = (struct mach_header_64 *) ptr;
	lc = (struct load_command *)((char *)ptr + sizeof(*header));
	n_cmds = header->ncmds;
	while (i < n_cmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *) lc;
			segment_print(seg, ptr);
			break ;
		}
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
		i++;
	}
}
