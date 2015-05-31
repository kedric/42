/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:08:29 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:08:34 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <termios.h>
# include <stdlib.h>
# define BUFF_SIZE 4096

typedef struct		s_ps1
{
	char			*env;
	char			*aff;
	int				len;
}					t_ps1;

typedef struct		s_term
{
	struct termios	term;
	struct termios	term_ori;
	int				fd;
	int				wait;
	char			**key;
}					t_term;

typedef struct		s_hist
{
	char			value[BUFF_SIZE];
	int				pose_buff;
	int				len;
	int				modif;
	char			buff[BUFF_SIZE];
	struct s_hist	*next;
	struct s_hist	*prev;
	int				number;
}					t_hist;

typedef struct		s_builtin
{
	char			*name;
	char			*help;
}					t_builtin;

typedef struct		s_gen
{
	char			**env;
	char			**env_orig;
	t_ps1			*ps1;
	t_term			*term;
	t_hist			*hist;
	t_builtin		**builtin;
	int				ret;
	int				status;
	char			*path;
	pid_t			pid_fork;
}					t_gen;

#endif
