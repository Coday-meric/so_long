/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:05:47 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:05:47 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_direction(t_data *img, int *p_h, int *p_w)
{
	int	dir;

	dir = rand() % (4 + 1 - 0) + 0;
	if (dir == 1)
		if (ft_check_wall(img, *p_h - 1, *p_w))
			*p_h = *p_h - 1;
	if (dir == 2)
		if (ft_check_wall(img, *p_h, *p_w - 1))
			*p_w = *p_w - 1;
	if (dir == 3)
		if (ft_check_wall(img, *p_h, *p_w + 1))
			*p_w = *p_w + 1;
	if (dir == 4)
		if (ft_check_wall(img, *p_h + 1, *p_w))
			*p_h = *p_h + 1;
}

static int	ft_bruteforce(int *i, int *j, t_data *img)
{
	int	t;
	int	p_h;
	int	p_w;

	t = 0;
	p_h = img->p_h;
	p_w = img->p_w;
	while (*i != p_h || *j != p_w)
	{
		if (t > 500000)
		{
			ft_putstr_fd("Map invalide ! Un collectible ou la sortie"
				" semble inaccessible.\n", 1);
			return (1);
		}
		ft_direction(img, &p_h, &p_w);
		t++;
	}
	return (0);
}

static int	ft_check_validity_item(int *i, int *j, t_data *img)
{
	while (img->map[*i] != NULL)
	{
		while (img->map[*i][*j])
		{
			if (img->map[*i][*j] == 'C')
			{
				if (ft_bruteforce(i, j, img))
					return (1);
				ft_putstr_fd("Chemin vers un collectible trouve ! "
					"Verification en cours...\n", 1);
			}
			*j = *j + 1;
		}
		*j = 0;
		*i = *i + 1;
	}
	return (0);
}

int	ft_check_validity_map(t_data *img)
{
	int	i;
	int	j;

	ft_putstr_fd("Verification de la map en cours...\n", 1);
	i = 0;
	j = 0;
	if (ft_check_validity_item(&i, &j, img))
		return (1);
	ft_putstr_fd("Collectibles trouves ! Verification sortie en cours...\n", 1);
	i = 0;
	j = 0;
	while (img->map[i] != NULL)
	{
		while (img->map[i][j])
		{
			if (img->map[i][j] == 'E')
				if (ft_bruteforce(&i, &j, img))
					return (1);
			j++;
		}
		j = 0;
		i++;
	}
	ft_putstr_fd("Sortie trouve ! Map verifie avec succes, bon jeux !\n", 1);
	return (0);
}
