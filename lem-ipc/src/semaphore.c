/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 21:09:01 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 17:19:41 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		sem_block(t_env *env)
{
	struct sembuf	op[1];
	int				ret;

	ret = 1;
	op[0].sem_num = 0;
	op[0].sem_op = -1;
	op[0].sem_flg = 0;
	if (env->verbose)
		ft_printf("je tente le blockage\n");
	ret = semop(env->sem_id, op, 1);
	return (ret);
}

void	sem_rel(t_env *env)
{
	struct sembuf op[1];

	op[0].sem_num = 0;
	op[0].sem_op = 1;
	op[0].sem_flg = IPC_NOWAIT;
	if (env->verbose)
		ft_printf("je tente le blockage\n");
	if (semctl(env->sem_id, 0, GETVAL, 1) == 0)
		semop(env->sem_id, op, 1);
	if (env->verbose)
		ft_printf("je tente le blockage\n");
}

int		init_sem(t_env *env)
{
	if ((env->sem_id = semget(env->key, 1, IPC_CREAT | S_IRUSR | S_IWUSR)) <= 0)
	{
		ft_fprintf(2, "fail to get semaphore\n");
		exit (-1);
	}
	if (semctl(env->sem_id, 0, GETPID, 0) == 0)
		semctl(env->sem_id, 0, SETVAL, 1);
	return (1);
}

void	sem_wait(t_env *env)
{
	struct sembuf op[1];

	op[0].sem_num = 0;
	op[0].sem_op = 0;
	op[0].sem_flg = 0;
	semop(env->sem_id, op, 1);
}
