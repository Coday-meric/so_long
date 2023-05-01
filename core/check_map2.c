/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:22:27 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:22:27 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_min(t_data *img)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (img->map[i] != NULL)
	{
		while (img->map[i][j])
		{
			if (img->map[i][j] == '0')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_wall_map(t_data *img)
{
	int	i;
	int	j;

	j = 0;
	while (j < img->w_w)
	{
		if (img->map[0][j] != '1')
			return (0);
		if (img->map[img->w_h - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (img->map[i])
	{
		if (img->map[i][0] != '1')
			return (0);
		if (img->map[i][img->w_w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_char(t_data *img)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (img->map[i] != NULL)
	{
		while (img->map[i][j])
		{
			if (img->map[i][j] != '1' && img->map[i][j] != '0' && \
				img->map[i][j] != 'P' && img->map[i][j] != 'C' && \
				img->map[i][j] != 'E' && img->map[i][j] != '\n')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
