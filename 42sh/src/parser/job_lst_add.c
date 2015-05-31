/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_lst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 14:17:35 by mcassagn          #+#    #+#             */
/*   Updated: 2014/02/22 14:58:41 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_job				*job_lst_add(t_job *lst, t_token *token_lst, \
									char need_success)
{
	t_job			*new_job;
	t_job			*current;

	if (!(new_job = create_job(token_lst, need_success)))
		return (NULL);
	if (!lst)
		return (new_job);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new_job;
	new_job->prev = current;
	return (lst);
}
