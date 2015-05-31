/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 10:47:06 by jmancero          #+#    #+#             */
/*   Updated: 2014/01/12 08:12:18 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <term.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_lstsel
{
	char			*value;
	int				sel;
	int				pnt;
	struct s_lstsel *next;
	struct s_lstsel *prev;
}					t_lstsel;

typedef struct		s_sig
{
	struct termios	term;
	struct termios	termo;
	int				x;
	int				y;
	int				max_len;
	t_lstsel		*lst;
}					t_sig;

int				ft_putc(int c);
void			ft_start(t_sig *sig);
int				ft_close(t_sig *sig);
void			affret(t_lstsel *lst);
void			aff_lst(t_lstsel *lst, t_sig *sig);
void			aff_tlst(t_lstsel *lst, t_sig *sig);
void			ft_mvflech(char e, t_lstsel *lst);
void			ft_pntnext(t_lstsel *lst);
void			ft_pntprev(t_lstsel *lst);
void			ft_selectopt(t_lstsel *lst);
void			ft_mvflech(char e, t_lstsel *lst);
t_lstsel		*ft_inilst(char **av, t_lstsel *lst);
t_lstsel		*ft_delet(t_lstsel *lst);
t_sig			*init_term(t_sig *sig);
t_sig			*ft_init_sig(void);
void			ft_init_signal(void);
t_sig			*init_term(t_sig *sig);
void			ft_sig_pause(int x);
t_lstsel		*ft_read(t_sig *sig);

#endif /*!FT_SELECT_H*/
