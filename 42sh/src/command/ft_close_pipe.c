/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:11:45 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:11:47 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"

void		ft_close_pipe(t_process *p)
{
	if (STDIN_FILENO != p->FD_IN)
		close(p->FD_IN);
	if (STDERR_FILENO != p->FD_ERR)
		close(p->FD_ERR);
	if (STDOUT_FILENO != p->FD_OUT)
		close(p->FD_OUT);
}
