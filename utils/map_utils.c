/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:47:46 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/25 00:29:28 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	contains(char **map, char c, unsigned int count, int atleast)
{
	if (atleast && count_of(map, c) < count)
		return (0);
	if (!atleast && count_of(map, c) != count)
		return (0);
	return (1);
}

int	contains_others(char **map, char *charset)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (0 == get_count(charset, map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

unsigned int	count_coins(char **map)
{
	return (count_of(map, 'C'));
}
