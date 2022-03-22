/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazarus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:27:48 by lazarus           #+#    #+#             */
/*   Updated: 2022/03/22 19:18:32 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int main(int ac, char **av)
{
    int i;
    char **map;

    i = -1;
    map = init_map(av[ac - 1], NULL, NULL, NULL);
    while (map && map[++i])
        printf("%s\n", map[i]);
    ft_free_tabs((void **)map);
    return (0);
}
