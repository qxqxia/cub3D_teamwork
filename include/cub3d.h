/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:02:57 by qxia              #+#    #+#             */
/*   Updated: 2022/08/05 11:16:24 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include "../mlx/mlx.h"

typedef struct s_map //map informtion
{
	char	*we_path;
	char	*ea_path;
	char	*no_path;
	char	*so_path;
	int	floor_color;
	int	ceiling_color;
}t_map;

typedef struct s_imgs //images information
{
	void	*img_ptr;
	char	*img_addr;
	int	bits_per_pixel;
	int	length;
	int	endian;
	int	width;
	int	height;
}t_imgs;

typedef struct s_cub3d
{
        void    *mlx;
        void    *win;
        t_map   map;
        t_imgs  wall_N;
	t_imgs	wall_S;
	t_imgs	wall_E;
	t_imgs	wall_W;
        struct s_player *ptr;
}t_cub3d;

#endif
