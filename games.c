/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:51:11 by engooh            #+#    #+#             */
/*   Updated: 2022/04/13 14:04:05 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
		end_game(all);
	if (keycode == UP)
		move(all, UP, '4' - '0');
	if (keycode == DOWN)
		move(all, DOWN, '4' - '0');
	if (keycode == LEFT)
		move(all, LEFT, '4' - '0');
	if (keycode == RIGHT)
		move(all, RIGHT, '4' - '0');
	return (0);
}

void	file_to_image_xpm(t_all *all)
{
	t_xpm	**t;

	t = (t_xpm **)ft_tabs_tabs(sizeof(t_xpm *), ASSET_NBR, sizeof(t_xpm), 1);
	if (!t)
		return ;
	t[0]->img = mlx_xpm_file_to_image(all->mlx, "asset/ground5.xpm",
			&t[0]->x, &t[0]->y);
	t[1]->img = mlx_xpm_file_to_image(all->mlx, "asset/ground.xpm",
			&t[1]->x, &t[1]->y);
	t[2]->img = mlx_xpm_file_to_image(all->mlx, "asset/col3.xpm",
			&t[2]->x, &t[2]->y);
	t[3]->img = mlx_xpm_file_to_image(all->mlx, "asset/col1.xpm",
			&t[3]->x, &t[3]->y);
	t[4]->img = mlx_xpm_file_to_image(all->mlx, "asset/col2.xpm",
			&t[4]->x, &t[4]->y);
	t[5] = 0;
	all->xpm = t;
	if (!(t[0]->img && t[1]->img && t[2]->img && t[3]->img && t[4]->img))
		end_game(all);
}

void	init_game(t_all *all)
{
	all->mlx = mlx_init();
    if (!all->mlx)
        end_game(all);
    all->win = mlx_new_window(all->mlx, all->xmax, all->ymax, "war block");
    all->img->img = mlx_new_image(all->mlx, all->xmax, all->ymax);
    all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bpp,
			&all->img->llg, &all->img->edn);
    file_to_image_xpm(all);
}

void	run_game(t_all *all)
{
	print_map(all, -1, -1);
	mlx_hook(all->win, 2, 1L << 0, check_hook, all);
	mlx_hook(all->win, 17, 1L << 0, end_game, all);
	mlx_put_image_to_window(all->mlx, all->win, all->img->img, 0, 0);
	mlx_loop(all->mlx);
}

int	end_game(t_all *all)
{
    if (all->img && all->img->img)
        mlx_destroy_image(all->mlx, all->img->img);
    if (all->win)
        mlx_destroy_window(all->mlx, all->win);
    if (all->xpm)
        delete_file_to_image(all);
    if (all->mlx)
        mlx_destroy_display(all->mlx);
    if (all)
        delete_struct(all);
    exit(0);
}
