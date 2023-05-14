/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_coins_and_invalid_check.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:05:47 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/21 00:18:19 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectible_sides(char **map, int i, int j)
{
	int	count;

	count = 0;
	if (map[i - 1][j] == '1' || map[i - 1][j] == 'E')
		count++;
	if (map[i + 1][j] == '1' || map[i + 1][j] == 'E')
		count++;
	if (map[i][j - 1] == '1' || map[i][j - 1] == 'E')
		count++;
	if (map[i][j + 1] == '1' || map[i][j + 1] == 'E')
		count++;
	if (count == 4)
		return (1);
	return (0);
}

int	check_collectibles_sides(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
			{
				if (collectible_sides(map, i, j) != 0)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_invalid_components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' \
			&& map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
