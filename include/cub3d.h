/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:02:57 by qxia              #+#    #+#             */
/*   Updated: 2022/07/27 16:45:32 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include "mlx.h"

typedef struct s_cub3d
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	struct s_images *imgs;
	struct s_info	*info;
	struct s_player *ptr;
}t_cub3d;

typedef struct s_info
{
	char	*we;
	char	*ea;
	char	*no;
	char	*so;
	int	*f;
	int	*c;
}t_info;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int	bpp;
	int	size;
	int	endian;
	int	w;
	int	h;
}t_img;
