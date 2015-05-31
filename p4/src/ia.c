/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 08:23:51 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/09 11:54:19 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		valid_position(t_game *game, int x, int y);

int		ft_vs(int player)
{
	if (player == BLUE)
		return (RED);
	return (BLUE);
}

int		mini_max(int player, int deph, t_game *game)
{
	int	check;
	int	max;
	int	tmp;
	int	x;
	int y;

	check = check_winner();
	max = 0;
	tmp = 0;
	if (check == player)
		return (2);
	else if (check == ft_vs(player))
		return (-1);
	else if (check == EGAL)
		return (1);
	else if (deph == 0)
		return (0);
	x = 0;
	while (x < game->max_x)
	{
		y = 0;
		while (y < game->max_y)
		{
			if (!game->grid[x][y] && valid_position(game, x, y))
			{
				game->grid[x][y] = player;
				if (player == BLUE)
				{
					tmp = mini_max(RED, deph - 1, game);
					if (tmp >= max)
						max = tmp;
				}
				else if (player == RED)
				{
					tmp = mini_max(BLUE, deph - 1, game);
					if (tmp <= max)
						max = tmp;
				}
				game->grid[x][y] = 0;
			}
			y++;
		}
		x++;
	}
	return (max);
}

int		valid_position(t_game *game, int x, int y)
{
	if (game->grid[x][y] == 0)
	{
		if (x == game->max_x - 1)
			return (1);
		if (y < game->max_y && game->grid[x + 1][y] != 0)
			return (1);
	}
	return (0);
}

void	search_first_posi(int *x, int *y, t_game *game)
{
	*x = 0;
	while (*x < game->max_x)
	{
		*y = 0;
		while(*y < game->max_y)
		{
			if (valid_position(game, *x, *y))
				return ;
			y++;
		}
		x++;
	}
}

void	ia(int player, t_game *game)
{
	int x_tmp;
	int	y_tmp;
	int	tmp;
	int	max;
	int	x;
	int	y;

	tmp = 0;
	max = -2000000;
	x = 0;
	y = 0;
	x_tmp = 0;
	while(x_tmp < game->max_x)
	{
		y_tmp = 0;
		while (y_tmp < game->max_y)
		{

			if (valid_position(game, x_tmp, y_tmp))
			{
				game->grid[x_tmp][y_tmp] = player;
				// if (mini_max(player, 0, game)  == 1)
				// 	return ;
				// game->grid[x_tmp][y_tmp] = ft_vs(player);
				//  if (mini_max(ft_vs(player), 0 , game) == -1)
				//  {
				// 	game->grid[x_tmp][y_tmp] = player;
				// 	return ;
				//  }
				printf("prob = %d joueur : %d pose x : %d pose : Y %d \n ", tmp, player, x_tmp + 1, y_tmp + 1);
				tmp = mini_max(ft_vs(player), game->ia_lvl, game);
				if (max <= tmp)
				{
					x = x_tmp;
					y = y_tmp;
					max = tmp;
				}
				game->grid[x_tmp][y_tmp] = 0;
			}
			y_tmp++;
		}
		x_tmp++;
	}
	game->grid[x][y] = player;
}
