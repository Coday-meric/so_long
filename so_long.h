/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:22:27 by amaisonn          #+#    #+#             */
/*   Updated: 2023/03/19 23:22:27 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./minilibx/mlx_int.h"
# include "./lib/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define R_U "./assets/rabbit-u.xpm"
# define R_D "./assets/rabbit-d.xpm"
# define R_R "./assets/rabbit-r.xpm"
# define R_L "./assets/rabbit-l.xpm"
# define F_L "./assets/fox-l.xpm"
# define F_R "./assets/fox-r.xpm"
# define F_P "./assets/fox-s.xpm"
# define GRASS "./assets/grass.xpm"
# define KEY "./assets/key.xpm"
# define THREE "./assets/three.xpm"
# define D_O "./assets/door-open.xpm"
# define D_C "./assets/door.xpm"
# define S_B "./assets/scoreboard.xpm"
# define FONTS "-misc-fixed-bold-r-semicondensed--20-0-75-75-c-0-iso10646-1"

typedef struct s_img_data
{
	void	*r_u;
	void	*r_d;
	void	*r_r;
	void	*r_l;
	void	*f_l;
	void	*f_r;
	void	*f_p;
	void	*three;
	void	*key;
	void	*grass;
	void	*d_c;
	void	*d_o;
	void	*s_b;
}	t_img_data;

typedef struct s_data
{
	t_img_data	*img_;
	int			w_w;
	int			w_h;
	int			h;
	int			w;
	int			nbr_item;
	int			nbr_item_collect;
	int			move;
	int			e_h;
	int			e_w;
	int			p_h;
	int			p_w;
	int			enmy_h;
	int			enmy_w;
	int			state;
	void		*mlx;
	void		*mlx_win;
	char		**map;
}	t_data;

int		ft_check_wall(t_data *img, int d_h, int d_w);
int		ft_check_map(t_data *img);
int		ft_check_item(t_data *img, int d_h, int d_w);
int		ft_check_win(t_data *img, int d_h, int d_w);
int		ft_hooks(int keycode, t_data *img);
int		ft_check_loose(t_data *img);
int		ft_check_validity_map(t_data *img);
int		ft_close(t_data *img);
int		ft_wall_map(t_data *img);
int		ft_check_char(t_data *img);
int		ft_check_min(t_data *img);
char	**ft_treat_map(char *fileMap);
void	ft_display_map(t_data *img);
void	ft_create_img(t_data *img);
void	ft_open_door(t_data *img);
void	ft_scoreboard(t_data *img);
void	ft_close_door(t_data *img);
void	ft_enemy(t_data *img);
void	ft_enemy_place(t_data *img);
void	ft_put_img(t_data *img, void *sel_img, int w, int h);

#endif //SO_LONG_H
