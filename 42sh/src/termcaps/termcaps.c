/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:24:36 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:24:40 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			fn_return(t_gen *gen, char *buff)
{
	(void)buff;
	gen->term->wait = 0;
}

void			tc_call_fn(t_gen *gen, char *line, enum e_key key)
{
	static t_fn	*fn[K_REGULAR + 1] =

	{
	&fn_return,
	&fn_curs_left,
	&fn_curs_down,
	&fn_curs_up,
	&fn_curs_right,
	&fn_char_backsp,
	&fn_char_del,
	&go_end,
	&go_start,
	&go_kill,
	&clear,
	&fn_prewrite
	};
	(*fn[key])(gen, line);
}

int				tc_search_key(char *buff, char **keyref)
{
	int	i;

	i = 0;
	while (i < K_REGULAR)
	{
		if (!ft_strcmp(buff, keyref[i]))
			return (i);
		++i;
	}
	return (K_REGULAR);
}

int				tc_get_key(char *buff)
{
	static char	*keyref[K_REGULAR + 1] = {NULL};

	if (keyref[0] == NULL)
	{
		keyref[K_ENTER] = key_to_str('\n', 0, 0, 0);
		keyref[K_LEFT] = tgetstr("kl", NULL);
		keyref[K_DOWN] = tgetstr("kd", NULL);
		keyref[K_UP] = tgetstr("ku", NULL);
		keyref[K_RIGHT] = tgetstr("kr", NULL);
		keyref[K_BACKSP] = tgetstr("kb", NULL);
		keyref[K_DEL] = tgetstr("kD", NULL);
		keyref[K_END] = key_to_str(5, 0, 0, 0);
		keyref[K_START] = key_to_str(1, 0, 0, 0);
		keyref[K_KILL] = key_to_str(4, 0, 0, 0);
		keyref[K_CL] = key_to_str(12, 0, 0, 0);
		keyref[K_REGULAR] = NULL;
	}
	return (tc_search_key(buff, keyref));
}

void			tc_stomp(char *buff, t_gen *gen)
{
	int			key;

	key = tc_get_key(buff);
	tc_call_fn(gen, buff, key);
}
