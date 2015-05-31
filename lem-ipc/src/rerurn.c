/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerurn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:06:35 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 17:18:30 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int	check_case(t_env *env, int x, int y)
{
	if (x >= env->mem->size_x || y >= env->mem->size_y || x < 0 || y < 0)
		return (-2);
	if (env->map[return_pose(env, x, y)] == env->player_id)
		return (1);
	else if (env->map[return_pose(env, x, y)] == 0)
		return (0);
	else
		return (-1);
}

int	return_x(t_env *env, int pose)
{
	return (pose / env->size_y);
}

int	return_y(t_env *env, int pose)
{
	return (pose % env->size_y);
}

int	return_pose(t_env *env, int x, int y)
{
	if (x > env->mem->size_x || x < 0)
	{
		ft_printf("invalide position X %d\n", x);
		if (x < 0)
			x = 0;
		if (x > env->mem->size_x)
			x = env->mem->size_x - 1;
	}
	if (y > env->mem->size_y || y < 0)
	{
		ft_printf("invalide position Y %d\n", y);
		if (x < 0)
			y = 0;
		if (y > env->mem->size_y)
			y = env->mem->size_y - 1;
	}
	return (x * env->mem->size_y + y + 1);
}

int	nb_enemy(t_env *env, t_play *p)
{
	int	nb_e;

	nb_e = 0;
	nb_e = (check_case(env, p->init.x + 1, p->init.y) == -1) ? nb_e + 1 : nb_e;
	nb_e = (check_case(env, p->init.x - 1, p->init.y) == -1) ? nb_e + 1 : nb_e;
	nb_e = (check_case(env, p->init.x, p->init.y + 1) == -1) ? nb_e + 1 : nb_e;
	nb_e = (check_case(env, p->init.x, p->init.y - 1) == -1) ? nb_e + 1 : nb_e;
	return (nb_e);
}
