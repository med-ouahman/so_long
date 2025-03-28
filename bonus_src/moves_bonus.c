/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:48:39 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 07:39:07 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_moves(t_data *data)
{
	char			moves[40];
	unsigned int	num;
	unsigned int	i;

	moves[0] = '\0';
	data->moves++;
	num = data->moves;
	i = 0;
	while (num)
	{
		i++;
		num /= 10;
	}
	i += ft_strlcat(moves, "MOVES: ", sizeof(moves));
	moves[i] = '\0';
	num = data->moves;
	while (num)
	{
		moves[--i] = num % 10 + 48;
		num /= 10;
	}
	put_image(data, WALL, 1, 0);
	put_image(data, WALL, 2, 0);
	put_image(data, WALL, 3, 0);
	mlx_string_put(data->mlx, data->window, 90, 30, 0xffffff, moves);
}

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
	if (data->map[next.row][next.col] == 'X')
	{
		ft_printf("DEFEATED!\n");
		clean(data, 0);
	}
	data->player = next;
	return (0);
}
