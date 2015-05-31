/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:53:48 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/09 11:40:30 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#include <stdlib.h>

void	init_grid(char *x, char *y, t_game *game)
{
	int i_x;
	int i_y;

	i_x = 0;
	game->max_x = ft_atoi(x);
	game->max_y = ft_atoi(y);
	game->grid = (int **)malloc(sizeof(int *) * game->max_x);
	while (i_x < game->max_x)
	{
		i_y = 0;
		game->grid[i_x] = (int *)malloc(sizeof(int) * game->max_y);
		while (i_y < game->max_y)
		{
			game->grid[i_x][i_y] = 0;
			i_y++;
		}
		i_x++;
	}
}

t_game	*init_game(void)
{
	static t_game *game = NULL;

	if (game == NULL)
	{
		game = (t_game *)malloc(sizeof(t_game));
		game->grid = NULL;
		game->ia_lvl = 5;
		game->player[0] = 1;
		game->player[1] = 1;
	}
	return (game);
}
