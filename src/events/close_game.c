/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:08 by qxia              #+#    #+#             */
/*   Updated: 2022/09/05 13:42:56 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_close(t_cub3d *cub3d)
{
    ft_free_cub3d(cub3d);
    exit(0);
}