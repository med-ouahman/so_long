/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 09:32:58 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/25 12:59:09 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_data *data)
{
	data->moves++;
	ft_printf("MOVES: %u\r", data->moves);
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

void	hooks(t_data *data)
{
	mlx_hook(data->window, 2, 1, key_events, data);
	mlx_hook(data->window, X, 0, exit_game, data);
}
