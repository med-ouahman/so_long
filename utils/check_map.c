/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:59:41 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/25 00:25:06 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	get_count(char *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	only_c(char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	borders(char **map, char c)
{
	char			**last;
	unsigned int	i;

	last = map;
	while (*(last + 1))
		last++;
	if (!only_c(*map, c) || !only_c(*last, c))
		return (0);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != c || map[i][ft_strlen(map[i]) - 1] != c)
			return (0);
		i++;
	}
	return (1);
}

unsigned int	count_of(char **map, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (map[i])
	{
		count += get_count(map[i], c);
		i++;
	}
	return (count);
}

char	**copy_map(char **map)
{
	size_t			len;
	size_t			size;
	unsigned int	i;
	char			**cpy;

	size = map_size(map);
	len = ft_strlen(map[0]);
	cpy = malloc((size + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cpy[i] = ft_strdup(map[i]);
		if (!cpy[i])
		{
			clear((void *)cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
