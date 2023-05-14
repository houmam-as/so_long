/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:41:55 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/22 16:58:54 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	fill_sides(char **map, int i, int j, int count)
{	
	if (map[i - 1][j] != 'P' && map[i - 1][j] != '1')
	{
		map[i - 1][j] = 'P';
		count = 1;
	}
	if (map[i + 1][j] != 'P' && map[i + 1][j] != '1')
	{
		map[i + 1][j] = 'P';
		count = 1;
	}
	if (map[i][j - 1] != 'P' && map[i][j - 1] != '1')
	{
		map[i][j - 1] = 'P';
		count = 1;
	}
	if (map[i][j + 1] != 'P' && map[i][j + 1] != '1')
	{
		map[i][j + 1] = 'P';
		count = 1;
	}
	return (count);
}

int	is_map_filled(char **map)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && j != len - 1)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_map(char **map);
//vpm = valid_path_map

int	valid_path(char **map)
{
	t_components	data;
	t_data			i;

	i.check = 1;
	while (i.check == 1)
	{
		data.i = 0;
		i.check = 0;
		while (map[data.i])
		{
			data.j = 0;
			while (map[data.i][data.j] && map[data.i][data.j] != '\n')
			{
				if (map[data.i][data.j] == 'P')
					i.check = fill_sides(map, data.i, data.j, i.check);
				data.j++;
			}
			data.i++;
		}
	}
	if (is_map_filled(map) != 0)
		return (1);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
