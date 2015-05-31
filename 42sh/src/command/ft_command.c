/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:20:30 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:20:35 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "parser.h"
#include "exec.h"
#include "libft.h"
#include "command.h"

#define COM_SUCCESS 0
#define COM_NO_SUCCESS 256
#define COM_NO_FIND 65280

void		ft_command(t_command *com, t_gen *env)
{
	t_command	*tmp;
	t_job		*job;

	tmp = com;
	while (tmp != NULL)
	{
		job = tmp->first_job;
		while (job)
		{
			launch_job(job, env);
			if (env->status == 256 && job->need_success == NEED_SUCCESS)
				job = get_job_next(job, NEED_NO_SUCCESS);
			else if (env->status == 0 && job->need_success == NEED_SUCCESS)
				job = job->next;
			else if ((env->status == 256 || env->status == 65280)
					&& job->need_success == NEED_NO_SUCCESS)
				job = job->next;
			else if (env->status == 0 && job->need_success == NEED_NO_SUCCESS)
				job = get_job_next(job, NEED_SUCCESS);
			else if (job->need_success == NO_CARE_SUCCESS)
				job = job->next;
		}
		tmp = tmp->next;
	}
}

t_job		*get_job_next(t_job *job, int success)
{
	t_job	*tmp;

	tmp = job;
	while (tmp != NULL)
	{
		if (tmp->need_success == success)
		{
			tmp = tmp->next;
			break ;
		}
		tmp = tmp->next;
	}
	return (tmp);
}
