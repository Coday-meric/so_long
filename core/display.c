/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:04:52 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/15 11:04:53 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img(t_data *img, void *sel_img, int w, int h)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win, sel_img, w, h);
}

void	ft_create_img(t_data *img)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	img->img_->r_u = mlx_xpm_file_to_image(img->mlx, R_U, &w, &h);
	img->img_->r_d = mlx_xpm_file_to_image(img->mlx, R_D, &w, &h);
	img->img_->r_r = mlx_xpm_file_to_image(img->mlx, R_R, &w, &h);
	img->img_->r_l = mlx_xpm_file_to_image(img->mlx, R_L, &w, &h);
	img->img_->f_l = mlx_xpm_file_to_image(img->mlx, F_L, &w, &h);
	img->img_->f_r = mlx_xpm_file_to_image(img->mlx, F_R, &w, &h);
	img->img_->f_p = mlx_xpm_file_to_image(img->mlx, F_P, &w, &h);
	img->img_->three = mlx_xpm_file_to_image(img->mlx, THREE, &w, &h);
	img->img_->key = mlx_xpm_file_to_image(img->mlx, KEY, &w, &h);
	img->img_->grass = mlx_xpm_file_to_image(img->mlx, GRASS, &w, &h);
	img->img_->d_c = mlx_xpm_file_to_image(img->mlx, D_C, &w, &h);
	img->img_->d_o = mlx_xpm_file_to_image(img->mlx, D_O, &w, &h);
	img->img_->s_b = mlx_xpm_file_to_image(img->mlx, S_B, &w, &h);
}

static void	ft_treat_elem(char c, t_data *img)
{
	if (c == '1')
		ft_put_img(img, img->img_->three, img->w * 64, img->h * 64);
	else if (c == 'C')
		ft_put_img(img, img->img_->key, img->w * 64, img->h * 64);
	else if (c == 'E')
	{
		img->e_w = img->w;
		img->e_h = img->h;
		ft_put_img(img, img->img_->d_c, img->w * 64, img->h * 64);
	}
	else if (c == 'P')
	{
		img->p_w = img->w;
		img->p_h = img->h;
		ft_put_img(img, img->img_->r_d, img->p_w * 64, img->p_h * 64);
	}
	else if (c == '\n')
	{
		img->w = 0;
		img->h = img->h + 1;
	}
	else if (c == '0')
		ft_put_img(img, img->img_->grass, img->w * 64, img->h * 64);
	if (c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '0')
		img->w = img->w + 1;
}

void	ft_display_map(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	img->h = 0;
	img->w = 0;
	while (img->map[i] != NULL)
	{
		while (img->map[i][j])
		{
			if (img->map[i][j] == 'C')
				img->nbr_item = img->nbr_item + 1;
			if (img->map[i][j] == 'E')
			{
				img->e_h = i;
				img->e_w = j;
			}
			ft_treat_elem(img->map[i][j], img);
			j++;
		}
		j = 0;
		i++;
	}
	ft_scoreboard(img);
}
