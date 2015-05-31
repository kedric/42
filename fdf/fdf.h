/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:21:36 by jmancero          #+#    #+#             */
/*   Updated: 2013/12/21 15:23:31 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 4096
# include <mlx.h>

typedef struct		s_fd
{
	int		open;
	int		read;
}					t_fd;

typedef struct		s_dim
{
	int		lgh;
	int		wdh;
}					t_dim;

typedef struct		s_coord
{
	int				***tab;
	int				length;
	int				width;
	void			*mlx;
	void			*wdw;
	void			*img;
	char			*i_data;
}					t_coord;

int			**fdf_create_tab(char **str, int *i, int *len);
int			***mlx_create_coord(int **tab, t_dim *dim);
t_coord		ft_draw_line(t_coord pic);
t_coord		ft_set_img(t_coord pic);
int			ft_key_hook(int keycode, void *key);

#endif
