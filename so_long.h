/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazarus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:24:08 by lazarus           #+#    #+#             */
/*   Updated: 2022/03/22 09:47:53 by lazarus          ###   ########.fr       */
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
# define _POSIX_C_SOURCE 200809L
#  include "./minilibx-linux/mlx.h"
#  include "/usr/include/X11/X.h"
# endif
# ifdef __APPLE__
#  include "minilibx_opengl_20191021/mlx.h"
# endif

typedef struct s_player
{
	int	pos;
	int	count;
	int	moves;
}	t_player;

typedef struct s_xpm
{
	int		x;
	int		y;
	void	*img;
}	t_xpm;

typedef struct s_elem
{
    char	*ground;
    char    *player;
	char	*wall;
    char    *exit;
    char    *col;
	int		color;
}	t_elem;

typedef struct s_data 
{
    char	*addr;
	void	*img;
	int		bpp;
	int		llg;
	int		edn;
}	t_data;

typedef struct s_map
{
	int		w;
	int		h;
	int		s_width;
	int		s_heigth;
    int     m_width;
    int     m_heigth;
	char	**map;
}	t_map;

typedef struct s_all
{
	void			*mlx;
	void			*win;
	t_data			*img;
	t_data			*tmp;
	t_map			*map;
    t_xpm           *xpm;
    t_elem          *elem;
    t_player        *player;
}	t_all;

int     open_file(char *file);
char    *get_next_line(int fd, int *size, char *map);
char    **init_map(t_all *all, char *file, char **maps, char *map);

t_all   *init_struct(void);
void    delete_struct(t_all *all);
#endif
