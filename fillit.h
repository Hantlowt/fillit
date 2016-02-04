/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:26:10 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/04 12:01:00 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct		s_tetri
{
	int				x;
	int				y;
	int				size_x;
	int				size_y;
	int				data;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

/*
** fillit.c
*/
int					recursif(t_tetri *cur, int max);
int					ft_next(t_tetri *cur, int max);
/*
** ft_parser.c
*/
int					ft_parser(char *buf);
/*
** tetriminos.c
*/
t_tetri				*ft_tetrilstnew(int date, t_tetri *prev);
t_tetri				*ft_lstgen(char *str);
void				ft_to_left_up(t_tetri *fst);
void				ft_size(t_tetri *fst);
int					move_tetriminos(int data, int x, int y);
/*
** collide.c
*/
int					are_tetriminos_collide(t_tetri *t1, t_tetri *t2);
int					no_collide(t_tetri *cur);
/*
** ft_display.c
*/
void				ft_display(t_tetri *fst);
t_tetri				*most_x(t_tetri *t);
t_tetri				*most_y(t_tetri *t);
/*
** ft_readfile.c
*/
char				*ft_readfile(char *path, int buffer_size);

#endif
