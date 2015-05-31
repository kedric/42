/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:36:00 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/26 09:36:17 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	char *lol;
	int fd;
	int i;

	//lol = malloc(sizeof(char *));
	i = 0;
	if (ac < 2)
		return (0);
	if	((fd = open("get_next_line.c", O_RDONLY)) == -1)
	{
		ft_putstr("fuck");
		return(0);
	}
	while(get_next_line(fd, &lol))
	{
		i++;
		puts(lol);
		free(lol);
	}
	return (0);
}
