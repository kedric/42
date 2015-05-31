/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 12:52:01 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 17:13:01 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "parser.h"
#include "struct.h"
#include "sh.h"

char	*strror2(int i)
{
	if (i == ENOCMD)
		return ("command not found");
	else if (i == EBPIPE)
		return ("broken pipe");
	else if (i == EBDENV)
		return ("env error");
	else if (i == EEXECV)
		return ("error execve");
	return ("unknown error");
}

char	*strror(int i)
{
	if (i == EALLOC)
		return ("malloc error");
	else if (i == E2BIGA)
		return ("too many arguments");
	else if (i == ENOARG)
		return ("missing argument");
	else if (i == ENPERM)
		return ("permission denied");
	else if (i == ENENTR)
		return ("no such a file or directory");
	else if (i == EISHER)
		return ("file already exists");
	else if (i == EBADFD)
		return ("bad file descriptor");
	else if (i == ENFORK)
		return ("fork error");
	else if (i == ENODIR)
		return ("not a directory");
	else if (i == EDIRIS)
		return ("is a directory");
	else if (i == EINVAR)
		return ("wrong type of argument");
	else
		return (strror2(i));
}

void	error(t_process *job, int i)
{
	t_gen	*gen;

	gen = recup_gen();
	if (i > 0)
		ft_dprintf(2, "%s: %s: %s\n", job->av[0], job->av[i], strror(gen->ret));
	else
		ft_dprintf(2, "%s: %s\n", job->av[0], strror(gen->ret));
}
