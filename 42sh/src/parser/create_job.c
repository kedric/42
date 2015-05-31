/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:32:47 by mcassagn          #+#    #+#             */
/*   Updated: 2014/02/25 15:52:27 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

t_job			*create_job(t_token *token_lst, char need_success)
{
	t_job		*new_job;

	if (!(new_job = (t_job *)malloc(sizeof(*new_job))))
		return (NULL);
	new_job->token_lst = token_lst;
	new_job->need_success = need_success;
	new_job->next = NULL;
	new_job->prev = NULL;
	new_job->first_process = make_process_lst(new_job->token_lst);
	return (new_job);
}
