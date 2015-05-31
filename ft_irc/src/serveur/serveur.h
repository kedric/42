/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 10:09:11 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/25 17:45:29 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <sys/socket.h>
# include <netdb.h>
# include <sys/time.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/select.h>
# include <stdio.h>

# define BUFF_SIZE 4096
# define XV(err,res,str)	(x_void(err, res, str, e_i(__FILE__, __LINE__)))
# define X(err,res,str)		(x_int(err, res, str, e_i(__FILE__, __LINE__)))
# define FD_CLIENT 50
# define FD_SERV 100
# define MAX(a,b)	((a > b) ? a : b)

typedef struct	s_errror
{
	char		*file;
	int			line;
}				t_error;

typedef struct	s_chan
{
	int			id;
	char		*name;
}				t_chan;

typedef struct	s_fd
{
	int			type;
	void		(*fct_read)();
	void		(*fct_write)();
	char		*save;
	char		*nick;
	int			channel;
	char		buff_read[BUFF_SIZE + 1];
	char		buff_write[BUFF_SIZE + 1];
}				t_fd;

typedef struct	s_env
{
	char		*prg_name;
	int			port;
	int			max;
	int			max_fd;
	t_fd		*fds;
	t_chan		chan[100];
	int			ret;
	fd_set		fd_read;
	fd_set		fd_write;
}				t_env;

t_error			e_i(char *file, int line);
void			init_env(t_env *env);
void			init_serv(t_env *env);
void			*x_void(void *err, void *res, char *str, t_error e);
int				x_int(int err, int res, char *str, t_error e);
void			client_write(t_env *e, int cs);
void			client_read(t_env *env, int cs);

/*
** loop.c
*/
void			check_fd(t_env *env);
void			do_select(t_env *env);
void			init_fd(t_env *e);

void			change_nickname(t_env *env, int cs);
void			change_chan(t_env *env, int cs);
void			leave_chan(t_env *env, int cs);
void			send_priv(t_env *env, int cs);

#endif
