/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:22:38 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:22:43 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtin.h"

void				free_gen(void)
{
	t_gen			*gen;

	gen = recup_gen();
	free(gen);
	gen = NULL;
}

t_gen				*recup_gen(void)
{
	static t_gen	*gen = NULL;

	if (gen == NULL)
	{
		gen = (t_gen *)malloc(sizeof(t_gen));
		gen->ps1 = (t_ps1 *)malloc(sizeof(t_ps1));
		gen->term = (t_term *)malloc(sizeof(t_term));
		gen->term->key = NULL;
		gen->hist = NULL;
		gen->ps1->aff = NULL;
		gen->ps1->env = NULL;
		gen->ps1->len = 0;
		gen->path = NULL;
		gen->ret = 0;
		gen->builtin = NULL;
		gen->env = NULL;
		gen->env_orig = NULL;
		gen->pid_fork = 1;
	}
	return (gen);
}

char				*ft_getenv(char *to_search)
{
	t_gen			*gen;
	int				i;

	gen = recup_gen();
	i = 0;
	if (gen->env)
	{
		while (gen->env[i])
		{
			if (!ft_strncmp(gen->env[i], to_search, ft_strlen(to_search)))
				break ;
			i++;
		}
		if (!gen->env[i])
			return (NULL);
	}
	else
		return (NULL);
	return (gen->env[i] + ft_strlen(to_search));
}

void				init_env(char **env)
{
	t_gen			*gen;
	int				i;

	i = 0;
	gen = recup_gen();
	if (!env || env[0] == NULL)
	{
		ft_putstr_fd("env NULL please retry\n", 2);
		exit(0);
	}
	else
		gen->env_orig = env;
	while (gen->env_orig[i])
		i++;
	gen->env = (char **)malloc(sizeof(char *) * (i + 1));
	gen->env[i] = NULL;
	while (--i >= 0)
		gen->env[i] = ft_strdup(gen->env_orig[i]);
}
