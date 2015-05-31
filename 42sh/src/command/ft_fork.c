/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:11:59 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:12:01 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "libft.h"
#include "command.h"
#include "builtin.h"
#include "error.h"
#include <sys/wait.h>
#include <sys/types.h>

void		ft_forkerror(t_process *p, t_gen *env)
{
	env->ret = ENFORK;
	error(p, 0);
}

void		ft_fork(t_process *p, t_gen *env)
{
	if (ft_checkbuiltin(p, env) == 1)
		env->status = ft_run_builtin(p, env);
	else
	{
		env->pid_fork = 0;
		env->pid_fork = fork();
		if (env->pid_fork == 0)
			launch_process(p, env);
		else if (env->pid_fork < 0)
		{
			ft_forkerror(p, env);
			exit(1);
		}
		else
		{
			if ((waitpid(env->pid_fork, &(env->status), 0)) == -1)
			{
				env->ret = EEXECV;
				error(p, 0);
			}
		}
	}
	if (env->path != NULL)
		free(env->path);
}
