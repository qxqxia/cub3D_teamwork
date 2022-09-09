/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:13:37 by qxia              #+#    #+#             */
/*   Updated: 2022/09/07 11:32:00 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_unsig(const char *str)
{
	int		negatif;
	size_t	result;

	negatif = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negatif = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if (*str && (*str < '0' || *str > '9'))
		return (-1);
	if (negatif < 0 && result > 2147483648)
		return (-1);
	if (negatif > 0 && result > 2147483647)
		return (-1);
	return (result * negatif);
}

void	ft_rotate_player(t_cub3d *cub, int key)
{
	double	olddir_x;
	double	oldplane_x;

	if (key == XK_LEFT)
	{
		olddir_x = cub->plr->d_x;
		cub->plr->d_x = cub->plr->d_x * cos(SPD) - cub->plr->d_y * sin(SPD);
		cub->plr->d_y = olddir_x * sin(SPD) + cub->plr->d_y * cos(SPD);
		oldplane_x = cub->plr->pl_x;
		cub->plr->pl_x = cub->plr->pl_x * cos(SPD) - cub->plr->pl_y * sin(SPD);
		cub->plr->pl_y = oldplane_x * sin(SPD) + cub->plr->pl_y * cos(SPD);
	}
	if (key == XK_RIGHT)
	{
		olddir_x = cub->plr->d_x;
		cub->plr->d_x = cub->plr->d_x * cos(-SPD) - cub->plr->d_y * sin(-SPD);
		cub->plr->d_y = olddir_x * sin(-SPD) + cub->plr->d_y * cos(-SPD);
		oldplane_x = cub->plr->pl_x;
		cub->plr->pl_x = cub->plr->pl_x * cos(-SPD) - cub->plr->pl_y * sin(-SPD);
		cub->plr->pl_y = oldplane_x * sin(-SPD) + cub->plr->pl_y * cos(-SPD);
	}
}

int	ft_key_event(int key, t_cub3d *cub3d)
{
	if (key == XK_ESCAPE)
		ft_close(cub3d);
	if (key == XK_W)
		ft_move_w(cub3d);
	if (key == XK_S)
		ft_move_s(cub3d);
	if (key == XK_A)
		ft_move_a(cub3d);
	if (key == XK_D)
		ft_move_d(cub3d);
	if (key == XK_LEFT || key == XK_RIGHT)
		ft_rotate_player(cub3d, key);
	ft_print_graphic(cub3d);
	ft_print_smallmap(cub3d, cub3d->imgs);
	return (0);
}
