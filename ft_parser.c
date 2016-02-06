/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:23:58 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/06 18:19:40 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_parserorga(char *buf)
{
	int		len;
	int		i;

	i = 4;
	while (*buf)
	{
		len = ft_getlinesize(buf);
		if (len != 4 && len != 0)
			return (0);
		if (len == 4 && !(i-- > 0))
			return (0);
		else if (len == 0 && i != 0)
			return (0);
		else if (len == 0 && i == 0)
			i = 4;
		buf = ft_gotoline(buf, 1);
	}
	return (1);
}

static int	ft_tetroright(char *buf, int map[])
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (buf[i] == '.')
			map[i] = -1;
		else if (buf[i] == '#')
		{
			if (i - 1 >= 0 && buf[i - 1] == '#')
				++map[i];
			if (i + 1 >= 0 && buf[i + 1] == '#')
				++map[i];
			if (i - 5 >= 0 && buf[i - 5] == '#')
				++map[i];
			if (i + 5 >= 0 && buf[i + 5] == '#')
				++map[i];
		}
		else if (buf[i] == '\n' || buf[i] == 0)
			map[i] = -1;
		else
			return (0);
		i++;
	}
	return (1);
}

static int	ft_parserright(char *buf)
{
	int	i;
	int	map[20];
	int	nb;

	i = 0;
	nb = 0;
	while (i < 20)
	{
		map[i] = 0;
		++i;
	}
	i = 0;
	if (ft_tetroright(buf, map) == 0)
		return (0);
	while (i < 20)
	{
		if (map[i] == 0)
			return (0);
		if (map[i] >= 1)
			nb += map[i];
		++i;
	}
	if (nb >= 6)
		return (1);
	return (0);
}

static int	ft_parserbluh(char *buf, int nbline)
{
	int		i;
	int		nbhash;

	i = 0;
	nbhash = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			++nbhash;
		++i;
	}
	if (nbhash != 4 * ((nbline) / 5))
		return (0);
	i = 0;
	while (i <= nbline - 5)
	{
		if (ft_parserright(buf) == 0)
			return (0);
		buf = ft_gotoline(buf, 5);
		i += 5;
	}
	return (1);
}

int			ft_parser(char *buf)
{
	if (!((ft_getnbrline(buf)) % 5 == 0))
		return (0);
	if (!(ft_parserorga(buf)))
		return (0);
	if (!(ft_parserbluh(buf, ft_getnbrline(buf))))
		return (0);
	return (1);
}
