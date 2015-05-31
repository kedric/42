/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 10:50:16 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/30 17:16:56 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	usage(char *name)
{
	ft_fprintf(2, "%s usage : %s [-v] team_id \n", name, name);
	exit(-1);
}

void	parse_av(t_env *env, char **av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if (ft_strcmp(av[i], "-v") == 0)
			env->verbose = 1;
		else if (ft_strcmp(av[i], "-x") == 0 && av[i + 1])
			env->size_x = ft_atoi(av[++i]);
		else if (ft_strcmp(av[i], "-y") == 0 && av[i + 1])
			env->size_y = ft_atoi(av[++i]);
		else if (ft_strcmp(av[i], "-g") == 0)
			graphique_mode(env);
		else if (ft_strcmp(av[i], "-s") == 0)
			env->wait = 1;
		else if (env->team_id == 0)
			env->team_id = av[i];
		else
			usage(av[0]);
	}
}

void	init_env(t_env *env, char **av)
{
	env->key = ftok(av[0], 42);
	env->verbose = 0;
	env->team_id = 0;
	env->size_mem = 0;
	env->mem = NULL;
	env->size_x = SIZE_X;
	env->size_y = SIZE_Y;
	env->brk = 1;
	env->turn = 0;
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 1)
		usage(av[0]);
	init_env(&env, av);
	parse_av(&env, av);
	if (init_memory(&env) == 1)
		clearmap(&env);
	return (0);
}
