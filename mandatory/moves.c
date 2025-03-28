/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:43:55 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/25 13:00:14 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_pos	find_next(t_pos player, int dir)
{
	t_pos	next;

	next.col = player.col;
	next.row = player.row;
	if (TOP == dir)
		next.row = player.row - 1;
	else if (LEFT == dir)
		next.col = player.col - 1;
	else if (BOTTOM == dir)
		next.row = player.row + 1;
	else if (RIGHT == dir)
		next.col = player.col + 1;
	return (next);
}

int	move_player(t_data *data, int dir)
{
	t_pos	next;

	next = find_next(data->player, dir);
	if (data->map[next.row][next.col] == '1')
		return (0);
	if (data->map[next.row][next.col] == '0'
		|| data->map[next.row][next.col] == 'C'
		|| data->map[next.row][next.col] == 'E')
	{
		print_moves(data);
		swap_positions(data, next, dir);
	}
	data->player = next;
	return (0);
}
