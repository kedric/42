/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 18:10:53 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/12 08:23:43 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"

t_sig	*ft_init_sig(void)
{
	static t_sig	sig;
	static int		first_time = 1;

	if (first_time)
	{
		first_time = 0;
		sig.x = tgetnum("co");
		sig.y = tgetnum("li");
		sig.lst = NULL;
	}
	return (&sig);
}

int		ft_close(t_sig *sig)
{
	tputs(tgetstr("te", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	tcsetattr(0, 0, &sig->termo);
	return (0);
}

void	ft_start(t_sig *sig)
{
	t_lstsel	*last_lst;

	sig = init_term(sig);
	while ((sig->lst = ft_read(sig)))
	{
		last_lst = sig->lst;
		aff_lst(sig->lst, sig);
	}
	ft_close (sig);
	affret(last_lst);
}

t_sig	*init_term(t_sig *sig)
{
	char	*termtype;
	char	buffer[2048];
	int		ret;

	if ((termtype = getenv("TERM")) == 0)
	{
		ft_perr("term not found in env");
		return (sig);
	}
	if ((ret = tgetent(buffer, termtype)) < 1)
		ft_perr("no acces termtype");
	tcgetattr(0, &sig->termo);
	ft_memcpy(&sig->term, &sig->termo, sizeof(struct termios));
	sig->term.c_lflag &= ~(ICANON | ECHO);
	tputs(tgetstr("ti", NULL), 1, ft_putc);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
	tcsetattr(0, 0, &sig->term);
	aff_lst(sig->lst, sig);
	return (sig);
}
