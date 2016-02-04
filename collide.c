/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:56:21 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/02 21:20:17 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		are_tetriminos_collide(t_tetri *t1, t_tetri *t2)
{
	int	data_to_compare;

	data_to_compare = move_tetriminos(t2->data, t2->x - t1->x, t2->y - t1->y);
	return ((t1->data & data_to_compare) > 0);
}

int		no_collide(t_tetri *cur)
{
	t_tetri *i;
	t_tetri *a;

	i = cur;
	a = cur;
	while (i)
	{
		if (are_tetriminos_collide(i, cur) && i != cur)
			return (0);
		i = i->prev;
	}
	return (1);
}
