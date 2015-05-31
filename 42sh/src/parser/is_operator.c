/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 12:43:05 by mcassagn          #+#    #+#             */
/*   Updated: 2014/02/26 17:24:21 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_sym			is_redir_operator(char *str)
{
	if (str[0] == '2' && str[1] == '>')
		return (redir_err);
	if (str[0] == '>' && str[1] == '>')
		return (append);
	if (str[0] == '>')
		return (redir_out);
	if (str[0] == '<')
		return (redir_in);
	return (unknown);
}

t_sym			is_separator(char *str)
{
	if (str[0] == ';')
		return (colon);
	return (unknown);
}

t_sym			is_background_operator(char *str)
{
	if (str[0] == '&')
		return (bg);
	return (unknown);
}

t_sym			is_logical_operator(char *str)
{
	if (str[0] == '|' && str[1] == '|')
		return (log_or);
	if (str[0] == '&' && str[1] == '&')
		return (log_and);
	return (unknown);
}

t_sym			is_operator(char *str)
{
	t_sym		type;

	if ((type = is_logical_operator(str)) != unknown)
		return (type);
	if (str[0] == '|' && str[1] != '|')
		return (pipes);
	if ((type = is_redir_operator(str)) != unknown)
		return (type);
	if ((type = is_separator(str)) != unknown)
		return (type);
	if ((type = is_background_operator(str)) != unknown)
		return (type);
	return (unknown);
}
