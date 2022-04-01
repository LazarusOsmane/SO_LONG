/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabs_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:25:50 by engooh            #+#    #+#             */
/*   Updated: 2022/04/01 17:39:20 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabs_tabs(int t_size, int t_len, int s_size, int s_len)
{
	int		i;
	void	**t;

	t = malloc(t_size * t_len);
	if (!t)
		return (NULL);
	i = -1;
	while (++i < t_len - 1)
	{
		t[i] = malloc(s_size * s_len);
		if (!t[i])
			return (NULL);
	}
	return (t);
}
