/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:41:19 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/26 02:57:18 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			check_colon(t_token *token_lst)
{
	if (token_lst->type == colon)
	{
		if (token_lst->next)
			return (check_exp(token_lst->next));
		return (TRUE);
	}
	return (parse_error(token_lst->str));
}

t_bool			check_pipe(t_token *token_lst)
{
	if (token_lst->type == pipes)
	{
		if (token_lst->next)
			return (check_exp(token_lst->next));
		return (parse_error(token_lst->str));
	}
	return (parse_error(token_lst->str));
}

t_bool			check_redir(t_token *token_lst)
{
	if (token_lst->type != pipes
			&& is_redir_operator(token_lst->str) != unknown)
	{
		if (token_lst->next && token_lst->next->type == redir_dest)
		{
			if (token_lst->next->next)
			{
				if (token_lst->next->next->type == pipes)
					return (check_pipe(token_lst->next->next));
				else if (token_lst->next->next->type == colon)
					return (check_colon(token_lst->next->next));
				else if (token_lst->next->next->type == log_and
						|| token_lst->next->next->type == log_or)
					return (check_logical(token_lst->next->next));
				else if (token_lst->next->next->type == bg)
					return (check_background(token_lst->next->next));
			}
			return (TRUE);
		}
		return (parse_error(token_lst->str));
	}
	return (parse_error(token_lst->str));
}

t_bool			check_command(t_token *token_lst)
{
	if (token_lst->type == word)
	{
		if (token_lst->next)
		{
			if (token_lst->next->type == pipes)
				return (check_pipe(token_lst->next));
			else if (is_redir_operator(token_lst->next->str) != unknown)
				return (check_redir(token_lst->next));
			else if (token_lst->next->type == colon)
				return (check_colon(token_lst->next));
			else if (token_lst->next->type == log_or
					|| token_lst->next->type == log_and)
				return (check_logical(token_lst->next));
			else if (token_lst->next->type == bg)
				return (check_background(token_lst->next));
			return (parse_error(token_lst->str));
		}
		return (TRUE);
	}
	else
		return (parse_error(token_lst->str));
}

t_bool			check_exp(t_token *token_lst)
{
	if (token_lst)
	{
		if (token_lst->type == word)
			return (check_command(token_lst));
		else if (token_lst->type == redir_in \
				|| token_lst->type == redir_out \
				|| token_lst->type == redir_err \
				|| token_lst->type == append)
			return (check_redir(token_lst));
		else if (token_lst->type == colon)
			return (check_colon(token_lst));
	}
	return (parse_error(token_lst->str));
}
