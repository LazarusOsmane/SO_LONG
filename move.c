/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:26:55 by engooh            #+#    #+#             */
/*   Updated: 2022/03/30 02:40:17 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void    run_move(t_all *all, int px, int py, int c)
{
    all->map[py][px] = '4';
    all->xpm[c]->pos[0] = px;
    all->xpm[c]->pos[1] = py;
    print_map(all, -1, -1);
    if (c == 3 && !all->cmax)
        end_game(all);
    else if (c == 2)
        all->cmax--;
    mlx_put_image_to_window(all->mlx, all->win, all->img->img, 0, 0);
    ft_printf("nombre de mouvement: %d\n", ++all->cnt);
}

void    move(t_all *all, int key, int c)
{
    int px;
    int py;
    int x;
    int y;

    x = all->xpm[c]->pos[0];
    y = all->xpm[c]->pos[1];
    px = x;
    py = y;
    if (key == UP && all->map[py][px - 1] != '1')
        px = px - 1; 
    else if (key == DOWN && all->map[py][px + 1] != '1')
        px = px + 1; 
    else if (key == LEFT && all->map[py + 1][px] != '1')
        py = py + 1; 
    else if (key == RIGHT && all->map[py - 1][px] != '1')
        py = py - 1;
    else 
        return ;
    if ((all->map[py][px] == '3' && all->cmax))
        return ;
    all->map[y][x] = '0';
    run_move(all, px, py, all->map[py][px] - '0');
}
