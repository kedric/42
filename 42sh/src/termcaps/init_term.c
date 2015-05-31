/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:23:25 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:23:30 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*key_to_str(int a, int b, int c, int d)
{
	char	*key;

	if (!(key = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	ft_memset(key, 0, 5);
	key[0] = a;
	key[1] = b;
	key[2] = c;
	key[3] = d;
	key[4] = '\0';
	return (key);
}

void	init_term(void)
{
	t_gen	*gen;
	char	buff[2024];
	char	*termtype;
	int		ret;
	char	*term;

	term = (ft_strncmp(ft_getenv("TERM_PROGRAM="), "iTerm.app", 5) == 0) \
			? "linux" : ft_getenv("TERM=");
	gen = recup_gen();
	if ((termtype = term) == 0)
		ft_puterr("term not found in env");
	if ((ret = tgetent(buff, termtype)) < 1)
		ft_puterr("no acces termtype");
	tcgetattr(0, &gen->term->term_ori);
	ft_memcpy(&gen->term->term, &gen->term->term_ori, sizeof(struct termios));
	gen->term->term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, 0, &gen->term->term);
}

void	close_term(void)
{
	t_gen	*gen;

	gen = recup_gen();
	tcsetattr(0, 0, &gen->term->term_ori);
}

void	init_sig(void)
{
	signal(SIGINT, ft_sig_int);
	signal(SIGTSTP, ft_sig_tstp);
}

void	clear(t_gen *gen, char *buff)
{
	(void)buff;
	ft_putstr_fd(tgetstr("cl", NULL), gen->term->fd);
	ft_putstr(gen->ps1->aff);
	while (gen->hist->next)
		gen->hist = gen->hist->next;
	ft_bzero(gen->hist->buff, BUFF_SIZE);
	gen->hist->pose_buff = 0;
	gen->hist->len = 0;
	gen->hist->modif = 0;
	ft_bzero(gen->hist->value, BUFF_SIZE);
}
