/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:02:57 by qxia              #+#    #+#             */
/*   Updated: 2022/08/12 13:18:49 by qxia             ###   ########.fr       */
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
	int		bits_per_pixel;
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

typedef struct s_cub3d
{
	char			**map;
	void			*mlx;
	void			*win;
	t_img_set		*imgs;
	t_info			*info;
	t_player		*plr;
}t_cub3d;


/***********************check_map****************************/


/***********************image*******************************/


/*************************movment**************************/


int	run_game(void);
#endif
