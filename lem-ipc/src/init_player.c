/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 14:15:40 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 17:47:10 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		player(t_env *env)
{
	t_play	p;

	ft_printf("je suis dans player\n");
	env->sem_id = semget(env->key, 1, S_IRUSR | S_IWUSR);
	sem_block(env);
	ft_printf("j ais recupe env->sem_id\n");
	init_client(env, env->seg_id, &p);
	init_team(env);
	sem_rel(env);
	while (env->mem->start == 0)
		sem_wait(env);
	while (env->mem->start == 1)
	{
		ft_printf("je block apres\n");
		sem_block(env);
		ft_printf("j ais blocker\n");
		play(env, &p);
		sem_rel(env);
		env->turn++;
		sem_wait(env);
	}
	env->mem->team_nb--;
}

char		return_char(t_env *env)
{
	char	c;
	char	*pat;

	pat = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	c = pat[env->mem->team_max - 1];
	return (c);
}

int			init_team(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->mem->team_nb)
	{
		if (!ft_strcmp(env->team_id, env->mem->team[i].name))
			break ;
		i++;
	}
	if (i == env->mem->team_nb)
	{
		env->mem->team_max++;
		env->mem->team[i].id = return_char(env);
		env->player_id = return_char(env);
		ft_strcat(env->mem->team[i].name, env->team_id);
		env->mem->team[i].nb_player = 0;
	}
	else
		env->player_id = env->mem->team[i].id;
	env->mem->team[i].nb_player++;
	return (1);
}
