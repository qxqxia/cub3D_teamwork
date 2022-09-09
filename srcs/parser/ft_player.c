/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:45 by qxia              #+#    #+#             */
/*   Updated: 2022/09/06 15:57:58 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_set_plane(t_cub3d *cub3d, char player)
{
	if (player == 'N')
	{
		cub3d->plr->pl_x = 0;
		cub3d->plr->pl_y = 0.66;
	}
	else if (player == 'S')
	{
		cub3d->plr->pl_x = 0;
		cub3d->plr->pl_y = -0.66;
	}
	else if (player == 'W')
	{
		cub3d->plr->pl_x = -0.66;
		cub3d->plr->pl_y = 0;
	}
	else if (player == 'E')
	{
		cub3d->plr->pl_x = 0.66;
		cub3d->plr->pl_y = 0;
	}
	return ;
}

void	ft_set_direction(t_cub3d *cub3d, char player)
{
	if ( player == 'N')
	{
		cub3d->plr->d_x = -1;
		cub3d->plr->d_y = 0;
	}
	else if (player == 'S')
	{
		cub3d->plr->d_x = 1;
		cub3d->plr->d_y = 0;
	}
	else if (player == 'W')
	{
		cub3d->plr->d_x = 0;
		cub3d->plr->d_y = -1;
	}
	else if (player == 'E')
	{
		cub3d->plr->d_x = 0;
		cub3d->plr->d_y = 1;
	}
	return ;
}

void	ft_set_player_info(t_cub3d *cub3d)
{
	int		i;
	int		j;
	char	player;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			player = cub3d->map[i][j];
			if (player == 'N' || player == 'S' || \
					player == 'E' || player == 'W')
			{
				cub3d->plr->p_x = i + 0.5;
				cub3d->plr->p_y = j + 0.5;
				ft_set_direction(cub3d, player);
				ft_set_plane(cub3d, player);
			}
			j++;
		}
		i++;
	}
	return ;
}

int	ft_set_player(t_cub3d *cub3d)
{
	cub3d->plr = malloc(sizeof(t_player));
	if (!(cub3d->plr))
		return (1);
	ft_set_player_info(cub3d);
	return (0);
}