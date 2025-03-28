/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:15:32 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 06:56:54 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	bouns(t_data *data, int index)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				put_image(data, index, j, i);
			j++;
		}
		i++;
	}
}

static int	key_events(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		clean(data, 0);
	if (keycode == TOP
		|| keycode == LEFT
		|| keycode == BOTTOM
		|| keycode == RIGHT)
		move_player(data, keycode);
	return (0);
}

static int	exit_game(t_data *data)
{
	clean(data, 0);
	return (0);
}

static int	animate(t_data *data)
{
	struct timeval			current;
	static struct timeval	last;
	static int				index = CL;
	long					diff;

	gettimeofday(&current, NULL);
	diff = (current.tv_sec - last.tv_sec) * 1000000;
	diff += (current.tv_usec - last.tv_usec);
	if (index > CL_D)
		index = CL;
	if (diff >= ANIMATION_DELAY)
	{
		bouns(data, index);
		index++;
		last = current;
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->window, 2, 1, key_events, data);
	mlx_hook(data->window, X, 0, exit_game, data);
	mlx_loop_hook(data->mlx, animate, data);
}
