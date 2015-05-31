/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 14:04:30 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/21 15:18:37 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdio.h>

t_coord	ft_draw_img(t_coord pic, int x, int y)
{
	pic.i_data[y * 3200 + x * 4] = (char)0XFFFFFF;
	pic.i_data[y * 3200 + x * 4 + 1] = (char)0XFFFFFF;
	pic.i_data[y * 3200 + x * 4 + 2] = (char)0XFFFFFF;
	return (pic);
}

void	ft_set_coord(int *x, int *max, int nb1, int nb2)
{
	if (nb1 < nb2)
	{
		*x = nb1;
		*max = nb2;
	}
	else
	{
		*x = nb2;
		*max = nb1;
	}
}

t_coord		ft_draw_j(t_coord pic, int i, int j)
{
	float		m;
	float		p;
	int			x;
	int			y;
	int			max;

	y = pic.tab[i][j + 1][1] - pic.tab[i][j][1];
	x = pic.tab[i][j + 1][0] - pic.tab[i][j][0];
	m = (float)y / (float)x;
	p = pic.tab[i][j][1] - (m * pic.tab[i][j][0]);
	ft_set_coord(&x, &max, pic.tab[i][j][0], pic.tab[i][j + 1][0]);
	while (x < max)
	{
		y = (int)((m * x + p) + 0.5);
		pic = ft_draw_img(pic, x, y);
		x++;
	}
	ft_set_coord(&y, &max, pic.tab[i][j][1], pic.tab[i][j + 1][1]);
	while (y < max)
	{
		x = (int)((y - p) / m + 0.5);
		pic = ft_draw_img(pic, x, y);
		y++;
	}
	return (pic);
}

t_coord		ft_draw_i(t_coord pic, int i, int j)
{
	float	m;
	float	p;
	int		x;
	int		y;
	int		max;

	y = pic.tab[i + 1][j][1] - pic.tab[i][j][1];
	x = pic.tab[i + 1][j][0] - pic.tab[i][j][0];
	m = (float)y / (float)x;
	p = pic.tab[i][j][1] - (m * pic.tab[i][j][0]);
	ft_set_coord(&x, &max, pic.tab[i][j][0], pic.tab[i + 1][j][0]);
	while (x < max)
	{
		y = (int)(m * x + p + 0.5);
		pic = ft_draw_img(pic, x, y);
		x++;
	}
	ft_set_coord(&y, &max, pic.tab[i][j][1], pic.tab[i + 1][j][1]);
	while (y < max)
	{
		x = (int)(y - p) / m + 0.5;
		pic = ft_draw_img(pic, x, y);
		y++;
	}
	return (pic);
}

t_coord		ft_draw_line(t_coord pict)
{
	int		i;
	int		j;

	i = 0;
	while (i < pict.length)
	{
		j = 0;
		while (j < pict.width - 1)
			pict = ft_draw_j(pict, i, j++);
		i++;
	}
	i = 0;
	while (i < pict.length - 1)
	{
		j = 0;
		while (j < pict.width)
			pict = ft_draw_i(pict, i, j++);
		i++;
	}
	return (pict);
}

