/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:46:01 by alhote            #+#    #+#             */
/*   Updated: 2016/02/02 19:29:16 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

char	*ft_readfile(char *path, int buffer_size)
{
	char	buffer[buffer_size + 1];
	char	*str;
	int		ret;
	int		fd;

	str = (char*)ft_memalloc(sizeof(char));
	fd = open(path, 0);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buffer, buffer_size)) > 0)
	{
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
	}
	close(fd);
	return ((!str[0] ? NULL : str));
}
