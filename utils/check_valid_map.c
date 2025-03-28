/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:58:51 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/26 00:45:38 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	find_row(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

static int	find_col(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			return (i);
		i++;
	}
	return (0);
}

static void	make_all_p(char **map, t_pos dimensions, int y, int x)
{
	if (x < 0 || x >= dimensions.col || y < 0 || y >= dimensions.row)
		return ;
	if (ft_strchr("0CE", map[y][x]))
	{
		map[y][x] = 'P';
		make_all_p(map, dimensions, y, x + 1);
		make_all_p(map, dimensions, y, x - 1);
		make_all_p(map, dimensions, y + 1, x);
		make_all_p(map, dimensions, y - 1, x);
	}
}

int	check_map_validity(char **map)
{
	t_pos	dimensions;
	int		x;
	int		y;

	if (!map)
		return (0);
	dimensions.row = map_size(map);
	dimensions.col = ft_strlen(map[0]);
	y = find_row(map);
	x = find_col(map[y]);
	make_all_p(map, dimensions, y, x - 1);
	make_all_p(map, dimensions, y, x + 1);
	make_all_p(map, dimensions, y - 1, x);
	make_all_p(map, dimensions, y + 1, x);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] != '1' && map[y][x] != 'P'
				&& map[y][x] != 'X' && map[y][x] != '0')
				return (clear((void *)map), 0);
	}
	clear((void *)map);
	return (1);
}
