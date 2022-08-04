/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:32:02 by qxia              #+#    #+#             */
/*   Updated: 2022/08/04 17:23:24 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char *argv[])
{

}

void	run_game(t_map map)
{
	t_cub3d	cub3d;

	cub3d.map = map;
	/*if (cub3d_init(&cub3d) == -1)
	{
		cub3d_free(&cub3d);
		fatal(-1);
	}*/
	mlx_loop(cub3d.mlx);
}

int	main(int argc,char *argv[])
{
	t_map	map;

	//check_args();
	//if (map_init(&map) == -1)
	//	fatal(-1);
	parse_map(&map, argv[1]);
	run_game(map);
	return (0);
}
