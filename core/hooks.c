/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:31:48 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:31:48 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_select_img(t_data *img, int d)
{
	if (d == 1)
		ft_put_img(img, img->img_->r_u, img->p_w * 64, img->p_h * 64);
	if (d == 2)
		ft_put_img(img, img->img_->r_d, img->p_w * 64, img->p_h * 64);
	if (d == 3)
		ft_put_img(img, img->img_->r_r, img->p_w * 64, img->p_h * 64);
	if (d == 4)
		ft_put_img(img, img->img_->r_l, img->p_w * 64, img->p_h * 64);
}

static void	ft_exec_move(int *h, int *w, int d)
{
	if (d == 1)
		*h = *h - 1;
	if (d == 2)
		*h = *h + 1;
	if (d == 3)
		*w = *w - 1;
	if (d == 4)
		*w = *w + 1;
}

static void	ft_move(t_data *img, int d)
{
	int	h;
	int	w;

	h = img->p_h;
	w = img->p_w;
	ft_exec_move(&h, &w, d);
	if (img->state != 2)
	{
		if (ft_check_wall(img, h, w) == 1 && ft_check_win(img, h, w) == 0)
		{
			ft_check_item(img, h, w);
			ft_put_img(img, img->img_->grass, img->p_w * 64, img->p_h * 64);
			img->p_w = w;
			img->p_h = h;
			img->move = img->move + 1;
			ft_scoreboard(img);
			ft_select_img(img, d);
		}
		if (ft_check_loose(img) == 0 && ft_check_win(img, h, w) == 0)
			ft_enemy(img);
	}
}

int	ft_close(t_data *img)
{
	img->state = 2;
	mlx_destroy_image(img->mlx, img->img_->r_u);
	mlx_destroy_image(img->mlx, img->img_->r_d);
	mlx_destroy_image(img->mlx, img->img_->r_r);
	mlx_destroy_image(img->mlx, img->img_->r_l);
	mlx_destroy_image(img->mlx, img->img_->f_l);
	mlx_destroy_image(img->mlx, img->img_->f_r);
	mlx_destroy_image(img->mlx, img->img_->f_p);
	mlx_destroy_image(img->mlx, img->img_->three);
	mlx_destroy_image(img->mlx, img->img_->key);
	mlx_destroy_image(img->mlx, img->img_->grass);
	mlx_destroy_image(img->mlx, img->img_->d_c);
	mlx_destroy_image(img->mlx, img->img_->d_o);
	mlx_destroy_image(img->mlx, img->img_->s_b);
	if (img->mlx_win)
		mlx_destroy_window(img->mlx, img->mlx_win);
	img->mlx_win = NULL;
	return (0);
}

int	ft_hooks(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		ft_close(img);
		return (0);
	}
	if (img->state == 1)
		return (1);
	else if (keycode == 119 || keycode == 122)
		ft_move(img, 1);
	else if (keycode == 115)
		ft_move(img, 2);
	else if (keycode == 97 || keycode == 113)
		ft_move(img, 3);
	else if (keycode == 100)
		ft_move(img, 4);
	return (1);
}
