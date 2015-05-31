/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 21:17:58 by jmancero          #+#    #+#             */
/*   Updated: 2014/04/19 07:49:43 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
# define INT_MIN (-INT_MAX - 1)
# define INT_MAX 2147483647
# define TINY_MAX 512
# define SMALL_MAX 4095

typedef struct	s_plage
{
	size_t		len;
	char		aloued;
	void		*prev;
	void		*next;
}				t_plage;

typedef struct	s_table
{
	size_t		max_len;
	int			page_len;
	void		*page;
	void		*next;
}				t_table;

typedef struct	s_chr
{
	t_table		*tmp;
	t_table		*tmp_old;
	t_plage		*tmp_p;
}				t_chr;

size_t			ft_strlen(const char *s);
int				ft_putchar(char c);
int				ft_putstr(char const *s);
int				ft_putpoint(long unsigned int n);
void			ft_bzero(void *s, size_t n);
int				ft_putnbr(int n);
void			free(void *ptr);
t_table			*paye_ton_thon(void);
void			*alloc_memmory(t_plage *page, size_t size);
t_plage			*creeat_plage(size_t len, void *prev, void *next, void *addr);
void			*active_new_page(size_t size);
void			print_alloc(t_table *table);
void			show_alloc_mem(void);
t_table			*return_page_to_alloc(t_table *table, size_t size);
void			first_call(t_table *table);
void			print_table(t_plage *tmp);
void			*ft_memcpy(void *s1, const void *s2, size_t n);

#endif
