/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:16:08 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 00:32:13 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_imgs(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_IMGS)
	{
		if (data->images[i])
			mlx_destroy_image(data->mlx, data->images[i]);
		i++;
	}
}

void	clean(t_data *data, int code)
{
	if (data->mlx)
	{
		destroy_imgs(data);
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	clear((void *)data->map);
	exit(code);
}
