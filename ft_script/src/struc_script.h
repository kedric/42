/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc_script.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 13:56:22 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 14:06:38 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_SCRIPT_H
# define STRUC_SCRIPT_H

# include <termios.h>
typedef struct termios	t_term;
typedef struct winsize	t_win;

typedef struct	s_opt
{
	char				**env;
	int					opt_a;
	int					opt_q;
	char				*file_name;
	int					fd_file;
	char				*cmd[4096];
	char				cmd_av[4096];
	char				*shell;
	int					fd_slave;
	char				*fds_name[32];
	int					fd_master;
	char				*fdm_name[32];
	t_term				orig;
	t_win				winsize;
	int					pid_c;
}				t_opt;

#endif
