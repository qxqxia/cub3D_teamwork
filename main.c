/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qinxia <qinxia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:32:02 by qxia              #+#    #+#             */
/*   Updated: 2022/08/09 14:32:15 by qinxia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	**map;
	size_t	map_height;

	if (argc == 2)
	{
		fd = file_open(argv[1]);
		if (fd > 0)
		{
			map_height = read_map_2d(fd, &map);
			if (map_height == (size_t)(-1))
			{
				printf("Sorry, map is empty \n");
				return (0);
			}
			if (parsing_map(&map, map_height) == 0)
				run_game();
		}
		else
			printf("File open error\n");
	}
	else
		printf("Worong arguments,"
			" and it must be a map with .cub extension\n");
	return (0);
}


