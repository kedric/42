/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:56:48 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 17:48:42 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct.h"
#include "sh.h"
#include "parser.h"
#include "error.h"

void		ft_dohist(t_process *p, char **com, int name, int reverse, int clear)
{
	t_gen	*env;
	int		i;

	env = recup_gen();
	if (clear == 1)
	{
		//ft_clearhist(env);
		return ;
	}
	//if (ft_checkishist(com, env) == -1)
	//	return ;
	i = (reverse == 1) ? ft_strstrlen(com) - 1 : 0;
	while (i > -1 && com[i])
	{
		if (name == 1)
			ft_dprintf(p->FD_OUT, "%s\n", "print le nom de la ligne");
		else
			ft_dprintf(p->FD_OUT, "%s\t%s\n", "print le num", "print le nom");
		i = (reverse == 1) ? i-- : i++;
	}
}

void		ft_history(t_process *p, t_gen *env)
{
	int	reverse;
	int	name;
	int	i;
	int	j;
	int	clear;

	i = 0;
	while (p->av[++i] && p->av[i][0] == '-')
	{
		j = 0;
		while (p->av[i][++j])
		{
		
			name = (p->av[i][j] == 'n' || name == 1) ? 1 : 0;
			reverse = (p->av[i][j] == 'r' || reverse == 1) ? 1 : 0;
			clear = (p->av[i][j] == 'p' || clear == 1) ? 1 : 0;
			if (p->av[i][j] != 'r' && p->av[i][j] != 'n' && p->av[i][j] != 'p')
			{
				env->ret = EBDOPT;
				ft_dprintf(2, "history: -%c: bad option", p->av[i][j]);
				return ;
			}
		}
	}
	ft_dohist(p, &(p->av[i]), name, reverse, clear);
}
