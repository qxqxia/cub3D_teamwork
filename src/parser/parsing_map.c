/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:42:23 by qinxia            #+#    #+#             */
/*   Updated: 2022/08/12 13:25:22 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	parsing_map_by_lines(void)
{
	size_t	i;
	size_t	j;
	size_t	width;

	i = 0;
	while (i < my_map.row)
	{
		j = 0;
		width = ft_strlen(my_map.map[i]);
		if (width == 0)
			return(printf("Error: Map can't have empty lines\n"));
		while (j < my_map.col)
		{
			if ((i == 0 || (i == my_map.row - 1)) && \
					(my_map.map[i][j] != '1' && my_map.map[i][j] != ' '))
				return (printf("Error: The map must be surrounded by walls\n"));
			else if (i != 0 && (i != my_map.row - 1) && \
							my_map.map[i][j] != ' ')
				break ;
		}
		if (i != 0 && (i != my_map.row - 1) && j == width)
			return(printf("Error: Map can't have empty lines\n"));
	}
	return (0);
}

static int	parsing_map_content(void)
{
	size_t	i;
	size_t	j;
	size_t	width;

	i = 0;
	while (i < my_map.col)
	{
		j = 0;
		while (j < my_map.row)
		{
			if (my_map.map[i][j] == '1' || my_map.map[i][j] == ' ')
				continue ;
			else if (my_map.map[i][j] == '0' || my_map.map[i][j] == '2' || \
					my_map.map[i][j] == 'N' || my_map.map[i][j] == 'S' || \
					my_map.map[i][j] == 'E' || my_map.map[i][j] == 'W')
			{
				//if (parsing_player(i, j) == 1 || parsing_by_cross(i, j) == 1)
					//return (1);
			}
			else
				return ((printf("Error: Map mismatch the subject\n")));
		}
	}
	return (0);
}

/*int	parsing_map(char ***map, size_t map_height)
{
	my_map.fr = 500;
	
	if (parsing_map_settings(map, map_height) == 0)
	{
		if (settings_checker() == 1 || parsing_map_by_lines() == 1)
			return (1);
		if (parsing_map_inner() == 1)
			return (1);
		if (!(my_map.dir == 'N' || my_map.dir == 'S' || my_map.dir == 'E' || \
				my_map.dir == 'W'))
			return (errors(9));
		return (0);
	}
	return (1);
}*/