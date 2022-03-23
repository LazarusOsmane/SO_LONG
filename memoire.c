#include "so_long.h"

t_all   *init_struct(void)
{
    t_all   *all;

    all = malloc(sizeof(t_all));
    if (!all)
        delete_struct(all);
    all->img = malloc(sizeof(t_data));
    if (!all->img)
        delete_struct(all);
    all->tmp = malloc(sizeof(t_data));
    if (!all->tmp)
        delete_struct(all);
    all->map = malloc(sizeof(t_map));
    if (!all->map)
        delete_struct(all);
    all->xpm = malloc(sizeof(t_xpm));
    if (!all->xpm)
        delete_struct(all);
    all->elem = malloc(sizeof(t_elem));
    if (!all->elem)
        delete_struct(all);
    all->player = malloc(sizeof(t_player));
    if (!all->player)
        delete_struct(all);
    return (all);
}

void    delete_struct(t_all *all)
{
    if (all && all->img)
        free(all->img);
    if (all && all->tmp)
        free(all->tmp);
    if (all && all->map)
        free(all->map);
    if (all && all->map && all->map->map)
        ft_free_tabs((void **)all->map->map);
    if (all && all->xpm)
        free(all->xpm);
    if (all && all->elem)
        free(all->elem);
    if (all && all->player)
        free(all->player);
    if (all)
        free(all);
    exit(0);
}
