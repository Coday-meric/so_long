/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:22:27 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:50:19 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_wall(t_data *img, int d_h, int d_w)
{
	if (img->map[d_h][d_w] == '1')
		return (0);
	return (1);
}

int	ft_check_item(t_data *img, int d_h, int d_w)
{
	if (img->map[d_h][d_w] == 'C')
	{
		img->nbr_item_collect = img->nbr_item_collect + 1;
		img->map[d_h][d_w] = '0';
		ft_scoreboard(img);
		if (img->nbr_item == img->nbr_item_collect)
			ft_open_door(img);
		return (1);
	}
	return (0);
}

int	ft_check_loose(t_data *img)
{
	if (img->p_w == img->enmy_w && img->p_h == img->enmy_h)
	{
		img->state = 2;
		ft_put_img(img, img->img_->f_p, img->enmy_w * 64, img->enmy_h * 64);
		ft_scoreboard(img);
		return (1);
	}
	return (0);
}

int	ft_check_win(t_data *img, int d_h, int d_w)
{
	if (img->e_w == d_w && img->e_h == d_h)
	{
		if (img->nbr_item == img->nbr_item_collect)
		{
			ft_put_img(img, img->img_->grass, img->p_w * 64, img->p_h * 64);
			ft_put_img(img, img->img_->f_p, img->enmy_w * 64, img->enmy_h * 64);
			ft_close_door(img);
			img->state = 1;
			ft_scoreboard(img);
			return (1);
		}
		return (1);
	}
	return (0);
}
