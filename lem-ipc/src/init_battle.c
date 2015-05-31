/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_battle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:29:59 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 18:03:03 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	wait_start(t_env *env)
{
	int				msg_id;
	struct s_msgbuf	buff;
	int				i;

	msg_id = msgget(env->key, IPC_CREAT | S_IRUSR | S_IWUSR);
	buff.mtext[0] = 'a';
	i = -1;
	while (++i < 700)
	{
		env->mem->team[i].id = 0;
		env->mem->team[i].nb_player = 0;
		ft_bzero(env->mem->team[i].name, 60);
	}
	sem_rel(env);
	msgrcv(msg_id, &buff, 1, 0, 0);
	env->mem->start = 1;
	shmdt (env->mem);
	msgctl (msg_id, IPC_RMID, 0);
}

void	send_start(t_env *env)
{
	int					msg_id;
	struct s_msgbuf		buff;

	msg_id = msgget(env->key, IPC_CREAT | S_IRUSR | S_IWUSR);
	buff.mtext[0] = 'a';
	msgsnd(msg_id, &buff, 1, 0);
}

int		init_memory(t_env *env)
{
	env->mem = NULL;
	env->size_mem = sizeof(t_mem) + (sizeof(char)
		* (env->size_x * env->size_y));
	if ((env->seg_id = shmget (env->key, env->size_mem, IPC_CREAT | IPC_EXCL
	| S_IRUSR | S_IWUSR)) != -1)
	{
		env->init = 1;
		ft_printf("jentre\n");
		init_sem(env);
		creat_map(env, env->seg_id);
		wait_start(env);
		while (1)
			player(env);
	}
	else if ((env->seg_id = shmget (env->key, sizeof(t_mem),
		IPC_EXCL | S_IRUSR | S_IWUSR)) != -1)
	{
		env->init = 0;
		while (1)
			player(env);
	}
	else
		ft_fprintf(2, "fail to alloc memory\n");
	return (1);
}

void	clearmap(t_env *env)
{
	env->mem->start = 0;
	sem_rel(env);
	sem_wait(env);
	sem_block(env);
	sem_rel(env);
	sem_block(env);
	shmdt (env->mem);
	shmctl (env->seg_id, IPC_RMID, 0);
	semctl (env->sem_id, IPC_RMID, 0);
	ft_putstr("netoyer\n");
}
