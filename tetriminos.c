/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:19:52 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/02 21:12:20 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_tetrilstnew(int data, t_tetri *prev)
{
	t_tetri *new;

	if (!(new = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	new->data = data;
	new->prev = prev;
	new->next = NULL;
	if (prev)
		prev->next = new;
	return (new);
}

t_tetri	*ft_lstgen(char *str)
{
	t_tetri *cur;
	t_tetri *prev;
	int		data;

	prev = NULL;
	cur = NULL;
	data = 0;
	while (*str)
	{
		if (*str != '\n')
			data = data << 1;
		if (*str == '#')
			++data;
		if (*str == '\n' && (*(str + 1) == '\n' || *(str + 1) == '\0'))
		{
			prev = cur;
			cur = ft_tetrilstnew(data, prev);
			data = 0;
		}
		str++;
	}
	while (cur->prev)
		cur = cur->prev;
	return (cur);
}

void	ft_to_left_up(t_tetri *fst)
{
	t_tetri	*fst2;

	fst2 = fst;
	while (fst2)
	{
		while (!(fst2->data & 34952))
			fst2->data = fst2->data << 1;
		while (!(fst2->data & 61440))
			fst2->data = fst2->data << 4;
		fst2 = fst2->next;
	}
}

void	ft_size(t_tetri *fst)
{
	int			size[2];
	int			mask[2];
	t_tetri		*fst2;

	fst2 = fst;
	while (fst2)
	{
		size[0] = 0;
		size[1] = 0;
		mask[0] = 34952;
		mask[1] = 61440;
		while (fst2->data & mask[0])
		{
			++size[0];
			mask[0] = mask[0] >> 1;
		}
		fst2->size_x = size[0];
		while (fst2->data & mask[1])
		{
			++size[1];
			mask[1] = mask[1] >> 4;
		}
		fst2->size_y = size[1];
		fst2 = fst2->next;
	}
}

int		move_tetriminos(int data, int x, int y)
{
	while (x > 0)
	{
		data = (data & 61166) >> 1;
		--x;
	}
	while (x < 0)
	{
		data = (data & 30583) << 1;
		++x;
	}
	while (y > 0)
	{
		data = (data & 65520) >> 4;
		--y;
	}
	while (y < 0)
	{
		data = (data & 4095) << 4;
		++y;
	}
	return (data);
}
