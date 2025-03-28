/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:46:10 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/24 15:47:03 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	int		fd;
	char	**map;

	if (ac != 2)
		return (ft_putstr_fd("Usage: ./so_long_bonus map.ber\n", 2), 1);
	if (!valid_extension(av[1]))
		return (ft_putstr_fd("Error\nInvalid map extension\n", 2), 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Map file might not exist or have read permissions", 2);
		return (1);
	}
	map = parse_map(fd);
	close(fd);
	if (!map)
		return (1);
	if (!valid_map(map))
	{
		clear((void *)map);
		return (1);
	}
	game(map);
	return (0);
}
