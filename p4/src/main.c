/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 23:16:53 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/08 20:08:27 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	drow_line(int y, int first)
{
	int i;

	i = 0;
	ft_putstr("\n  ");
	while (i < y && first == 0)
	{
		ft_putstr("____");
		i++;
	}
	while (i < y && first == 1)
	{
		ft_putnbr(i + 1);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("\n");
}

void	print_grid(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	drow_line(game->max_y, 1);
	while (x < game->max_x)
	{
		y = 0;
		ft_putnbr(x + 1);
		while (y < game->max_y)
		{
			ft_putstr(" | ");
			if (game->grid[x][y] == RED)
				ft_putchar('0');
			else if (game->grid[x][y] == BLUE)
				ft_putchar('x');
			else if (game->grid[x][y] == 0)
				ft_putchar(' ');
			y++;
		}
		ft_putstr(" |");
		drow_line(game->max_y, 0);
		x++;
	}
}

void	ft_print_winner(int winner)
{
	ft_putstr("And the winner is :");
	if (winner == BLUE)
		ft_putstr("X \n");
	if (winner == RED)
		ft_putstr("0 \n");
	if (winner == EGAL)
		ft_putstr(" egaliter\n");
}

void play(int player, t_game *game)
{
	game->player_in = player;
	if (game->player[player - 1] == 1)
		ia(player, game);
//	else
//		player_play();
}

int	main(int ac, char **av)
{
	t_game *game;
	int player = BLUE;

	if (ac != 4)
		return (0);
	game = init_game();
	init_grid(av[1], av[2], game);
	while (check_winner() == 0)
	{
		play((player = ft_vs(player)), game);
		print_grid(game);
	}
	ft_print_winner(check_winner());
	return(0);
}
