/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:44:29 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 00:30:44 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../utils/utils.h"

# define MAX_IMGS 9

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*images[MAX_IMGS];
	char	*files[MAX_IMGS];
	char	**map;
	int		prev;
	t_pos	player;
	t_pos	door;
	uint	coins;
	uint	moves;
}	t_data;

enum e_characters
{
	PLAYER = 0,
	PLAYER_LEFT,
	WALL,
	CL,
	EXIT_CLOSE,
	EXIT_OPEN,
	PLAYER_ON_DOOR,
	PLAYER_ON_DOOR_LEFT,
	BG,
};

int		game(char **map);
void	hooks(t_data *data);
void	print_moves(t_data *data);
void	hooks(t_data *data);
void	clean(t_data *data, int code);
void	put_image(t_data *data, int w, int j, int i);
void	print_moves(t_data *data);
void	swap_positions(t_data *data, t_pos next, int dir);
int		move_player(t_data *data, int dir);

#endif
