/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:04:42 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 06:57:44 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_files(t_data *data)
{
	data->files[PLAYER] = "textures/player.xpm";
	data->files[WALL] = "textures/wall.xpm";
	data->files[PLAYER_LEFT] = "textures/player-left.xpm";
	data->files[CL] = "textures/food.xpm";
	data->files[EXIT_CLOSE] = "textures/door-close.xpm";
	data->files[EXIT_OPEN] = "textures/door-open.xpm";
	data->files[PLAYER_ON_DOOR] = "textures/player-on-door.xpm";
	data->files[PLAYER_ON_DOOR_LEFT] = "textures/player-on-door-left.xpm";
	data->files[BG] = "textures/bg.xpm";
}

static void	set_images(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_IMGS)
	{
		data->images[i] = NULL;
		i++;
	}
	i = 0;
	while (i < MAX_IMGS)
	{
		data->images[i] = file_to_image(data->mlx, data->files[i]);
		if (data->images[i] == NULL)
			clean(data, 1);
		i++;
	}
}

void	put_image(t_data *data, int w, int j, int i)
{
	mlx_put_image_to_window(data->mlx, data->window,
		data->images[w], j * IMG_SIZE, i * IMG_SIZE);
}

int	display_images(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				put_image(data, PLAYER, j, i);
			else if (data->map[i][j] == '1')
				put_image(data, WALL, j, i);
			else if (data->map[i][j] == '0')
				put_image(data, BG, j, i);
			else if (data->map[i][j] == 'C')
				put_image(data, CL, j, i);
			else if (data->map[i][j] == 'E')
				put_image(data, EXIT_CLOSE, j, i);
			j++;
		}
		i++;
	}
	return (0);
}

int	game(char **map)
{
	t_data		data;
	int			width;
	int			height;

	data.map = map;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		clean(&data, 1);
	set_files(&data);
	set_images(&data);
	width = map_size(map) * IMG_SIZE;
	height = ft_strlen(map[0]) * IMG_SIZE;
	data.window = mlx_new_window(data.mlx, height, width, "./so_long");
	if (data.window == NULL)
		clean(&data, 1);
	display_images(&data);
	data.coins = count_coins(map);
	data.moves = 0;
	data.player = find_position(map, 'P');
	data.door = find_position(map, 'E');
	data.prev = PLAYER;
	hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
