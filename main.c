/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazarus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:27:48 by lazarus           #+#    #+#             */
/*   Updated: 2022/03/30 01:35:05 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int main(int ac, char **av)
{
    t_all   *all;

    all = init_struct();
    all->map = init_map(all, av[ac - 1], NULL, NULL);
    init_game(all);
    run_game(all);
    return (0);
}
