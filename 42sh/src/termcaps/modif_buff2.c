/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_buff2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:23:38 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:23:43 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	format_str(char key)
{
	if (ft_isprint(key) || key == '\n')
	{
		if (key == '\t')
			return (32);
		return (key);
	}
	return (0);
}

void	print_in(t_gen *gen, char k)
{
	char	*tmp;
	int		i;
	char	key[2];

	key[0] = k;
	key[1] = '\0';
	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	ft_bzero(tmp, BUFF_SIZE);
	ft_strncat(tmp, gen->hist->buff, gen->hist->pose_buff);
	ft_strcat(tmp, key);
	ft_strcat(tmp, gen->hist->buff + gen->hist->pose_buff);
	ft_memcpy(gen->hist->buff, tmp, BUFF_SIZE);
	free(tmp);
	tc_clean_line(gen);
	gen->hist->pose_buff++;
	gen->hist->len++;
	ft_putstr_fd(gen->hist->buff, gen->term->fd);
	i = gen->hist->pose_buff;
	gen->hist->pose_buff = gen->hist->len;
	gen_tc_move_left(gen, gen->hist->len - i);
	gen->hist->pose_buff = i;
}
