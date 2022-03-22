/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazarus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:06:59 by lazarus           #+#    #+#             */
/*   Updated: 2022/03/22 19:15:33 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int open_file(char *file)
{
    int i;
    int fd;

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

char    *get_next_line(int fd, int *size, char *map)
{
    int  ret;
    int  len;
    char *line;
    char buf[2];

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
        ft_free_exit(line, "Error\nthe map does not respect the .ber format");
    }
    return (line);
}

char **check_map(char **maps, int len, int nbrl)
{
    int i;
    int c;

    i = -1;
    c = 0;
    while (maps[++i])
    {
        if (maps[i][0] != '1' || maps[i][len] != '1')
            ft_free_texit((void **)maps, "Error1\nthe map does not respect the .ber format");
        if (i && i != nbrl && !ft_strcmpstr(maps[i], "10PEC", &c))
            ft_free_texit((void **)maps, "Error\nthe map has an invalid character");
        if (!i && !ft_strcmpstr(maps[i], "1", NULL))
            ft_free_texit((void **)maps, "Error\nthe first line from map must have only one");
        if (i == nbrl && !ft_strcmpstr(maps[i], "1", NULL))
            ft_free_texit((void **)maps, "Error\nthe last line from map must have only one");
    }
    if (c < 3)
        ft_free_texit((void **)maps, "Error\nthe map must have at least one P, C and E");
    return (maps);
}

char **init_map(char *file, char *map, char **maps, char *line)
{
    int     i;
    int     fd;
    int     len;

    i = 0;
    len = 0;
    fd = open_file(file);
    line = get_next_line(fd, &len, map);
    while (line)
    {
        map = ft_strjoin(map, line, len * ++i);
        ft_free_null(line);
        line = get_next_line(fd, &len, map);
    }
    if (i < 3)
        ft_free_exit(map, "Error\nthe map should not be less than 3 lines long ");
    maps = ft_split(map, '\n');
    ft_free_null(map);
    return (check_map(maps, len - 2, i - 1));
}
