/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:06:59 by lazarus           #+#    #+#             */
/*   Updated: 2022/04/04 13:55:02 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *file)
{
	int	i;
	int	fd;

	i = ft_strlen(file) - 4;
	if (i <= 4 || ft_strncmp(".ber", file + i, 4))
	{
		ft_putstr_fd("Error\nthe map is not a .ber", 0);
		exit(0);
	}
	fd = open(file, O_RDONLY | O_NOFOLLOW);
	if (fd < 0)
	{
		perror("Error\n");
		exit(0);
	}
	return (fd);
}

char	*get_next_line(t_all *all, int fd, int *size, char *map)
{
	int		ret;
	int		len;
	char	*line;
	char	buf[2];

	ret = 1;
	len = 0;
	line = NULL;
	buf[0] = '\0';
	buf[1] = '\0';
	while (buf[0] != '\n' && ret)
	{
		ret = read(fd, buf, 1);
		len += ret;
		if (ret)
			line = ft_strjoin(line, buf, len);
	}
	if (!*size)
		*size = len;
	if (ret < 0 || (len != *size && ret))
	{
		ft_free_null(map);
		ft_free_exit(all, line, "Error\n");
	}
	return (line);
}

char	**check_map(t_all *all, char **maps, int len, int nbrl)
{
	int	i;
	int	cc[3];

	i = -1;
	cc[0] = 0;
	cc[1] = 0;
	cc[2] = 0;
	while (maps[++i])
	{
		if (maps[i][0] != '1' || maps[i][len] != '1')
			ft_free_texit(all, (void **)maps, "Error1\n");
		if (i && i != nbrl && !ft_strcmpstr(maps[i], "10PEC", cc))
			ft_free_texit(all, (void **)maps, "Error\n");
		if (!i && !ft_strcmpstr(maps[i], "1", NULL))
			ft_free_texit(all, (void **)maps, "Error\n");
		if (i == nbrl && !ft_strcmpstr(maps[i], "1", NULL))
			ft_free_texit(all, (void **)maps, "Error\n");
	}
	if (cc[0] < 1 || cc[1] < 1 || cc[2] < 1)
		ft_free_texit(all, (void **)maps, "Error\n");
	all->cmax = cc[0];
	return (maps);
}

char	**init_map(t_all *all, char *file, char **maps, char *map)
{
	int		i;
	int		fd;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	fd = open_file(file);
	line = get_next_line(all, fd, &len, map);
	while (line)
	{
		map = ft_strjoin(map, line, len * ++i);
		ft_free_null(line);
		line = get_next_line(all, fd, &len, map);
	}
	if (i < 3)
		ft_free_exit(all, map, "Error\n");
	maps = ft_split(map, '\n');
	ft_free_null(map);
	all->y = i * (64 / 2.4);
	all->x = len * 64;
	all->ymax = 1200;
	all->xmax = 1400;
	return (check_map(all, maps, len - 2, i - 1));
}
