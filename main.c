/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:32:02 by qxia              #+#    #+#             */
/*   Updated: 2022/09/06 16:22:48 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	run_game(t_cub3d *cub3d)
{
	if (!cub3d->mlx)
		return (ERR_MLX);
	cub3d->win = mlx_new_window(cub3d->mlx, 1240, 720, "cub3d");
	if (!cub3d->win)
		return (ERR_MLX);
	cub3d->imgs->smallmap = NULL;
	cub3d->imgs->plr = NULL;
	cub3d->imgs->dir = NULL;
	cub3d->imgs->flr = NULL;
	ft_print_smallmap(cub3d, cub3d->imgs);
	//mlx_hook(cub3d->win, 2, 1l << 0, &ft_key_event, cub3d);
	//mlx_hook(cub3d->win, 17, 1l << 0, &ft_close, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	ret;
	t_cub3d	*cub3d;

	ret = -1;
	cub3d = NULL;
	if (argc != 2)
		return (ft_return(ERR_ARGS, cub3d));
	ret = ft_parser(argv[1], &cub3d);
	if (ret != 0)
		return(ft_return(ret, cub3d));
	cub3d->imgs = malloc(sizeof(t_img_set));
	cub3d->mlx = mlx_init();
	if (ft_init_imgs(cub3d))
		return (ft_return(ERR_INFO, cub3d));
	if (run_game(cub3d))
		return (ft_return(ERR_INFO, cub3d));
	return (0);
}


