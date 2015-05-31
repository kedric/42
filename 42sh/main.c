/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:17:24 by pdjamei           #+#    #+#             */
/*   Updated: 2014/03/27 19:17:27 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"
#include "parser.h"
#include "command.h"

void			ft_parse_and_exec(char *line, t_gen *gen)
{
	t_command	*command_lst;
	char		*tr;

	tr = ft_strtrim(line);
	if (ft_strncmp(tr, "exit", 4) == 0 && (!tr[4] || ft_isspace(tr[4]) == 1))
	{
		ft_strdel(&tr);
		destroy_gen();
		exit(0);
	}
	ft_strdel(&tr);
	command_lst = NULL;
	if (line && line[0])
	{
		command_lst = parser(line);
		ft_command(command_lst, gen);
		command_lst_free(command_lst);
	}
}

void			updat_prompt(t_ps1 *ps1)
{
	int			i;
	t_gen		*gen;

	gen = recup_gen();
	free(ps1->aff);
	ps1->aff = NULL;
	ps1->len = 0;
	parse_ps1(ps1);
	i = tgetnum("co");
	while (i--)
		ft_putstr_fd(tgetstr("kl", NULL), gen->term->fd);
}

void			prompt_next_line(t_gen *gen, char **line)
{
	char		buff[MAX_KEYCODE_LEN];
	int			ret;

	init_term();
	updat_prompt(gen->ps1);
	ft_putstr(gen->ps1->aff);
	if (gen->hist == NULL || gen->hist->buff[0] != 0)
		gen->hist = add_element(gen->hist);
	gen->term->wait = 1;
	while (gen->term->wait)
	{
		ft_bzero(buff, MAX_KEYCODE_LEN);
		ret = read(gen->term->fd, buff, MAX_KEYCODE_LEN);
		buff[ret] = 0;
		tc_stomp(buff, gen);
	}
	go_end(gen, NULL);
	gen->hist = save_hist(gen->hist);
	ft_putchar('\n');
	*line = gen->hist->buff;
	close_term();
}

void			ft_rappel(void)
{
	t_gen		*gen;
	char		*line;

	gen = recup_gen();
	while (1)
	{
		init_sig();
		gen->term->fd = open("/dev/tty", O_RDWR);
		prompt_next_line(gen, &line);
		ft_parse_and_exec(line, gen);
		close(gen->term->fd);
	}
}

int				main(int ac, char **av, char **env)
{
	t_gen		*gen;

	(void)ac;
	(void)av;
	init_env(env);
	gen = recup_gen();
	gen->ps1->env = ft_strdup("[%1%*%0]-[%2%d%0]>");
	parse_ps1(gen->ps1);
	ft_rappel();
	ft_putnbr(gen->ps1->len);
	return (1);
}
