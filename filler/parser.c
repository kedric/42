/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 10:18:55 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/25 11:34:25 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_ratache(char *ret, t_plt *plt)
{
	char *join;

	while(plt->next)
		plt = plt->next;
	join = ft_strjoin(plt->value, ret);
	free(plt->value);
	plt->value = join;
	free(ret);
}

t_plt	*ft_creat_lst(char *ret, t_plt *plt)
{
	t_plt *tmp;
	t_plt *start;

	tmp = (t_plt *)malloc(sizeof(t_plt));
	tmp->value = ret;
	tmp->pos = 1;
	if (plt == NULL)
		return (tmp);
	start = plt;

	while (plt->next)
	{
		plt = plt->next;
		tmp->pos++;
	}
	plt->next = tmp;
	return (start);
}

t_plt	*push_to_lst(char *buff, t_plt *plt, int rat)
{
	int i;
	char	**ret;

	i = 0;
	ret = ft_strsplit(buff, '\n');
	if (rat == 1)
		ft_ratache(ret[i++], plt);
	while (ret[i])
	{
		plt = ft_creat_lst(ret[i], plt);
		i++;
	}
	free(ret);
	return (plt);
}

t_plt	*parse_enter(void)
{
	char	*buff;
	int		ret;
	t_plt	*plt;
	int		rat;

	rat = 0;
	plt = NULL;
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((ret = read(0, buff, BUFF_SIZE)) != 0)
	{

		buff[ret] = '\0';
		plt = push_to_lst(buff, plt, rat);
		if (buff[ret - 1] != '\n')
			rat = 1;
		else
			rat = 0;
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	return (plt);
}
