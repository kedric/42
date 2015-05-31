/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_caps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:08:42 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 19:07:09 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_CAPS_H
# define TERM_CAPS_H

# include <stdlib.h>
# include <fcntl.h>
# include "sh.h"
# include <signal.h>
# define MAX_KEYCODE_LEN	4096

void				print_key(char *key);

typedef void		t_fn(t_gen *gen, char *buff);
void				fn_curs_left(t_gen *gen, char *buff);
void				fn_curs_down(t_gen *gen, char *buff);
void				fn_curs_up(t_gen *gen, char *buff);
void				fn_curs_right(t_gen *gen, char *buff);
void				fn_char_backsp(t_gen *gen, char *buff);
void				fn_char_del(t_gen *gen, char *buff);
void				fn_prewrite(t_gen *gen, char *buff);

enum				e_key
{
	K_ENTER,
	K_LEFT,
	K_DOWN,
	K_UP,
	K_RIGHT,
	K_BACKSP,
	K_DEL,
	K_END,
	K_START,
	K_KILL,
	K_CL,
	K_REGULAR
};

void				tc_move_left(t_gen *gen, int i, int force);
void				tc_move_right(t_gen *gen, int i, int force);
void				tc_del_char(t_gen *gen, int i);
void				tc_clean_line(t_gen *gen);
void				gen_tc_move_left(t_gen *gen, int i);
void				gen_tc_move_right(t_gen *gen, int i);
int					ft_isnl(t_gen *gen, int pos);
void				go_end(t_gen *gen, char *key);
void				go_start(t_gen *gen, char *key);
void				fn_write_char(t_gen *gen, char key);

/*
** signal
*/
void				ft_sig_segv(int x);
void				ft_sig_tstp(int x);
void				ft_sig_int(int x);
void				init_sig(void);
void				go_kill(t_gen *gen, char *buff);
void				clear(t_gen *gen, char *buff);
void				print_in(t_gen *gen, char k);
char				format_str(char key);
#endif
