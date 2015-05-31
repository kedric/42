/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:12:47 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:12:51 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "exec.h"
#include "struct.h"
#include "error.h"
#include "command.h"

void		launch_process(t_process *p, t_gen *envp)
{
	check_redirection(p, envp);
	if ((envp->path = check_and_get_path(p->av[0], envp)) != NULL)
		execve(envp->path, p->av, envp->env);
	else
	{
		error(p, 0);
		exit(-1);
	}
}
