/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 17:42:54 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 18:08:55 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	init_client(t_env *env, int seg_id, t_play *p)
{
	int	size;

	env->mem = (t_mem *)shmat (seg_id, 0, 0);
	env->mem->team_nb++;
	size = env->mem->size;
	shmdt (env->mem);
	if ((seg_id = shmget (env->key, size,
					IPC_EXCL | S_IRUSR | S_IWUSR)) == -1)
		ft_fprintf(2, "fail to read memory\n");
	env->mem = (t_mem *)shmat (seg_id, 0, 0);
	if (env->verbose == 1)
		ft_printf ("memoire partagee reattachee a l'adresse %p\n", env->mem);
	env->map = (char *)env->mem + sizeof(t_mem) + 1;
	srand(time(NULL));
	p->init.x = -1;
	p->init.y = 0;
	p->to_do.x = rand() % env->mem->size_x;
	p->to_do.y = rand() % env->mem->size_y;
	p->init.y = p->to_do.y;
}

int		search_enemy(t_env *env, t_play *p)
{
	int	max;
	int	act;

	act = 0;
	max = 0;
	ft_printf("je cherche un enemy\n");
	search_right(env, p, &max, &act);
	search_top(env, p, &max, &act);
	search_left(env, p, &max, &act);
	search_bot(env, p, &max, &act);
	if (max == 0 && 0 == (act = search_hard(env, p)))
		close_connection(env, p);
	else
		init_moove(p, act);
	return (0);
}

int		creat_map(t_env *env, int seg_id)
{
	env->mem = (t_mem *)shmat (seg_id, 0, 0);
	ft_bzero(env->mem, env->size_mem);
	env->mem->size = env->size_mem;
	env->mem->team_nb = -1;
	env->mem->size_x = env->size_x;
	env->mem->size_y = env->size_y;
	env->mem->start = 0;
	if (env->verbose == 1)
		ft_printf("seg_id = %d size : %d memoire adresse %p\n",
		seg_id, env->mem->size, env->mem);
	env->map = (char *)env->mem + sizeof(t_mem) + 1;
	ft_bzero(env->map, env->size_y * env->size_x);
	return (1);
}
