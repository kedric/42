/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:47:51 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/04 16:49:30 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

void			command_lst_free(t_command *command_lst)
{
	t_command	*curr;
	t_command	*to_free;

	curr = command_lst;
	while (curr)
	{
		to_free = curr;
		curr = curr->next;
		job_lst_free(to_free->first_job);
		to_free->first_job = NULL;
		token_lst_free(&(to_free->token_lst));
		to_free->background = 0;
		to_free->next = NULL;
		to_free->prev = NULL;
		free(to_free);
		to_free = NULL;
	}
	command_lst = NULL;
}
