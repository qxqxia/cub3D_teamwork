/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:26:54 by qxia              #+#    #+#             */
/*   Updated: 2022/09/09 14:34:31 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_info(t_cub3d **cub3d)
{
	(*cub3d)->info = malloc(sizeof(t_info));
	if (!(*cub3d)->info)
		return (ERR_MALLOC);
	(*cub3d)->info->no = NULL;
	(*cub3d)->info->so = NULL;
	(*cub3d)->info->we = NULL;
	(*cub3d)->info->ea = NULL;
	(*cub3d)->info->f = NULL;
	(*cub3d)->info->c = NULL;
	return (0);
}

int	ft_init_struct(t_cub3d **cub3d)
{
	*cub3d = malloc(sizeof(t_cub3d));
	if (!(*cub3d))
		return (ERR_MALLOC);
	(*cub3d)->info = NULL;
	(*cub3d)->map = NULL;
	(*cub3d)->mlx = NULL;
	(*cub3d)->win = NULL;
	(*cub3d)->imgs = NULL;
	(*cub3d)->plr = NULL;
	return (0);
}

int	ft_check_file(char *filename)
{
	int		str_len;
	char	*mapfile;

	str_len = ft_strlen(filename);
	if (str_len <= 4)
		return (ERR_FILE);
	mapfile = filename;
	mapfile += str_len - 4;
	if (ft_strcmp(mapfile, ".cub") != 0)
		return (ERR_FILE);
	return (0);
}

int	ft_parser(char *filename, t_cub3d **cub3d)
{
	int		fd;
	int		cub3d_ret;
	int		info_ret;
	int		map_ret;

	if (ft_check_file(filename) != 0)
		return (ERR_FILE);
	fd = open(filename, O_RDONLY);
	if (fd <= 2)
		return (ERR_FILE);
	cub3d_ret = ft_init_struct(cub3d);
	info_ret = ft_get_info(fd, cub3d);
	map_ret = ft_get_map(fd, cub3d);
	if (info_ret != 0)
		return (info_ret);
	if (cub3d_ret != 0)
		return (cub3d_ret);
	if (map_ret != 0)
		return (map_ret);
	if (ft_set_player(*cub3d))
		return (ERR_MALLOC);
	return (0);
}
