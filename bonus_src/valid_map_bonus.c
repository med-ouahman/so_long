/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:51:58 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 00:51:40 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	valid_structure(char **map, char *charset)
{
	while (*charset)
	{
		if (*charset == 'C' && !contains(map, *charset, 1, 1))
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Map must contain at least one collectible", 2);
			return (0);
		}
		if ((*charset == 'P' || *charset == 'E')
			&& !contains(map, *charset, 1, 0))
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd
			("Map must contain one starting position and one exit", 2);
			return (0);
		}
		charset++;
	}
	return (1);
}

int	valid_map(char **map)
{
	if (!is_rectangle(map))
		return (ft_putendl_fd("Error\nMap must be rectangle", 2), 0);
	if (!valid_structure(map, "PEC"))
		return (0);
	if (!borders(map, '1'))
		return (ft_putendl_fd("Error\nMap must be surronded by walls", 2), 0);
	if (contains_others(map, "10PECX"))
		return (ft_putendl_fd("Error\nMap contains unmapped characters", 2), 0);
	if (!check_map_validity(copy_map(map)))
		return (ft_putendl_fd("Error\nMap doesn't contain a valid path", 2), 0);
	return (1);
}
