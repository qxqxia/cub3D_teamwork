/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:13:28 by qxia              #+#    #+#             */
/*   Updated: 2022/09/07 11:17:32 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_w(t_cub3d *cub)
{
	float	plr_t_x;
	float	plr_t_y;

	plr_t_x = cub->plr->p_x + cub->plr->d_x * MOVE_DIST;
	plr_t_y = cub->plr->p_y + cub->plr->d_y * MOVE_DIST;
	if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] == '1' && \
		cub->map[(int)plr_t_x][(int)cub->plr->p_y] == '1')
		return ;
	else if (cub->map[(int)plr_t_x][(int)plr_t_y] != '1')
	{
		cub->map[(int)cub->plr->p_x][(int)cub->plr->p_y] = '0';
		cub->plr->p_x = plr_t_x;
		cub->plr->p_y = plr_t_y;
	}
	else if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] != '1')
		cub->plr->p_y = plr_t_y;
	else if (cub->map[(int)plr_t_x][(int)cub->plr->p_y] != '1')
		cub->plr->p_x = plr_t_x;
}

void	ft_move_s(t_cub3d *cub)
{
	float	plr_t_x;
	float	plr_t_y;

	plr_t_x = cub->plr->p_x - cub->plr->d_x * MOVE_DIST;
	plr_t_y = cub->plr->p_y - cub->plr->d_y * MOVE_DIST;
	if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] == '1' && \
		cub->map[(int)plr_t_x][(int)cub->plr->p_y] == '1')
		return ;
	else if (cub->map[(int)plr_t_x][(int)plr_t_y] != '1')
	{
		cub->map[(int)cub->plr->p_x][(int)cub->plr->p_y] = '0';
		cub->plr->p_x = plr_t_x;
		cub->plr->p_y = plr_t_y;
	}
	else if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] != '1')
		cub->plr->p_y = plr_t_y;
	else if (cub->map[(int)plr_t_x][(int)cub->plr->p_y] != '1')
		cub->plr->p_x = plr_t_x;
}

void	ft_move_a(t_cub3d *cub)
{
	float	plr_t_x;
	float	plr_t_y;

	plr_t_x = cub->plr->p_x - cub->plr->d_y * MOVE_DIST;
	plr_t_y = cub->plr->p_y + cub->plr->d_x * MOVE_DIST;
	if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] == '1' && \
		cub->map[(int)plr_t_x][(int)cub->plr->p_y] == '1')
		return ;
	else if (cub->map[(int)plr_t_x][(int)plr_t_y] != '1')
	{
		cub->map[(int)cub->plr->p_x][(int)cub->plr->p_y] = '0';
		cub->plr->p_x = plr_t_x;
		cub->plr->p_y = plr_t_y;
	}
	else if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] != '1')
		cub->plr->p_y = plr_t_y;
	else if (cub->map[(int)plr_t_x][(int)cub->plr->p_y] != '1')
		cub->plr->p_x = plr_t_x;
}

void	ft_move_d(t_cub3d *cub)
{
	float	plr_t_x;
	float	plr_t_y;

	plr_t_x = cub->plr->p_x + cub->plr->d_y * MOVE_DIST;
	plr_t_y = cub->plr->p_y - cub->plr->d_x * MOVE_DIST;
	if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] == '1' && \
		cub->map[(int)plr_t_x][(int)cub->plr->p_y] == '1')
		return ;
	else if (cub->map[(int)plr_t_x][(int)plr_t_y] != '1')
	{
		cub->map[(int)cub->plr->p_x][(int)cub->plr->p_y] = '0';
		cub->plr->p_x = plr_t_x;
		cub->plr->p_y = plr_t_y;
	}
	else if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] != '1')
		cub->plr->p_y = plr_t_y;
	else if (cub->map[(int)plr_t_x][(int)cub->plr->p_y] != '1')
		cub->plr->p_x = plr_t_x;
}