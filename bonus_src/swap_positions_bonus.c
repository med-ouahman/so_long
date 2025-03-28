/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_positions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:11:07 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/27 02:16:40 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_on_door(t_data *data, int dir)
{
	if (LEFT == dir)
	{
		put_image(data, PLAYER_ON_DOOR_LEFT, data->door.col, data->door.row);
		data->prev = PLAYER_LEFT;
	}
	else if (RIGHT == dir)
	{
		put_image(data, PLAYER_ON_DOOR, data->door.col, data->door.row);
		data->prev = PLAYER;
	}
	else
	{
		if (data->prev == PLAYER_LEFT)
			put_image(data, PLAYER_ON_DOOR_LEFT,
				data->door.col, data->door.row);
		if (data->prev == PLAYER)
			put_image(data, PLAYER_ON_DOOR, data->door.col, data->door.row);
	}
}

static void	put_player(t_data *data, t_pos position, int dir)
{
	if (LEFT == dir)
	{
		put_image(data, PLAYER_LEFT, position.col, position.row);
		data->prev = PLAYER_LEFT;
	}
	else if (RIGHT == dir)
	{
		put_image(data, PLAYER, position.col, position.row);
		data->prev = PLAYER;
	}
	else
		put_image(data, data->prev, position.col, position.row);
}

static int	player_off_door(t_data *data, t_pos next, int dir)
{
	if (data->map[next.row][next.col] == 'C'
		|| data->map[next.row][next.col] == '0')
	{
		if (data->map[next.row][next.col] == 'C')
			data->coins--;
		if (data->coins == 0)
			put_image(data, EXIT_OPEN, data->door.col, data->door.row);
		if (data->map[data->door.row][data->door.col] == 'P')
		{
			put_image(data, EXIT_CLOSE, data->door.col, data->door.row);
			put_player(data, next, dir);
			data->map[data->door.row][data->door.col] = 'E';
			return (1);
		}
	}
	if (data->map[next.row][next.col] == 'E' && data->coins == 0)
		return (ft_printf("VICTORY!\n"), clean(data, EXIT_SUCCESS), 0);
	return (0);
}

void	swap_positions(t_data *data, t_pos next, int dir)
{
	if (player_off_door(data, next, dir))
		return ;
	data->map[next.row][next.col] = 'P';
	data->map[data->player.row][data->player.col] = '0';
	if (data->map[data->door.row][data->door.col] == 'P')
		player_on_door(data, dir);
	else
		put_player(data, next, dir);
	put_image(data, BG, data->player.col, data->player.row);
}
