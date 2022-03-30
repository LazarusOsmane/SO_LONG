/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazarus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:24:08 by lazarus           #+#    #+#             */
/*   Updated: 2022/03/30 01:47:49 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

# ifdef __linux__
#  define _POSIX_C_SOURCE 200809L
#  define ESC 65307
#  include "./minilibx-linux/mlx.h"
#  include "/usr/include/X11/X.h"
# endif
# ifdef __APPLE__
#  include "minilibx_opengl_20191021/mlx.h"
# endif

# define WIDTH_TEXTURE 64
# define HEIGTH_TEXTURE 64
# define ASSET_NBR 6
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef struct s_xpm
{
	int		x;
	int		y;
    int     col;
    int     cnt;
    int     pos[2];
	void	*img;
}	t_xpm;

typedef struct s_elem
{
    int     x;
    int     y;
    int     color;
    char    *flag;
    t_xpm   *ground;
}	t_elem;

typedef struct s_data 
{
    char	*addr;
	void	*img;
	int		bpp;
	int		llg;
	int		edn;
}	t_data;

typedef struct s_all
{
    int             x;
    int             y;
    int             cmax;
    int             xmax;
    int             ymax;
	void			*mlx;
	void			*win;
    int             flag;
    char            **map;
	t_data			*img;
	t_data			*tmp;
    t_xpm           **xpm;
    int             color;
}	t_all;

int     open_file(char *file);
char    *get_next_line(t_all *all, int fd, int *size, char *map);
char    **init_map(t_all *all, char *file, char **maps, char *map);

t_all   *init_struct(void);
void    delete_struct(t_all *all);
void    delete_file_to_image(t_all *all);

int     check_hook(int keycode, t_all *all);

void    init_game(t_all *all);
void    run_game(t_all *all);
void    end_game(t_all *all);

void    print_map(t_all *all, int x, int y);

void    ft_free_texit(t_all *all, void **s, char *err);
void    ft_free_exit(t_all *all, void *s, char *err);
void    move(t_all *all, int key, int c);
void    draw(t_all *all, int x, int y, int z);
#endif
