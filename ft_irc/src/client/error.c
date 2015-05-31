/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:01:09 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/24 12:26:46 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_error		e_i(char *file, int line)
{
	t_error	err;

	err.file = file;
	err.line = line;
	return (err);
}

int			x_int(int err, int res, char *str, t_error e)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s, %d)\n", str, e.file, e.line);
		exit (1);
	}
	return (res);
}

void		*x_void(void *err, void *res, char *str, t_error e)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s, %d)\n", str, e.file, e.line);
		exit (1);
	}
	return (res);
}
