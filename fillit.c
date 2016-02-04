/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:59:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/04 12:00:55 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_next(t_tetri *cur, int max)
{
	++cur->x;
	if (cur->x + cur->size_x > max)
	{
		cur->x = 0;
		++cur->y;
	}
	if (cur->y + cur->size_y > max)
		return (0);
	return (1);
}

int		recursif(t_tetri *cur, int max)
{
	if (!cur)
		return (1);
	cur->x = 0;
	cur->y = 0;
	while (1)
	{
		while (!no_collide(cur))
		{
			if (!ft_next(cur, max))
				return (0);
		}
		if (recursif(cur->next, max))
			return (1);
		else
		{
			if (!ft_next(cur, max))
				return (0);
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*str;
	t_tetri	*fst;
	int		max;

	if (argc == 2)
	{
		if ((str = ft_readfile(argv[1], 25)))
		{
			if (!(ft_parser(str)))
			{
				ft_putendl("error");
				return (0);
			}
			fst = ft_lstgen(str);
			ft_to_left_up(fst);
			ft_size(fst);
			max = 0;
			while (!recursif(fst, max))
				++max;
			ft_display(fst);
			return (0);
		}
	}
	ft_putendl("error");
	return (0);
}
