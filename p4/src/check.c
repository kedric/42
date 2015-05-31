/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:42:11 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/08 13:08:33 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		check_col(t_game *game)
{
	int	x;
	int	y;

	x = (y = 0);
	while (x < game->max_x)
	{
		while (y + 3 < game->max_y)
		{
			if (game->grid[x][y] == RED &&
				game->grid[x][y + 1] == RED &&
				game->grid[x][y + 2] == RED &&
				game->grid[x][y + 3] == RED)
				return (RED);
			else if (game->grid[x][y] == BLUE &&
					game->grid[x][y + 1] == BLUE &&
					game->grid[x][y + 2] == BLUE &&
					game->grid[x][y + 3] == BLUE)
				return (BLUE);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int		check_line(t_game *game)
{
	int	x;
	int	y;

	x = (y = 0);
	while (y < game->max_y)
	{
		while (x + 3 < game->max_x)
		{
			if (game->grid[x][y] == RED &&
				game->grid[x + 1][y] == RED &&
				game->grid[x + 2][y] == RED &&
				game->grid[x + 3][y] == RED)
				return (RED);
			else if (game->grid[x][y] == BLUE &&
					game->grid[x + 1][y] == BLUE &&
					game->grid[x + 2][y] == BLUE &&
					game->grid[x + 3][y] == BLUE)
				return (BLUE);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int		check_null(t_game *game)
{
	int	x;
	int	y;

	x = (y = 0);
	while (x < game->max_x)
	{
		while (y < game->max_y)
		{
			if (game->grid[x][y] == 0)
				return (0);
			y++;
		}
		y = 0;
		x++;
	}
	return (EGAL);
}

int		check_diag(t_game *game)
{
	int	x;
	int	y;

	x = (y = 0);
	while (y + 3 < game->max_y)
	{
		while (x + 3 < game->max_x)
		{
			if (game->grid[x][y] == RED &&
				game->grid[x + 1][y + 1] == RED &&
				game->grid[x + 2][y + 2] == RED &&
				game->grid[x + 3][y + 3] == RED)
				return (RED);
			else if (game->grid[x][y] == BLUE &&
					game->grid[x + 1][y + 1] == BLUE &&
					game->grid[x + 2][y + 2] == BLUE &&
					game->grid[x + 3][y + 3] == BLUE)
				return (BLUE);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int		check_diag_inv(t_game *game)
{
	int	x;
	int	y;

	x = 0;

	while (x + 3 < game->max_x)
	{
		y = game->max_y - 1;
		while (y - 3 > 0)
		{
			if (game->grid[x][y] == RED &&
				game->grid[x + 1][y - 1] == RED &&
				game->grid[x + 2][y - 2] == RED &&
				game->grid[x + 3][y - 3] == RED)
				return (RED);
			else if (game->grid[x][y] == BLUE &&
					game->grid[x + 1][y - 1] == BLUE &&
					game->grid[x + 2][y - 2] == BLUE &&
					game->grid[x + 3][y - 3] == BLUE)
				return (BLUE);
			y--;
		}
		x++;

	}
	return (0);
}

int		check_diag_dbinv(t_game *game)
{
	int	x;
	int	y;

	x = game->max_x - 1;

	while (x - 3 >= 0)
	{
		y = 0;
		while (y + 3 < game->max_y)
		{
			if (game->grid[x][y] == RED &&
				game->grid[x - 1][y + 1] == RED &&
				game->grid[x - 2][y + 2] == RED &&
				game->grid[x - 3][y + 3] == RED)
				return (RED);
			else if (game->grid[x][y] == BLUE &&
					game->grid[x - 1][y + 1] == BLUE &&
					game->grid[x - 2][y + 2] == BLUE &&
					game->grid[x - 3][y + 3] == BLUE)
				return (BLUE);
			y++;
		}
		x--;

	}
	return (0);
}

int		check_winner()
{
	int	ret;
	t_game *game;

	game = init_game();
	ret = 0;
	if (check_null(game))
		return (EGAL);
	else if ((ret = check_col(game)) == BLUE || ret == RED)
		return (ret);
	else if ((ret = check_line(game)) == BLUE || ret == RED)
		return (ret);
	else if ((ret = check_diag(game)) == BLUE || ret == RED)
		return (ret);
	else if ((ret = check_diag_inv(game)) == BLUE || ret == RED)
		return (ret);
	else if ((ret = check_diag_dbinv(game)) == BLUE || ret == RED)
		return (ret);
	return (0);
}
