/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:38:56 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 16:57:44 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

static t_process	*get_last_process(t_process *process_lst)
{
	t_process		*lst;

	lst = process_lst;
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static char			is_ok_redir(t_token *token)
{
	if (token->type == redir_in || token->type == redir_out
			|| token->type == append || token->type == redir_err)
	{
		if (token->next && token->next->type == redir_dest)
		{
			return (1);
		}
	}
	return (0);
}

static char			check_state(t_token *token)
{
	if (token->prev && token->prev->type == word)
	{
		if (token->next->next && is_ok_redir(token->next->next))
			return (2);
		return (1);
	}
	else if (token->next->next && token->next->next->type == word)
	{
		if (token->next->next->next && is_ok_redir(token->next->next->next))
			return (4);
		return (3);
	}
	else if (token->next->next && is_ok_redir(token->next->next))
	{
		if (token->next->next->next->next
				&& token->next->next->next->next->type == word)
			return (5);
		return (6);
	}
	return (7);
}

static void			do_redir(t_token **token, t_process **current,
							t_process **process)
{
	char			state;

	state = check_state(*token);
	if (state == 3 || state == 4)
		*process = process_lst_add(*process, (*token)->next->next->str);
	else if (state == 5)
		*process = process_lst_add(*process,
				(*token)->next->next->next->next->str);
	else if (state == 6 || state == 7)
		*process = process_lst_add(*process, "cat");
	*current = get_last_process(*process);
	*current = update_fd(*token, current);
	if (state == 2 || state == 6 || state == 5 || state == 3)
		*token = (*token)->next->next;
	else if (state == 4)
		*token = (*token)->next->next->next;
	if (state == 2 || state == 6 || state == 5 || state == 4)
		*current = update_fd(*token, current);
	if (state == 5)
		*token = (*token)->next;
	*token = ((*token)->next) ? (*token)->next->next : (*token)->next;
}

t_process			*make_process_lst(t_token *token)
{
	t_process		*process;
	t_process		*current;

	process = NULL;
	current = NULL;
	while (token)
	{
		if (token->type == word)
		{
			process = process_lst_add(process, token->str);
			token = token->next;
		}
		else if (is_ok_redir(token))
			do_redir(&token, &current, &process);
		else if (token->type == pipes)
			token = token->next;
	}
	return (process);
}
