/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:02:57 by qxia              #+#    #+#             */
/*   Updated: 2022/09/07 11:32:18 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MOVE_DIST 0.10
# define SPD 0.10

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include "../mlx/mlx.h"

/**************Macros************************/

#  define XK_ESCAPE 0xff1b
#  define XK_W 0x0077
#  define XK_A 0x0061
#  define XK_S 0x0073
#  define XK_D 0x0064
#  define XK_LEFT 0xff51
#  define XK_RIGHT 0xff53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
	int		w;
	int		h;
}t_img;

typedef struct s_img_set
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	t_img	*plr;
	t_img	*dir;
	t_img	*flr;
	t_img	*smallmap;
	t_img	*graphic;
}t_img_set;

typedef struct s_info
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}t_info;

typedef struct s_player
{
	double	p_x;
	double	p_y;
	double	d_x;
	double	d_y;
	double	pl_x;
	double	pl_y;
}t_player;

typedef struct s_ray
{
	double		lp_x;
	double		dir_x;
	double		dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	double		wall_x;
	int			lign_h;
}	t_ray;

typedef struct s_text
{
	int		start;
	int		end;
	int		tex_x;
	double	step;
	double	tex_p;
}	t_text;

typedef struct s_cub3d
{
	char			**map;
	void			*mlx;
	void			*win;
	t_img_set		*imgs;
	t_info			*info;
	t_player		*plr;
}t_cub3d;

enum	e_error_codes
{
	ERR_ARGS = 1,
	ERR_FILE,
	ERR_FD,
	ERR_GNL,
	ERR_MLX,
	ERR_MALLOC,
	ERR_INFO,
	ERR_MAP_NULL,
	ERR_MAP_OPEN,
	ERR_MAP_CHAR,
	ERR_MAP_MOREPLAYER,
};

/***********************parser****************************/
int ft_check_info(t_info *info);
int ft_check_map(char **map);
int	ft_get_map(int fd, t_cub3d **cub3d);
int	ft_parser(char *filename, t_cub3d **cub3d);
int	ft_init_info(t_cub3d **cub3d);
int	ft_get_info(int fd, t_cub3d **cub3d);
int	ft_arraylen(char **str_array);
void	ft_free_strarray(char **str_array);
int	ft_set_player(t_cub3d *cub3d);
int	ft_init_imgs(t_cub3d *cub);

/*************************movment**************************/
void		ft_move_w(t_cub3d *cub);
void		ft_move_s(t_cub3d *cub);
void		ft_move_a(t_cub3d *cub);
void		ft_move_d(t_cub3d *cub);
int	ft_atoi_unsig(const char *str);
int ft_close(t_cub3d *cub3d);
int	ft_key_event(int key, t_cub3d *cub3d);
int	ft_return(int ret_code, t_cub3d *cub3d);
void	ft_free_cub3d(t_cub3d *cub3d);

/*************************exec**************************/
int rgb_to_int(int *rgb);
t_img   *chose_texture(t_cub3d *cub, t_ray ray);
int	ft_print_smallmap(t_cub3d *cub, t_img_set *ig);
void	dda(t_cub3d *cub, t_ray *ray, int map_x, int map_y);
void	init_side_dist(t_cub3d *cub, t_ray *ray, int map_x, int map_y);
void	ft_print_graphic(t_cub3d *cub);

#endif
