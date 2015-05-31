/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 10:06:26 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 11:25:31 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	press_quote(t_term *term)
{
	if (term->quote == 0
		&& term->hist->buff[term->hist->pose_cursor - 1] != 92)
	{
		term->quote = 1;

	}
	else if (term->quote == 1
		&& term->hist->buff[term->hist->pose_cursor - 1] != 92)
	{
		term->quote = 0;
	}
}

void	press_dquote(t_term *term)
{
	if (term->dquote == 0
		&& term->hist->buff[term->hist->pose_cursor - 1] != 92)
	{
		term->dquote = 1;
	}
	else if (term->dquote == 1
		&& term->hist->buff[term->hist->pose_cursor - 1] != 92)
	{
		term->dquote = 0;
	}
}
