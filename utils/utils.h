/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:58:27 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/25 12:17:06 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>

# define TOP 65362
# define LEFT 65361
# define BOTTOM 65364
# define RIGHT 65363

# define IMG_SIZE 60
# define ESCAPE 65307
# define X 17

typedef struct s_pos
{
	int	row;
	int	col;
}	t_pos;

int				valid_extension(char *name);
int				valid_map(char **map);
char			**parse_map(int fd);
int				is_rectangle(char **map);
void			clear(void **ptr);
int				only_c(char *s, char c);
unsigned int	map_size(char **map);
unsigned int	count_coins(char **map);
t_pos			find_position(char **map, char c);
unsigned int	count_of(char **map, char c);
int				contains_others(char **map, char *charset);
char			**copy_map(char **map);
unsigned int	get_count(char *s, char c);
int				check_map_validity(char **map);
void			*file_to_image(void *mlx, char *filename);
int				borders(char **map, char c);
int				contains(char **map, char c, unsigned int count, int atleast);

#endif