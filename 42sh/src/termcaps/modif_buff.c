/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:23:45 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:23:51 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	fn_char_backsp(t_gen *gen, char *key)
{
	int	i;

	(void)key;
	if (gen->hist->pose_buff != 0)
	{
		tc_clean_line(gen);
		i = gen->hist->pose_buff - 1;
		while (gen->hist->buff[i])
		{
			gen->hist->buff[i] = gen->hist->buff[i + 1];
			++i;
		}
		gen->hist->len--;
		gen->hist->pose_buff--;
		ft_putstr_fd(gen->hist->buff, gen->term->fd);
		i = gen->hist->pose_buff;
		gen->hist->pose_buff = gen->hist->len;
		gen_tc_move_left(gen, gen->hist->len - i);
		gen->hist->pose_buff = i;
		gen->hist->modif = 1;
	}
	else
		ft_putstr_fd(bell, gen->term->fd);
}

void	fn_char_del(t_gen *gen, char *key)
{
	(void)key;
	if (gen->hist->pose_buff < gen->hist->len)
	{
		gen->hist->pose_buff++;
		gen_tc_move_right(gen, 1);
		fn_char_backsp(gen, NULL);
	}
}

void	init_var(int *j, int *i)
{
	*j = -1;
	*i = 0;
}

void	fn_prewrite(t_gen *gen, char *key)
{
	int	j;
	int	i;

	init_var(&j, &i);
	while (key[++j])
	{
		if ((key[i] = format_str(key[j])) != 0)
			i++;
	}
	j = -1;
	while (key[++j])
	{
		if (key[j] == '\n')
		{
			go_end(gen, NULL);
			gen->hist = save_hist(gen->hist);
			ft_putchar('\n');
			ft_parse_and_exec(gen->hist->buff, gen);
			updat_prompt(gen->ps1);
			ft_putstr(gen->ps1->aff);
			gen->hist = add_element(gen->hist);
		}
		else
			fn_write_char(gen, key[j]);
	}
}

void	fn_write_char(t_gen *gen, char key)
{
	if (gen->hist->len + 1 < BUFF_SIZE)
	{
		if (gen->hist->len == gen->hist->pose_buff)
		{
			gen->hist->buff[gen->hist->len] = key;
			gen->hist->pose_buff = gen->hist->pose_buff + 1;
			gen->hist->len = gen->hist->len + 1;
			ft_putchar_fd(key, gen->term->fd);
		}
		else
			print_in(gen, key);
		gen->hist->modif = 1;
	}
	else
		ft_putstr(bell);
}
