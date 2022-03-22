/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazarus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:19:20 by lazarus           #+#    #+#             */
/*   Updated: 2022/03/21 13:47:04 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void    *ft_free_tabs(void **s)
{
    int i;

    i = -1;
    while (s && s[++i])
        free(s[i]);
    if (s)
        free(s);
    s = NULL;
    return (s);
}
    
