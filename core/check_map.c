/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:22:27 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:22:27 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_wh_map(t_data *img)
{
	int	i;
	int	j;
	int	w;
	int	h;

	i = 0;
	j = 0;
	w = 0;
	while (img->map[i])
	{
		while (img->map[i][j])
			j++;
		if (w != 0 && w != j)
			return (0);
		w = j;
		j = 0;
		i++;
	}
	h = i;
	if (h == w)
		return (0);
	img->w_w = w - 1;
	img->w_h = h;
	return (1);
}

static void	ft_items_count(int	*i, int	*j, int	*p, t_data *img)
{
	if (img->map[*i][*j] == 'P')
	{
		*p = *p + 1;
		img->p_h = *i;
		img->p_w = *j;
	}
	*j = *j + 1;
}

static void	ft_items_var(int	*i, int	*j, int	*e, int	*c)
{
	*i = 0;
	*j = 0;
	*e = 0;
	*c = 0;
}

static int	ft_items_map(t_data *img)
{
	int	i;
	int	j;
	int	e;
	int	c;
	int	p;

	ft_items_var(&i, &j, &e, &c);
	p = 0;
	while (img->map[i] != NULL)
	{
		while (img->map[i][j])
		{
			if (img->map[i][j] == 'E')
				e++;
			if (img->map[i][j] == 'C')
				c++;
			ft_items_count(&i, &j, &p, img);
		}
		j = 0;
		i++;
	}
	if (e == 1 && c >= 1 && p == 1)
		return (1);
	return (0);
}

int	ft_check_map(t_data *img)
{
	if (ft_wh_map(img) == 0 || ft_check_min(img) == 0)
	{
		ft_putstr_fd("Error : map au mauvais format ou trop petite !\n", 1);
		return (0);
	}
	if (ft_items_map(img) == 0)
	{
		ft_putstr_fd("Error : items absent ou en trop !\n", 1);
		return (0);
	}
	if (ft_wall_map(img) == 0)
	{
		ft_putstr_fd("Error : les murs n'entourent pas la map !\n", 1);
		return (0);
	}
	if (ft_check_char(img) == 0)
	{
		ft_putstr_fd("Error : les caracteres de la map" \
		" sont non valide !\n", 1);
		return (0);
	}
	return (1);
}
