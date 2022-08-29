/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:19:52 by qxia              #+#    #+#             */
/*   Updated: 2022/08/29 15:51:41 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
        return (ERR_MAP);
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