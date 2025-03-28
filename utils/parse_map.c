/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:06:04 by mouahman          #+#    #+#             */
/*   Updated: 2025/03/24 13:09:00 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*exclude_nl(char *line)
{
	size_t	len;
	char	*s;
	size_t	i;

	len = ft_strlen(line);
	if (line[len - 1] != '\n')
		return (ft_strdup(line));
	s = malloc(len);
	if (!s)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		s[i] = line[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static t_list	*get_lines(int fd)
{
	char	*line;
	t_list	*lines;
	t_list	*new;

	lines = NULL;
	errno = 0;
	line = get_next_line(fd);
	if (!line && errno == 0)
		return (ft_putendl_fd("Error\nMap is empty", 2), NULL);
	while (line && errno == 0)
	{
		new = ft_lstnew(line);
		if (!new)
			return (ft_lstclear(&lines, free), free(line), NULL);
		ft_lstadd_back(&lines, new);
		line = get_next_line(fd);
		if (!line && errno != 0)
		{
			ft_lstclear(&lines, free);
			return (NULL);
		}
	}
	return (lines);
}

static int	fill_map(char **map, t_list *lines)
{
	unsigned int	i;

	i = 0;
	while (lines)
	{
		if (!ft_strcmp((char *)lines->content, "\n")
			|| (!lines->next && ft_strchr((char *)lines->content, '\n')))
		{
			ft_putendl_fd("Error\nMap contains redundant newlines", 2);
			return (clear((void *)map), 1);
		}
		map[i] = exclude_nl((char *)lines->content);
		if (!map[i])
		{
			clear((void *)map);
			return (1);
		}
		i++;
		lines = lines->next;
	}
	map[i] = NULL;
	return (0);
}

char	**parse_map(int fd)
{
	char	**map;
	t_list	*lines;
	int		size;
	int		i;

	lines = get_lines(fd);
	if (!lines)
		return (NULL);
	size = ft_lstsize(lines) + 1;
	map = malloc(size * sizeof(char *));
	if (!map)
	{
		ft_lstclear(&lines, free);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		map[i] = NULL;
	if (fill_map(map, lines) == 1)
		return (ft_lstclear(&lines, free), NULL);
	ft_lstclear(&lines, free);
	return (map);
}
