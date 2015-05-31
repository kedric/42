/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 22:57:23 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 17:17:59 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	clear_me(t_env *env, t_play *p)
{
	ft_printf("je meure\n");
	env->map[return_pose(env, p->init.x, p->init.y)] = 0;
	sem_rel(env);
	sem_wait(env);
	shmdt (env->mem);
	exit(0);
}

void	move_other(t_env *env, t_play *p)
{
	if (check_case(env, p->init.x, p->init.y + 1) == 0)
		init_moove(p, 2);
	else if (check_case(env, p->init.x + 1, p->init.y) == 0)
		init_moove(p, 3);
	else if (check_case(env, p->init.x, p->init.y - 1) == 0)
		init_moove(p, 4);
	else if (check_case(env, p->init.x - 1, p->init.y) == 0)
		init_moove(p, 1);
}

void	move(t_env *env, t_play *p)
{
	if (env->verbose)
		ft_printf("moove to x : %d y : %d\n", p->to_do.x, p->to_do.y);
	if (nb_enemy(env, p) >= 2)
		clear_me(env, p);
	if ((p->init.x != p->to_do.x || p->init.y != p->to_do.y)
		&& env->map[return_pose(env, p->to_do.x, p->to_do.y)] == 0)
		env->map[return_pose(env, p->init.x, p->init.y)] = 0;
	if (env->map[return_pose(env, p->to_do.x, p->to_do.y)] == 0)
	{
		env->map[return_pose(env, p->to_do.x, p->to_do.y)] = env->player_id;
		p->init.x = p->to_do.x;
		p->init.y = p->to_do.y;
	}
	else
		move_other(env, p);
}

int		ckeck_statut(t_env *env, t_play *p)
{
	return (nb_enemy(env, p));
}

int		play(t_env *env, t_play *p)
{
	if (env->verbose == 1)
		ft_printf("je joue pour la team %c\n", env->player_id);
	if (p->init.x != -1)
	{
		if (ckeck_statut(env, p) == 1)
			return (1);
		else
			search_enemy(env, p);
	}
	else
		p->init.x = p->to_do.x;
	move(env, p);
	return (1);
}
