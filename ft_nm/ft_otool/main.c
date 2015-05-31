/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 09:15:14 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/26 10:20:32 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <stdio.h>

void	otool(char *ptr)
{

	unsigned int magic_number;

	magic_number = *(int *) ptr;

	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		handle_64(ptr);
	// else if (magic_number == MH_MAGIC)
	// {
	// 	handle_32(ptr);
	// 	ft_printf("je suis ici\n");
	// }
}

char	*open_file(char *file)
{
	int			fd;
	struct stat	buff;
	void		*ptr;
	int			len;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("fail to open file\n", 2);
		return (NULL);
	}
	if (fstat(fd, &buff) < 0)
	{
		ft_putstr_fd("stat fail\n", 2);
		return (NULL);
	}
	len =  buff.st_size;
	if ((ptr = mmap(0, len, PROT_READ, MAP_PRIVATE,fd, 0)) == MAP_FAILED)
	{
		ft_putstr_fd("mmap fail\n", 2);
		return (NULL);
	}
	return (ptr);
}


int	main (int ac, char **av)
{
	char	*ptr;

	(void) ac;
	ptr = open_file(av[1]);
	if (ptr != NULL)
	{
		otool(ptr);
	}
}
