#include "so_long.h"

void    ft_free_texit(t_all *all, void **s, char *err)
{
    int i;

    i = -1;
    while (s && s[++i])
        free(s[i]);
    if (s)
        free(s);
    ft_putstr_fd(err, 0);
    delete_struct(all);
    exit(0);
}

void ft_free_exit(t_all *all, void *s, char *err)
{
    if (s)
        free(s);
    ft_putstr_fd(err, 0);
    delete_struct(all);
    exit(0);
}

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
    all->cnt = 0;
    all->map = NULL;
    all->mlx = NULL;
    return (all);
}

void    delete_struct(t_all *all)
{
    if (all && all->img)
        free(all->img);
    if (all && all->tmp)
        free(all->tmp);
    if (all && all->map)
        ft_free_tabs((void **)all->map);
    if (all->mlx)
        free(all->mlx);
    if (all)
        free(all);
    exit(0);
}

void    delete_file_to_image(t_all *all)
{
    int i;

    i = -1;
    while (all->xpm[++i])
    {
        mlx_destroy_image(all->mlx, all->xpm[i]->img);
        free(all->xpm[i]);
    }
    free(all->xpm);
}
