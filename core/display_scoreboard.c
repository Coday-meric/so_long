/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_scoreboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:26:36 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:26:36 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_b(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 100;
	r = 255;
	g = 255;
	b = 255;
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	ft_display_scoreboard(t_data *img, char *move)
{
	char	*item_coll;
	char	*item;

	item_coll = ft_itoa(img->nbr_item_collect);
	item = ft_itoa(img->nbr_item);
	mlx_string_put(img->mlx, img->mlx_win, 52, 40, get_b(), "Move:");
	mlx_string_put(img->mlx, img->mlx_win, 105, 40, get_b(), move);
	mlx_string_put(img->mlx, img->mlx_win, 145, 40, get_b(), "Key:");
	mlx_string_put(img->mlx, img->mlx_win, 192, 40, get_b(), item_coll);
	mlx_string_put(img->mlx, img->mlx_win, 210, 40, get_b(), "/");
	mlx_string_put(img->mlx, img->mlx_win, 230, 40, get_b(), item);
	free(item);
	free(item_coll);
}

void	ft_scoreboard(t_data *img)
{
	char	*move;

	move = ft_itoa(img->move);
	ft_put_img(img, img->img_->s_b, 1 * 32, 0);
	mlx_set_font(img->mlx, img->mlx_win, FONTS);
	if (img->state == 1)
	{
		mlx_string_put(img->mlx, img->mlx_win, 50, 40, get_b(), "W I N with");
		mlx_string_put(img->mlx, img->mlx_win, 160, 40, get_b(), move);
		mlx_string_put(img->mlx, img->mlx_win, 200, 40, get_b(), "move");
	}
	else if (img->state == 2)
		mlx_string_put(img->mlx, img->mlx_win, 90, 40, get_b(), \
		"L O O S E R !");
	else
		ft_display_scoreboard(img, move);
	free(move);
}
