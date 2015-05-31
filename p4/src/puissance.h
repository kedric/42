/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 23:17:17 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/08 15:21:39 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H
# include "../libft/libft.h"
# define RED 1 /* y */
# define BLUE 2 /* x */
# define EGAL 100



# include <stdio.h>

typedef struct	s_game
{
	int			**grid;
	int			max_x;
	int			max_y;
	int			ia_lvl;
	int			player[2];
	int			player_in;
}				t_game;

/*
**	init_game.c
*/
t_game	*init_game(void);
void	init_grid(char *x, char *y, t_game *game);

/*
** check.c
*/
int		check_winner();

/*
** ia.c
*/
int		ft_vs(int player);
void	ia(int player, t_game *game);

/*
**
*/
#endif /* PUISSANCE_H */
