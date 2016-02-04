/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:26:54 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/04 12:00:18 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*most_x(t_tetri *t)
{
	int		i;
	t_tetri	*actual;
	t_tetri	*id;
	int		x;

	actual = t;
	id = 0;
	i = 0;
	x = 0;
	while (actual)
	{
		if ((actual->x + actual->size_x) > x)
		{
			x = actual->x + actual->size_x;
			id = actual;
		}
		actual = actual->next;
	}
	return (id);
}

t_tetri	*most_y(t_tetri *t)
{
	int		i;
	t_tetri	*actual;
	t_tetri	*id;
	int		y;

	actual = t;
	id = 0;
	i = 0;
	y = 0;
	while (actual)
	{
		if ((actual->y + actual->size_y) > y)
		{
			y = actual->y + actual->size_y;
			id = actual;
		}
		actual = actual->next;
	}
	return (id);
}

char	get_char(t_tetri *t, int x, int y)
{
	int		i;
	t_tetri	*clone;

	i = 0;
	clone = t;
	while (clone)
	{
		if (move_tetriminos(clone->data, clone->x - x, clone->y - y) & 32768)
			return (i + 'A');
		clone = clone->next;
		++i;
	}
	return ('.');
}

void	ft_display(t_tetri *fst)
{
	int		i;
	int		a;
	int		max_x;
	int		max_y;
	t_tetri	*fst2;

	i = 0;
	a = 0;
	fst2 = fst;
	while (fst2->prev)
		fst2 = fst2->prev;
	max_x = most_x(fst2)->x + most_x(fst2)->size_x;
	max_y = most_y(fst2)->y + most_y(fst2)->size_y;
	while (i < (max_x > max_y ? max_x : max_y))
	{
		while (a < (max_x > max_y ? max_x : max_y))
		{
			ft_putchar(get_char(fst2, a, i));
			++a;
		}
		ft_putchar('\n');
		a = 0;
		++i;
	}
}
