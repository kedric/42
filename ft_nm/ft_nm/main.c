/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 18:32:38 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/27 11:56:42 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

char *search_letter(char *s)
{
	while (ft_isalpha(*s) == 0)
		s++;
	return (s);
}

int		chrhexa(void *to, size_t len, char *chm)
{
	size_t i;
	struct mach_header_64 *head;
	int		ret;

	i = 0;
	ret = 0;
	while (i < len)
	{
		head = (struct mach_header_64 *)((char *)to + i);
		if (head != 0)
		{
			if (head->magic == MH_MAGIC_64 || head->magic == MH_CIGAM_64)
			{
				ret = 1;
				ft_printf("%s(%s)\n", chm, search_letter((char *)head - 30));
				handle_64((void *)head);
				ft_printf("\n");
			}
		}
			i++;
	}
	return (ret);
}

int	test_64(char *ptr, size_t len, char *chm)
{
	struct mach_header_64 *head;

	head = (struct mach_header_64 *)ptr;
	if (head->magic == MH_MAGIC_64 || head->magic == MH_CIGAM_64)
	{
		handle_64(ptr);
		return (1);
	}
	else if (chrhexa(ptr, len, chm))
		return(1);

	return(0);
}

void	nm(char *ptr, size_t len, char *chm)
{

	unsigned int magic_number;

	magic_number = *(int *) ptr;
	if (test_64(ptr, len, chm))
		return ;
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		handle_32(ptr);
}

char	*open_file(char *file, size_t *len)
{
	int			fd;
	struct stat	buff;
	void		*ptr;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_puterr("fail to open file\n");
		return (NULL);
	}
	if (fstat(fd, &buff) < 0)
	{
		ft_puterr("stat fail");
		return (NULL);
	}
	*len =  buff.st_size;
	if ((ptr = mmap(0, *len, PROT_READ, MAP_PRIVATE,fd, 0)) == MAP_FAILED)
	{
		ft_puterr("mmap fail");
		return (NULL);
	}
	return (ptr);
}


int	main (int ac, char **av)
{
	char	*ptr;
	size_t	len;
	int		i;

	i = 1;
	if (ac == 1)
		av[i--] = "a.out";
	while (i < ac)
	{
		if (ac > 2)
			ft_printf("\n%s:\n", av[i]);
		ptr = open_file(av[i], &len);
		if (ptr != NULL)
		{
			nm(ptr, len, av[i]);
			munmap(ptr, len);
		}
		i++;
	}

}
