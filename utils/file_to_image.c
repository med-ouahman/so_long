/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:38:35 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/24 16:39:06 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*file_to_image(void *mlx, char *filename)
{
	int	x;
	int	y;

	return (mlx_xpm_file_to_image(mlx, filename, &x, &y));
}
