/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:42:32 by engooh            #+#    #+#             */
/*   Updated: 2022/04/01 17:52:38 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	get_color_pixel(t_all *all, void *img, int y, int x)
{
	char	*src;
	int		color;

	all->tmp->addr = mlx_get_data_addr(img, &all->tmp->bpp,
			&all->tmp->llg, &all->tmp->edn);
	src = all->tmp->addr + (y * all->tmp->llg + x * (all->tmp->bpp / 8));
	color = *(unsigned int *)src;
	return (color);
}

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->img->addr + (y * all->img->llg + x * (all->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_all *all, void *img, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->xpm[all->flag]->y)
	{
		j = -1;
		while (++j < all->xpm[all->flag]->x)
		{
			all->color = get_color_pixel(all, img, i, j);
			if (!(all->color == (0xFF << 24)))
				my_mlx_pixel_put(all, x + j, y + i, all->color);
		}
	}
}

int	draw(t_all *all, int x, int y, int z)
{
	int	c;
	int	xx;
	int	yy;

	c = all->flag;
	z = all->xpm[c]->y - z;
	yy = 64 + (x + y) * (all->xpm[c]->y / 4);
	xx = (all->xmax / 2) + (x - y) * (all->xpm[c]->x / 2.4);
	put_pixel(all, all->xpm[c]->img, xx, yy + z);
	return (1);
}

void	print_map(t_all *all, int x, int y)
{
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			all->flag = all->map[y][x] - '0';
			if (all->map[y][x] == '1' && draw(all, x, y, 16))
				draw(all, x, y, 28);
			if (all->map[y][x] == '0')
				draw(all, x, y, 0);
			if (all->map[y][x] == '2' || all->map[y][x] == '3'
					|| all->map[y][x] == '4')
			{
				if (all->map[y][x] == '4')
				{
					all->xpm[4]->pos[0] = x;
					all->xpm[4]->pos[1] = y;
				}
				all->flag = 0;
				draw(all, x, y, 0);
				all->flag = all->map[y][x] - '0';
				draw(all, x, y, 32);
			}
		}
	}
}
