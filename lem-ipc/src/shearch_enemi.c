/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearch_enemi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:49:03 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 17:32:34 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	search_top(t_env *env, t_play *p, int *max, int *act)
{
	int i;
	int	x;
	int	y;

	i = -1;
	x = p->init.x;
	y = p->init.y;
	while (++i < p->init.x)
	{
		if (check_case(env, x - i, y) == -1)
		{
			if (i < *max || *max == 0)
			{
				if (env->verbose)
					ft_printf("enemy trouver top X: %d Y: %d\n", x - i, y);
				*max = i;
				*act = 1;
				return ;
			}
		}
	}
}

void	search_right(t_env *env, t_play *p, int *max, int *act)
{
	int i;
	int	x;
	int	y;

	i = -1;
	x = p->init.x;
	y = p->init.y;
	while (++i + y < env->mem->size_y - 1)
	{
		if (check_case(env, x, y + i) == -1)
		{
			if (i < *max || *max == 0)
			{
				if (env->verbose)
					ft_printf("enemy trouver right X: %d Y: %d\n", x, y + i);
				*max = i;
				*act = 2;
				return ;
			}
		}
	}
	return ;
}

void	search_bot(t_env *env, t_play *p, int *max, int *act)
{
	int i;
	int	x;
	int	y;

	i = -1;
	x = p->init.x;
	y = p->init.y;
	while ((++i + x) < env->mem->size_x - 1)
	{
		if (check_case(env, x + i, y) == -1)
		{
			if (i < *max || *max == 0)
			{
				if (env->verbose)
					ft_printf("enemy trouver left X: %d Y: %d\n", x + i, y);
				*max = i - 1;
				*act = 3;
				return ;
			}
		}
	}
	return ;
}

void	search_left(t_env *env, t_play *p, int *max, int *act)
{
	int i;
	int	x;
	int	y;

	i = -1;
	x = p->init.x;
	y = p->init.y;
	while (++i < y - 1)
	{
		if (check_case(env, x, y - i) == -1)
		{
			if (i < *max || *max == 0)
			{
				if (env->verbose)
					ft_printf("enemy trouver bot X: %d Y: %d\n", x, y - i);
				*max = i;
				*act = 4;
				return ;
			}
		}
	}
	return ;
}

int		search_hard(t_env *env, t_play *p)
{
	int	pose;
	int i;

	i = return_pose(env, p->init.x, p->init.y);
	pose = return_pose(env, p->init.x, p->init.y);
	while (++i < env->mem->size_x * env->mem->size_y + env->mem->size_y)
	{
		if (check_case(env, return_x(env, i), return_y(env, i)) == -1)
			break ;
		if (i - pose >= 0 && check_case(env, return_x(env, i - pose)
							, return_y(env, i - pose)) == -1)
		{
			i = pose - i;
			break ;
		}
	}
	if (i == env->mem->size_x * env->mem->size_y +
		env->mem->size_y && env->turn > 10)
	{
		if (env->init)
			return (0);
		else
			clear_me(env, p);
	}
	return (moove_to(env, p, i));
}
