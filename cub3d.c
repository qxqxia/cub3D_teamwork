/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qinxia <qinxia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:09:27 by qinxia            #+#    #+#             */
/*   Updated: 2022/08/09 15:04:16 by qinxia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static void	cub3d_init(void)
{
	cub3d.map = my_map;
	cub3d.textures.tex_width = 64;
	cub3d.textures.tex_height = 64;
	cub3d.keys.w = 0;
	cub3d.keys.s = 0;
	cub3d.keys.a = 0;
	cub3d.keys.d = 0;
	cub3d.keys.left = 0;
	cub3d.keys.right = 0;
}

/*static void	hooks(void)
{
	mlx_hook(cub3d.win, 17, 1L << 17, mlx_close, 0);
	mlx_hook(cub3d.win, 2, 1L << 0, mlx_press, 0);
	mlx_hook(cub3d.win, 3, 1L << 1, mlx_release, 0);
	if (BONUS == 1)
	{
		mlx_hook(cub3d.win, 6, 1L << 6, mlx_mouse, 0);
	}
}*/

int	run_game(void)
{
	cub3d_init();
	cub3d.mlx = mlx_init();
	if (cub3d.mlx == 0)
		printf("Cannot connect with mlx\n");
	else
	{
		cub3d.win = mlx_new_window(cub3d.mlx, cub3d.map.col, cub3d.map.row, "cub3D");
		//sprites_array();
		//textures();
		//pos_init();
		cub3d.img.img = mlx_new_image(cub3d.mlx, cub3d.map.col, cub3d.map.row);
		//cub3d.img.addr = mlx_get_data_addr(cub3d.img.img, \
				&(cub3d.img.bits_per_pixel), &(cub3d.img.line_length), \
				&(cub3d.img.endian));
		//ray_cast();
		//hooks();
		//mlx_loop_hook(cub3d.mlx, ray_cast, NULL);
		mlx_loop(cub3d.mlx);
	}
	return (0);
}