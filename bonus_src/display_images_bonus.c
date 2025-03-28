/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:02:44 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/27 03:02:59 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	random_enmy(void)
{
	int	random;

	random = rand() % 3;
	if (random == 0)
		return (ENMY_B);
	if (random == 1)
		return (ENMY_R);
	return (ENMY_Y);
}

void	set_files(t_data *data)
{
	data->files[PLAYER] = "textures/player.xpm";
	data->files[WALL] = "textures/wall.xpm";
	data->files[PLAYER_LEFT] = "textures/player-left.xpm";
	data->files[CL] = "textures/food.xpm";
	data->files[CL_L] = "textures/food-left.xpm";
	data->files[CL_R] = "textures/food-right.xpm";
	data->files[CL_D] = "textures/food-down.xpm";
	data->files[EXIT_CLOSE] = "textures/door-close.xpm";
	data->files[EXIT_OPEN] = "textures/door-open.xpm";
	data->files[PLAYER_ON_DOOR] = "textures/player-on-door.xpm";
	data->files[PLAYER_ON_DOOR_LEFT] = "textures/player-on-door-left.xpm";
	data->files[BG] = "textures/bg.xpm";
	data->files[ENMY_B] = "textures/blue.xpm";
	data->files[ENMY_R] = "textures/yellow.xpm";
	data->files[ENMY_Y] = "textures/green.xpm";
}

void	set_images(t_data *data)
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

void	display_images(t_data *data)
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
			else if (data->map[i][j] == 'X')
				put_image(data, random_enmy(), j, i);
			j++;
		}
		i++;
	}
}
