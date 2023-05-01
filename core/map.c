/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:59:59 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/18 10:59:59 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	ft_len_map(char *fileMap)
{
	int		i;
	int		fd;
	char	buff[1];

	i = 0;
	fd = open(fileMap, O_RDONLY);
	while (read(fd, buff, 1) != 0)
		i++;
	close(fd);
	return (i);
}

char	**ft_treat_map(char *fileMap)
{
	int		fd;
	char	**map;
	char	*buff;
	size_t	lenmap;

	lenmap = ft_len_map(fileMap);
	buff = ft_calloc((lenmap + 1), sizeof(char));
	fd = open(fileMap, O_RDONLY);
	read(fd, buff, lenmap);
	close(fd);
	map = ft_split(buff, '\n');
	free(buff);
	return (map);
}
