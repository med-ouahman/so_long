/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:32 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/24 13:17:46 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_pos	find_position(char **map, char c)
{
	t_pos	pos;
	int		i;
	int		j;

	i = 0;
	pos.row = -1;
	pos.col = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				pos.row = i;
				pos.col = j;
			}
			j++;
		}
		i++;
	}
	return (pos);
}
