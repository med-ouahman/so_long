/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:55 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/26 07:22:13 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../utils/utils.h"
# include <sys/time.h>

# define MAX_IMGS 15
# define ANIMATION_DELAY 100000

typedef struct s_data
{
	void	*mlx;
	int		width;
	int		height;
	void	*window;
	void	*images[MAX_IMGS];
	char	*files[MAX_IMGS];
	char	**map;
	int		player_on_door;
	t_pos	player;
	t_pos	door;
	int		prev;
	uint	coins;
	uint	moves;
}	t_data;

enum e_characters
{
	PLAYER = 0,
	PLAYER_LEFT,
	WALL,
	CL,
	CL_L,
	CL_R,
	CL_D,
	EXIT_OPEN,
	EXIT_CLOSE,
	PLAYER_ON_DOOR,
	PLAYER_ON_DOOR_LEFT,
	BG,
	ENMY_B,
	ENMY_R,
	ENMY_Y
};

int		game(char **map);
int		valid_map(char **map);
int		game(char **map);
void	clean(t_data *data, int code);
void	hooks(t_data *data);
int		move_player(t_data *data, int dir);
void	put_image(t_data *data, int w, int j, int i);
void	display_images(t_data *data);
void	swap_positions(t_data *data, t_pos next, int dir);
void	set_files(t_data *data);
void	set_images(t_data *data);

#endif