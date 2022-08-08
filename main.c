/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:32:02 by qxia              #+#    #+#             */
/*   Updated: 2022/08/08 13:03:28 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	check_args(int argc, char *argv[])
{

}

void	run_game(t_map map)
{
	t_cub3d	cub3d;

	cub3d.map = map;
	cub3d.mlx = mlx_init();
	/*if (cub3d_init(&cub3d) == -1)
	{
		cub3d_free(&cub3d);
		fatal(-1);
	}*/
	mlx_loop(cub3d.mlx);
}

int	main(void)
{
	//t_map	map;
	void *mlx;
	void *win;

	//check_args();
	//if (map_init(&map) == -1)
	//	fatal(-1);
	//parse_map(&map, argv[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "cub3d");
	mlx_loop(mlx);
	//run_game(map);
	return (0);
}
