/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:41:22 by engooh            #+#    #+#             */
/*   Updated: 2022/03/22 17:54:11 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2, int len)
{
	int     i;
	char	*p;

	if (!s1)
    {
        s1 = malloc(sizeof(char));
        if (!s1)
            return (NULL);
        *s1 = '\0';
    }
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
    free(s1);
	return (p);
}
