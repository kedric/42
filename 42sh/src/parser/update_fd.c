/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:48:16 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/13 13:35:00 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <fcntl.h>

t_process		*update_fd(t_token *token, t_process **current)
{
	int			fd;

	fd = 0;
	if (token->type == append)
	{
		fd = open(token->next->str, O_APPEND | O_CREAT | O_WRONLY, 0644);
		(*current)->FD_OUT = fd;
	}
	else if (token->type == redir_out)
	{
		fd = open(token->next->str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		(*current)->FD_OUT = fd;
	}
	else if (token->type == redir_in)
	{
		fd = open(token->next->str, O_RDONLY);
		(*current)->FD_IN = fd;
	}
	else if (token->type == redir_err)
	{
		fd = open(token->next->str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		(*current)->FD_ERR = fd;
	}
	return (*current);
}
