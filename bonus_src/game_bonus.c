/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:25:54 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 07:36:09 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game(char **map)
{
	t_data		data;

	data.map = map;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		clean(&data, 1);
	set_files(&data);
	set_images(&data);
	data.width = map_size(map) * IMG_SIZE;
	data.height = ft_strlen(map[0]) * IMG_SIZE;
	data.window = mlx_new_window(data.mlx, data.height,
			data.width, "./so_long");
	if (data.window == NULL)
		clean(&data, 1);
	display_images(&data);
	data.coins = count_coins(map);
	data.moves = 0;
	data.prev = PLAYER;
	mlx_set_font(data.mlx, data.window, "10x20");
	mlx_string_put(data.mlx, data.window, 90, 30, 0xffffff, "MOVES: 0");
	data.player = find_position(map, 'P');
	data.door = find_position(map, 'E');
	hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
