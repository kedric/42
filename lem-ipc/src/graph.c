/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 17:09:44 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 18:04:26 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <curses.h>
#include <stdlib.h>

void	init_ncurse(void)
{
	initscr();
	start_color();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
}

int		refrech_game(t_env *env)
{
	int		i;
	int		j;
	int		pos;

	sem_block(env);
	i = -1;
	while (++i <= env->mem->size_x)
	{
		j = 0;
		while (j < env->mem->size_y)
		{
			pos = return_pose(env, i, j);
			if (env->map[pos] != 0)
				mvprintw(i, j, "%c", env->map[pos]);
			else
				mvprintw(i, j, "%c", '*');
			j++;
		}
	}
	refresh();
	return (1);
}

void	init_graph(t_env *env)
{
	int size;

	size = 0;
	if ((env->seg_id = shmget (env->key, sizeof(t_mem),
		IPC_EXCL | S_IRUSR | S_IWUSR)) != -1)
	{
		env->sem_id = semget(env->key, 1, S_IRUSR | S_IWUSR);
		env->mem = (t_mem *)shmat (env->seg_id, 0, 0);
		size = env->mem->size;
		shmdt (env->mem);
		if ((env->seg_id = shmget (env->key, size,
					IPC_EXCL | S_IRUSR | S_IWUSR)) == -1)
			ft_fprintf(2, "fail to read memory\n");
		env->mem = (t_mem *)shmat (env->seg_id, 0, 0);
		env->map = (char *)env->mem + sizeof(t_mem) + 1;
	}
	else
	{
		endwin();
		ft_fprintf(2, "please init player brefor\n");
		exit(0);
	}
}

void	graphique_mode(t_env *env)
{
	init_ncurse();
	init_sem(env);
	init_graph(env);
	while (getch() != 10)
		;
	send_start(env);
	sem_block(env);
	sem_rel(env);
	sem_wait(env);
	while (refrech_game(env) != 125 && env->mem->start)
	{
		if (env->wait == 1)
		{
			env->mem->start = 0;
			usleep(50000);
			env->mem->start = 1;
		}
		sem_rel(env);
		sem_wait(env);
	}
	sem_rel(env);
	sem_wait(env);
	endwin();
	exit(0);
}
