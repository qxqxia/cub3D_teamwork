/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:19:52 by qxia              #+#    #+#             */
/*   Updated: 2022/09/01 16:41:08 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  ft_map_shape(char **map, int i, int j, int size )
{
    int str_len;
    
    if (!map[i])
        return (0);
    str_len = ft_strlen(map[i]);
    if (i = 0 || j = 0 || i == size - 1 || j == str_len -1)
    {
        if (map[i][j] != '1' && map[i][j] != ' ')
            return (0);
    }
    if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || \
		map[i][j] == 'E' || map[i][j] == 'W')
	{
		if (!map[i + 1][j] || !map[i - 1] || !map[i][j + 1] || \
			!map[i][j - 1] || !map[i + 1][j + 1] || !map[i + 1][j - 1] || \
			!map[i - 1][j + 1] || !map[i - 1][j - 1])
			return (0);
		if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ' || \
			map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || \
			map[i + 1][j + 1] == ' ' || map[i + 1][j - 1] == ' ' || \
			map[i - 1][j + 1] == ' ' || map[i - 1][j - 1] == ' ')
			return (0);
	}
	return (1);
}

static int  ft_check_close(char **map, int size)
{
    int i;
    int j;
    int str_len;

    i = 0;
    while (i < size)
    {
        j = 0;
        str_len = ft_strlen(map[i]);
        while( j < str_len)
        {
            if (!ft_map_shape(map, i, j, size))
                return (ERR_MAP_OPEN);
            j++;
        }
        i++;
    }
    return (0);    
}

int ft_check_char(char **map)
{
    int i;
    int j;
    int player_count;

    i = 0;
    player_count = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j]) == 'S' || 
                    map[i][j] == 'N')
                player_count++;
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' && \
				map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != 'S' && \
				map[i][j] != ' ')
				return (ERR_MAP_CHAR);
			j++;
		}
		i++;
    }
    if (player_count != 1)
        return (ERR_MAP_PLAYER);
    return (0);
}

int ft_check_map(char **map)
{
    int size;
    int ret;

    if (!map)
        return (ERR_MAP_NULL);
    size = ft_arraylen(map);
    ret = 0;
    ret = ft_check_char(map);
    if (ret != 0)
        return (ret);
    ret = ft_check_close(map, size);
    if (ret != 0)
        return (ret);
    return (0);
}