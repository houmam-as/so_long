/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_errors_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:39:55 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/22 16:37:27 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errors_check(char *map_name)
{
	char	**map;

	map = read_map(map_name);
	if (map_extension(map_name) != 0 || check_dimensions(map, map_name) != 0 \
		|| check_invalid_components(map) != 0 || check_components(map) != 0
		|| map[0] == NULL || check_walls(map, map_name) != 0)
	{
		ft_printf("Error\n- Map error -\n");
		free_map(map);
		return (1);
	}
	if (check_collectibles_sides(map) != 0 || valid_path(map) != 0)
	{
		ft_printf("Error\n- Invalid Path -\n");
		free_map(map);
		return (1);
	}
	free_map(map);
	return (0);
}

int	check_walls(char **map, char *map_name)
{
	int	lines;
	int	len;
	int	i;
	int	j;

	lines = size_map(map_name);
	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && j != len - 1)
		{
			if ((map[0][j] != '1') || (map[lines - 1][j] != '1')
				|| (map[i][0] != '1') || (map[i][len - 2] != '1'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_components(char **map)
{
	t_components	item;

	item.p = 0;
	item.c = 0;
	item.e = 0;
	item.i = 0;
	while (map[item.i])
	{
		item.j = 0;
		while (map[item.i][item.j])
		{
			if (map[item.i][item.j] == 'P')
				item.p++;
			if (map[item.i][item.j] == 'C')
				item.c++;
			if (map[item.i][item.j] == 'E')
				item.e++;
			item.j++;
		}
		item.i++;
	}
	if (item.p != 1 || item.c == 0 || item.e != 1)
		return (1);
	return (0);
}

int	check_dimensions(char **map, char *map_name)
{
	size_t	len;
	int		i;
	int		lenght;

	lenght = size_map(map_name);
	len = ft_strlen(map[lenght - 1]) + 1;
	i = 0;
	while (map[i] && i < lenght - 1)
	{
		if (ft_strlen(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	map_extension(char *map_name)
{
	char	*extension;

	extension = ft_strrchr(map_name, 46);
	if (extension == NULL)
		return (-1);
	if (ft_strncmp(".ber", extension, 4) != 0)
		return (1);
	return (0);
}
