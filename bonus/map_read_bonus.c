/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:51 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/22 17:04:13 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	size_map(char *map_name)
{
	int		fd;
	int		i;
	char	*map;

	fd = open(map_name, O_RDONLY);
	map = get_next_line(fd);
	i = 0;
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**read_map(char *map_name)
{
	int		i;
	int		fd;
	int		size;
	char	**map;

	size = size_map(map_name);
	map = malloc((size + 1) * sizeof(char *));
	fd = open(map_name, O_RDONLY);
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	map[i] = 0;
	close(fd);
	return (map);
}
