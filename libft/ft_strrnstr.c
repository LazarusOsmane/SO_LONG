/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:17:30 by engooh            #+#    #+#             */
/*   Updated: 2022/04/13 14:14:36 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrnstr(char *s1, char const *s2)
{
    int i;
    int y;

    i = ft_strlen(s1);
    y = ft_strlen(s2);
    while (i && y && (s1[--i] == s2[--y]))
    {
    }
    if (y)
        return (NULL);
    return (s1 + i);
}
