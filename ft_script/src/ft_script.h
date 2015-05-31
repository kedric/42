/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 09:30:38 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 14:29:47 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/select.h>
# include "struc_script.h"

int						open_ptym(t_opt *opt);
int						fork_pty(t_opt *opt);
void					test(t_opt *opt);
int						set_master(void);
void					reset_exit(t_opt *opt);
void					wait_fd(t_opt *opt);
void					say_started(t_opt *opt);
void					say_stop(t_opt *opt);

#endif
