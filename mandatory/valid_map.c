/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:47:46 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 00:52:00 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_structure(char **map, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == 'C' && !contains(map, charset[i], 1, 1))
		{
			ft_putendl_fd("Error\nMap must contain at least one collectible",
				2);
			return (0);
		}
		if ((charset[i] == 'P' || charset[i] == 'E')
			&& !contains(map, charset[i], 1, 0))
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd
			("Map must contain one starting position and one exit",
				2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_map(char **map)
{
	char	*charset;

	charset = "PEC";
	if (!is_rectangle(map))
		return (ft_putendl_fd("Error\nMap must be rectangle", 2), 0);
	if (!valid_structure(map, charset))
		return (0);
	if (!borders(map, '1'))
		return (ft_putendl_fd("Error\nMap must be surronded by walls", 2), 0);
	if (contains_others(map, "0PEC1"))
		return (ft_putendl_fd("Error\nMap contains unmapped characters", 2), 0);
	if (!check_map_validity(copy_map(map)))
		return (ft_putendl_fd("Error\nMap doesn't contain a valid path", 2), 0);
	return (1);
}
