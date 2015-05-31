/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:48:50 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/04 16:48:59 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <unistd.h>

t_bool		parse_error(char *str)
{
	if (!write(STDOUT_FILENO, "Parse error near '", 18))
		return (FALSE);
	ft_putstr(str);
	if (!write(STDOUT_FILENO, "'.\n", 3))
		return (FALSE);
	return (FALSE);
}
