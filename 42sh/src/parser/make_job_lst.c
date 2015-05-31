/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_job_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:55:15 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/04 17:01:02 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

static t_bool		is_log_ope(t_sym type)
{
	if (type == log_and)
		return (TRUE);
	if (type == log_or)
		return (TRUE);
	return (FALSE);
}

static char			test_success(t_token *token)
{
	if (token)
	{
		if (token->type == log_and)
			return (NEED_SUCCESS);
		if (token->type == log_or)
			return (NEED_NO_SUCCESS);
		else
			return (NO_CARE_SUCCESS);
	}
	return (NO_CARE_SUCCESS);
}

t_job				*make_job_lst(t_token *token_lst)
{
	t_job			*job;
	t_token			*job_token;
	char			success;

	job = NULL;
	while (token_lst)
	{
		job_token = NULL;
		while (token_lst != NULL && !is_log_ope(token_lst->type))
		{
			job_token = token_add(token_lst->str, token_lst->type, job_token);
			token_lst = token_lst->next;
		}
		success = test_success(token_lst);
		job = job_lst_add(job, job_token, success);
		if (token_lst != NULL \
				&& (token_lst->type == log_or || token_lst->type == log_and))
			token_lst = token_lst->next;
	}
	return (job);
}
