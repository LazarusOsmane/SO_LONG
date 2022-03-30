/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:51:11 by engooh            #+#    #+#             */
/*   Updated: 2022/03/29 13:15:04 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int     check_hook(int keycode, t_all *all)
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

void    file_to_image_xpm(t_all *all)
{
    t_xpm   **t;

    t = (t_xpm **)ft_tabs_tabs(sizeof(t_xpm *), ASSET_NBR, sizeof(t_xpm), 1);
    if (!t)
        return ;
    t[0]->img = mlx_xpm_file_to_image(all->mlx, "image/ground2.xpm", &t[0]->x, &t[0]->y);
    t[1]->img = mlx_xpm_file_to_image(all->mlx, "image/wall.xpm", &t[1]->x, &t[1]->y);
    t[2]->img = mlx_xpm_file_to_image(all->mlx, "image/isometric_pixel_0209.xpm", &t[2]->x, &t[2]->y);
    t[3]->img = mlx_xpm_file_to_image(all->mlx, "image/isometric_pixel_0209.xpm", &t[3]->x, &t[3]->y);
    t[4]->img = mlx_xpm_file_to_image(all->mlx, "image/isometric_pixel_0209.xpm", &t[4]->x, &t[4]->y);
    t[5] = 0;
    all->xpm = t; 
}

void    init_game(t_all *all)
{
    all->mlx = mlx_init();
    file_to_image_xpm(all);
    all->win = mlx_new_window(all->mlx, all->xmax, all->ymax, "gosth master");
    all->img->img = mlx_new_image(all->mlx, all->xmax, all->ymax);
    all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bpp, &all->img->llg, &all->img->edn);
}

void    run_game(t_all *all)
{
    print_map(all, -1, -1);
    mlx_hook(all->win, 2, 1L<<0, check_hook, all);
    mlx_put_image_to_window(all->mlx, all->win, all->img->img, 0, 0);
    mlx_loop(all->mlx);
}

void    end_game(t_all *all)
{
    mlx_destroy_image(all->mlx, all->img->img);
    delete_file_to_image(all);
    mlx_destroy_window(all->mlx, all->win);
    mlx_destroy_display(all->mlx);
    delete_struct(all);
}
