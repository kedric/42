/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 11:40:14 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 18:09:24 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <stdlib.h>
# include <sys/ipc.h>
# include <sys/sem.h>
# include <sys/shm.h>
# include <sys/stat.h>
# include <sys/msg.h>
# include <time.h>

# define SIZE_X 25
# define SIZE_Y 25
# define BLK 1
# define N_BLK 0
# define WAIT 0
# define MOOVE 1

typedef struct s_map	t_map;

struct					s_map
{
	int					player;
	t_map				*up;
	t_map				*down;
	t_map				*right;
	t_map				*left;
}						;

typedef struct			s_team
{
	char				id;
	char				name[60];
	char				nb_player;
}						t_team;

typedef struct			s_mem
{
	int					start;
	int					team_nb;
	int					team_max;
	t_team				team[700];
	int					size;
	int					size_x;
	int					size_y;
}						t_mem;

typedef struct			s_env
{
	int					verbose;
	char				*team_id;
	key_t				key;
	int					size_x;
	int					size_y;
	int					seg_id;
	size_t				turn;
	size_t				size_mem;
	char				*map;
	int					sem_id;
	t_mem				*mem;
	char				player_id;
	int					wait;
	int					brk;
	int					init;
}						t_env;

typedef struct			s_move
{
	int					x;
	int					y;
}						t_move;

typedef struct			s_play
{
	t_move				init;
	t_move				to_do;
	int					etats;
}						t_play;

struct					s_msgbuf
{
	long				mtype;
	char				mtext[1];
};

int						init_memory(t_env *env);
void					graphique_mode(t_env *env);
void					clearmap(t_env *env);
void					send_start(t_env *env);

/*
** semaphore.c
** lock = 1;
** unlock = 0;
*/
int						init_sem(t_env *env);
int						sem_block(t_env *env);
void					sem_rel(t_env *env);
void					sem_wait(t_env *env);

/*
** player
*/
void					player(t_env *env);
int						play(t_env *env, t_play *p);
int						init_team(t_env *env);
int						search_enemy(t_env *env, t_play *p);
int						return_x(t_env *env, int pose);
int						return_y(t_env *env, int pose);
int						return_pose(t_env *env, int x, int y);
int						nb_enemy(t_env *env, t_play *p);
int						check_case(t_env *env, int x, int y);
void					init_moove(t_play *p, int act);
void					clear_me(t_env *env, t_play *p);
void					search_left(t_env *env, t_play *p, int *max, int *act);
void					search_bot(t_env *env, t_play *p, int *max, int *act);
void					search_right(t_env *env, t_play *p, int *max, int *act);
void					search_top(t_env *env, t_play *p, int *max, int *act);
int						search_hard(t_env *env, t_play *p);
void					close_connection(t_env *env, t_play *p);
int						moove_to(t_env *env, t_play *p, int pose);
int						creat_map(t_env *env, int seg_id);
void					init_client(t_env *env, int seg_id, t_play *p);

#endif

