/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:26:27 by qxia              #+#    #+#             */
/*   Updated: 2022/09/01 16:26:58 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_filename(char *path)
{
    char    *str;

    str = ft_strrchr(path, '.');
    if (!str)
        return (1);
    str++;
    if (ft_strcmp(str, "xpm"))
        return (1);
    return (0);
}

int ft_check_fd(t_info *info)
{
    int fd;

    if (!info->no || !info->so || !info->we || !info->ea)
		return (ERR_FD);
	if (check_filename(info->no) || check_filename(info->so) || \
		check_filename(info->we) || check_filename(info->ea))
		return (ERR_FD);
	fd = open(info->no, O_RDONLY);
	if (fd <= 0)
		return (ERR_FD); 
	close(fd);
	fd = open(info->so, O_RDONLY);
	if (fd <= 0)
		return (ERR_FD);
	close(fd);
	fd = open(info->we, O_RDONLY);
	if (fd <= 0)
		return (ERR_FD);
	close(fd);
	fd = open(info->ea, O_RDONLY);
	if (fd <= 0)
		return (ERR_FD);
	close(fd);
	return (0);
}

int ft_check_info(t_info *info)
{
    if (!info->no || !info->so || !info->we || !info->ea || \
            !info->f || !info->c)
            return (ERR_INFO);
    if (ft_check_fd(info) != 0)
            return (ERR_FD);
    return (0);
}