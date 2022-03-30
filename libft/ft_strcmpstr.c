/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazarus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:39:03 by lazarus           #+#    #+#             */
/*   Updated: 2022/03/30 01:26:40 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_strcmpstr(char *s1, char *s2, int *cc)
{
    while (*s1)
    {

        if (!ft_strchr(s2, *s1))
            return (0);
        if (*s1 == 'P' && ++cc[2])
            *s1 = '4';
        if (*s1 == 'E' && ++cc[1])
            *s1 = '3';
        if (*s1 == 'C' && ++cc[0])
            *s1 = '2'; 
        s1++;
    }
    return (1);
}
