/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:53:22 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:53:22 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_create_move(int *h, int *w)
{
	int	dir;

	dir = rand() % (4 + 1 - 0) + 0;
	if (dir == 1)
		*h = *h - 1;
	if (dir == 2)
		*w = *w - 1;
	if (dir == 3)
		*w = *w + 1;
	if (dir == 4)
		*h = *h + 1;
	return (dir);
}

void	ft_enemy(t_data *img)
{
	int	h;
	int	w;
	int	dir;

	h = img->enmy_h;
	w = img->enmy_w;
	ft_put_img(img, img->img_->grass, img->enmy_w * 64, img->enmy_h * 64);
	dir = ft_create_move(&h, &w);
	while (img->map[h][w] != '0')
	{
		h = img->enmy_h;
		w = img->enmy_w;
		dir = ft_create_move(&h, &w);
	}
	img->enmy_h = h;
	img->enmy_w = w;
	if (dir == 3)
		ft_put_img(img, img->img_->f_r, img->enmy_w * 64, img->enmy_h * 64);
	else
		ft_put_img(img, img->img_->f_l, img->enmy_w * 64, img->enmy_h * 64);
	ft_check_loose(img);
}

void	ft_enemy_place(t_data *img)
{
	int	h;
	int	w;

	w = (rand() % ((img->w_w - 1) + 1 - 0) + 0);
	h = (rand() % ((img->w_h - 1) + 1 - 0) + 0);
	while (img->map[h][w] != '0')
	{
		w = (rand() % ((img->w_w - 1) + 1 - 0) + 0);
		h = (rand() % ((img->w_h - 1) - 0) + 0);
	}
	img->enmy_h = h;
	img->enmy_w = w;
	ft_put_img(img, img->img_->f_l, img->enmy_w * 64, img->enmy_h * 64);
}
