/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exp2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:32:04 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/12 14:32:28 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			check_background(t_token *token_lst)
{
	if (token_lst->type == bg)
	{
		if (token_lst->next)
			return (check_exp(token_lst->next));
		return (TRUE);
	}
	return (parse_error(token_lst->str));
}

t_bool			check_logical(t_token *token_lst)
{
	if (token_lst->type == log_and \
			|| token_lst->type == log_or)
	{
		if (token_lst->next)
			return (check_exp(token_lst->next));
		else
			return (parse_error(token_lst->str));
	}
	return (parse_error(token_lst->str));
}
