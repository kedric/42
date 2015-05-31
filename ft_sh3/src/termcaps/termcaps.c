/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 10:36:51 by jmancero          #+#    #+#             */
/*   Updated: 2014/02/09 11:22:54 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_term	*recup_term(void)
{
	static t_term	*term = NULL;

	if (term == NULL)
	{
		term = (t_term *)malloc(sizeof(t_term));
		term->fd = open("/dev/tty", O_RDWR);
		term->dquote = 0;
		term->quote = 0;
		term->wait_fermeture = 0;
	}
	return (term);
}

char	*key_to_str(int a, int b, int c, int d)
{
	char	*key;

	key = (char *)malloc(sizeof(char) * 5);
	ft_bzero(key, 5);
	key[0] = a;
	key[1] = b;
	key[2] = c;
	key[3] = d;
	key[4] = '\0';
	return (key);
}

char	**init_key(char **key)
{
	key[0] = key_to_str(12, 0, 0, 0);
	key[1] = key_to_str(27, 91, 65, 0);
	key[2] = key_to_str(27, 91, 66, 0);
	key[3] = key_to_str(27, 91, 67, 0);
	key[4] = key_to_str(27, 91, 68, 0);
	key[5] = key_to_str(127, 0, 0, 0);
	key[6] = key_to_str(9, 0, 0, 0);
	key[7] = key_to_str(27, 27, 91, 68);
	key[8] = key_to_str(27, 27, 91, 67);
	key[9] = key_to_str(4, 0, 0, 0);
	key[10] = NULL;
	return (key);
}

void	init_term(void)
{
	t_term	*term;
	char	buff[BUFF_SIZE];
	char	*termtype;
	int		ret;

	term = recup_term();
	if ((termtype = getenv("TERM")) == 0)
		ft_puterr("term not found in env");
	if ((ret = tgetent(buff, termtype)) < 1)
		ft_puterr("no acces termtype");
	tcgetattr(0, &term->term_ori);
	ft_memcpy(&term->term, &term->term_ori, sizeof(struct termios));
	term->term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, 0, &term->term);
	if (term->key == NULL)
	{
		term->key = (char **)malloc(sizeof(char *) * 11);
		term->key = init_key(term->key);
	}
}

void	close_term(void)
{
	t_term	*term;

	term = recup_term();
	tcsetattr(0, 0, &term->term_ori);
}
