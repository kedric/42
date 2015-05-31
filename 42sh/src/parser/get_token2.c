/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:33:17 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 19:16:10 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

t_token			*create_token(void)
{
	t_token		*new;

	if (!(new = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	new->str = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->type = unknown;
	return (new);
}

t_sym			get_token_type(char *str)
{
	t_sym		type;

	if ((type = is_operator(str)) != unknown)
		return (type);
	if ((type = is_word(str)) != unknown)
		return (type);
	return (unknown);
}
