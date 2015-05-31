/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:45:14 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/21 15:18:18 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_cc(int *x, int *y, int *cnt, int **tab)
{
	float	tmp;

	tmp = 15. + 35. * (0.82 * cnt[0] + 0.57 * cnt[1]);
	*x = (int)(tmp + 0.5);
	tmp = 0.57 * (0.57 * cnt[0] - 0.82 * cnt[1]);
	tmp -= 0.06 * tab[cnt[0]][cnt[1]];
	tmp *= 35.;
	tmp += 533.;
	*y = (int)(tmp + 0.5);
}

int			***mlx_create_coord(int **tab, t_dim *dim)
{
	int		***crd;
	int		cnt[2];
	int		l;
	int		w;

	l = dim->lgh;
	w = dim->wdh;
	if (!(crd = (int ***)malloc(sizeof(int **) * l)))
		return (NULL);
	cnt[0] = 0;
	while (cnt[0] < l)
	{
		if (!(crd[cnt[0]] = (int **)malloc(sizeof(int *) * w)))
			return (NULL);
		cnt[1] = 0;
		while (cnt[1] < w)
		{
			if (!(crd[cnt[0]][cnt[1]] = (int *)malloc(sizeof(int) * 2)))
				return (NULL);
			ft_cc(&crd[cnt[0]][cnt[1]][0], &crd[cnt[0]][cnt[1]][1], cnt, tab);
			cnt[1]++;
		}
		cnt[0]++;
	}
	return (crd);
}

int			*ft_create_line(char *str, int *i)
{
	int			*line;
	char		**tab;

	tab = ft_strsplit(str, ' ');
	*i = 0;
	while (tab[*i])
		*i += 1;
	if (!(line = (int *)malloc(sizeof(line) * (*i + 1))))
		return (NULL);
	*i = 1;
	while (tab[*i])
	{
		line[*i] = ft_atoi(tab[*i]);
		*i += 1;
	}
	return (line);
}

int		**fdf_create_tab(char **str, int *i, int *len)
{
	int			**tab;
	char		**tab_str;
	size_t		rest;

	if ((tab_str = ft_strsplit(*str, '\n')) == NULL)
		return (NULL);
	free(*str);
	rest = ft_strlen(tab_str[(*i = 0)]);
	while (tab_str[*i])
	{
		if (rest != ft_strlen(tab_str[*i]))
			return (NULL);
		*i += 1;
	}
	if (!(tab = (int **)malloc(sizeof(tab) * (*i + 1))))
		return (NULL);
	*i = 0;
	while (tab_str[*i])
	{
		if ((tab[*i] = ft_create_line(tab_str[*i], len)) == NULL)
			return (NULL);
		*i += 1;
	}
	return (tab);
}

t_coord		ft_set_img(t_coord pic)
{
	int		i;
	int		j;
	int		bpp;
	int		size;
	int		endian;

	pic.img = mlx_new_image(pic.mlx, 800, 800);
	i = (endian = (bpp = (size = 0)));
	pic.i_data = mlx_get_data_addr(pic.img, &bpp, &size, &endian);
	while (i < pic.length)
	{
		j = 0;
		while (j < pic.width)
		{
			pic.i_data[pic.tab[i][j][1] * 3200 + pic.tab[i][j][0] * 4] =
				(char)0XFF;
			pic.i_data[(pic.tab[i][j][1] * 3200 + pic.tab[i][j][0] * 4) + 1] =
				(char)0XFF;
			pic.i_data[(pic.tab[i][j][1] * 3200 + pic.tab[i][j][0] * 4) + 2] =
				(char)0xFF;
			j++;
		}
		i++;
	}
	return (pic);
}
