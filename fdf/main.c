/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 10:57:30 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/21 15:24:36 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int		ft_expose_hook(t_coord *pic)
{
	int	i;

	i = mlx_put_image_to_window(pic->mlx, pic->wdw, pic->img, 0, 0);
	return (i);
}

int	ft_read_file(int fd, char **str)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	*str = (char *)malloc(sizeof(char) * 1);
	**str = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin(*str, buff);
		free(*str);
		*str = temp;
	}
	if (ret == -1)
		return (-1);
	return (0);
}

void	ft_print(int **tab, t_dim *dim)
{
	int		loop;
	t_coord	pic;

	pic.tab = mlx_create_coord(tab, dim);
	pic.length = dim->lgh;
	pic.width = dim->wdh;
	pic.mlx = mlx_init();
	pic.wdw = mlx_new_window(pic.mlx, 800, 800, "FdF");
	loop = mlx_key_hook(pic.wdw, &ft_key_hook, NULL);
	pic = ft_set_img(pic);
	pic = ft_draw_line(pic);
	loop = mlx_expose_hook(pic.wdw, &ft_expose_hook, &pic);
	loop = mlx_loop(pic.mlx);
}

int	ft_start(int ac, char ** av, t_fd *fd, char **str)
{
	if (ac == 1)
	{
		ft_putstr("usage: ./fdf file1\n");
		return (-1);
	}
	if ((fd->open = open(av[1], O_RDONLY)) == -1)
	{
		perror(av[1]);
		return (-1);
	}
	if ((fd->read = ft_read_file(fd->open, str)) == -1)
	{
		perror(av[1]);
		return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_fd	*fd;
	t_dim	*dim;
	char	*str;
	int		**tab;

	tab = 0;
	fd = (t_fd *)malloc(sizeof(t_fd));
	dim = (t_dim *)malloc(sizeof(t_dim));
	if (ft_start(ac, av, fd, &str) == -1)
		return (0);
	if ((tab = fdf_create_tab(&str, &dim->lgh, &dim->wdh)) == NULL)
	{
		ft_putstr(av[1]);
		ft_putstr(": Incorrect value in file\n");
		return (0);
	}
	fd->open = close(fd->open);
	ft_print(tab, dim);
	return (0);
}
