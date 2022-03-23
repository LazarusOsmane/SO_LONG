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
    int     i;
    t_all   *all;

    all = init_struct();
    all->map->map = init_map(all, av[ac - 1], NULL, NULL);
    if (!all->map->map)
        delete_struct(all);
    i = -1;
    while(all->map->map[++i])
        printf("%s||\n", all->map->map[i]);
    delete_struct(all);
    return (0);
}
