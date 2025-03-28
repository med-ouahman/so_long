/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:55:57 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/24 13:08:57 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	valid_extension(char *name)
{
	char	*dot;

	dot = ft_strrchr(name, '.');
	if (!dot || dot == name || *(dot - 1) == '/')
		return (0);
	if (!ft_strcmp(dot, ".ber"))
		return (1);
	return (0);
}
