/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qinxia <qinxia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:02:57 by qxia              #+#    #+#             */
/*   Updated: 2022/08/09 15:04:20 by qinxia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include "../mlx/mlx.h"

typedef struct s_imgs //images information
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}t_imgs;

struct s_map //map informtion
{
	char	*we;
	char	*ea;
	char	*no;
	char	*so;
	int	floor_color;
	int	ceiling_color;
	char	*player;
	char	**map;
	size_t	row; //高度
	size_t	col; //宽度
	char	dir;
}my_map;

struct	s_textures
{
	int		tex_width;
	int		tex_height;
	t_imgs	no;
	t_imgs	so;
	t_imgs	we;
	t_imgs	ea;
	t_imgs	ceiling;
	t_imgs	floor;
};

/*typedef struct	s_player
{
	double		x;
	double		y;
	char	texture;
	int	player_width;
	int	player_height;
	int player_screen_x;
} t_player;*/

struct	s_keys
{
	int		w;
	int		s;
	int		d;
	int		a;
	int		left;
	int		right;
};

struct s_cub3d
{
        void    *mlx;
        void    *win;
		t_imgs	img;
        struct s_map   map;
		struct s_textures textures;
        struct s_keys	keys;
}cub3d;

int	run_game(void);

#endif
