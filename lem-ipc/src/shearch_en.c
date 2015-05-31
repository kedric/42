/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearch_en.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 17:28:51 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 17:36:30 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		search_team(t_env *env)
{
	int		i;
	int		max;
	char	c;
	int		total;

	c = 0;
	total = 0;
	i = 0;
	max = env->mem->size_x * env->mem->size_y + env->mem->size_y;
	while (i < max)
	{
		if (check_case(env, return_x(env, i), return_y(env, i)) == -1)
		{
			if (c == 0)
				c = env->map[i];
			else if (c != env->map[i])
				total++;
			else if (c != env->map[i] && total > 2)
				return (1);
		}
		i++;
	}
	return (0);
}

void	close_connection(t_env *env, t_play *p)
{
	while (env->init && search_team(env))
	{
		sem_rel(env);
		sem_wait(env);
		sem_block(env);
	}
	if (env->init)
	{
		clearmap(env);
		exit(0);
	}
	env->map[return_pose(env, p->init.x, p->init.y)] = 0;
	shmdt (env->mem);
}

void	init_moove(t_play *p, int act)
{
	if (act == 1)
		p->to_do.x = p->init.x - 1;
	else if (act == 2)
		p->to_do.y = p->init.y + 1;
	else if (act == 3)
		p->to_do.x = p->init.x + 1;
	else if (act == 4)
		p->to_do.y = p->init.y - 1;
	else
		ft_printf("rien a faire\n");
}

int		moove_to(t_env *env, t_play *p, int pose)
{
	int	i;
	int j;

	i = 0;
	if (return_x(env, pose) > p->init.x)
		i++;
	if (return_y(env, pose) > p->init.y)
		i++;
	if (i == 2)
		return ((rand() % 2 == 0) ? 3 : 2);
	j = (i == 0) ? 1 : 0;
	if (return_x(env, pose) < p->init.x)
		i++;
	if (i == 2)
		return ((rand() % 2 == 0) ? 1 : 2);
	if (return_y(env, pose) < p->init.y)
		i++;
	if (i == 2)
	{
		if (j == 0)
			return ((rand() % 2 == 0) ? 3 : 4);
		else
			return ((rand() % 2 == 0) ? 1 : 4);
	}
	return (1);
}
