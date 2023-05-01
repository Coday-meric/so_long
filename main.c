/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:38:36 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:38:36 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_render(t_data *img)
{
	if (img->mlx_win == NULL)
		return (1);
	return (0);
}

static int	ft_file_map(char *filemap, t_data *img)
{
	int	fd;
	
	fd = open(filemap, O_RDONLY);
	if (read(fd, 0, 0) == -1)
	{
		free(img->img_);
		free(img);
		return (0);
	}
	close(fd);
	return (1);
}

static void	ft_clean(t_data *img)
{
	int	i;

	i = 0;
	mlx_destroy_display(img->mlx);
	mlx_loop_end(img->mlx);
	free(img->mlx_win);
	free(img->mlx);
	while (img->map[i])
		free(img->map[i++]);
	free(img->map);
	free(img->img_);
	free(img);
}

static int	ft_test_map(t_data *img)
{
	int	i;

	i = 0;
	if (ft_check_map(img) == 0)
	{
		while (img->map[i])
			free(img->map[i++]);
		free(img->map);
		free(img->img_);
		free(img);
		return (0);
	}
	if (ft_check_validity_map(img) == 1)
	{
		while (img->map[i])
			free(img->map[i++]);
		free(img->map);
		free(img->img_);
		free(img);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		*img;

	img = ft_calloc(1, sizeof(t_data));
	img->img_ = ft_calloc(1, sizeof(t_img_data));
	if (argc != 2 || ft_file_map(argv[1], img) == 0)
		return (0);
	img->map = ft_treat_map(argv[1]);
	if (ft_test_map(img) == 0)
		return (0);
	img->state = 0;
	img->move = 0;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->w_w * 64, img->w_h * 64, \
		"So Long");
	ft_create_img(img);
	ft_display_map(img);
	ft_enemy_place(img);
	mlx_loop_hook(img->mlx, ft_render, img);
	mlx_hook(img->mlx_win, 2, 1L << 0, ft_hooks, img);
	mlx_hook(img->mlx_win, 33, 0, ft_close, img);
	mlx_loop(img->mlx);
	ft_clean(img);
	return (0);
}
