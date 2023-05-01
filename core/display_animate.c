/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_animate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:22:27 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:22:27 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_open_door(t_data *img)
{
	ft_put_img(img, img->img_->d_o, img->e_w * 64, img->e_h * 64);
}

void	ft_close_door(t_data *img)
{
	ft_put_img(img, img->img_->d_c, img->e_w * 64, img->e_h * 64);
}
