/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:32:53 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/20 21:40:27 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectibles_number(char **map)
{
	int	count;
	int	len;
	int	i;
	int	j;

	len = ft_strlen(map[0]);
	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && j != len - 1)
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_dimensions	game_dimensions(char **map, char *map_name)
{
	t_dimensions	game;
	int				x;
	int				y;

	x = ft_strlen(map[0]) - 1;
	y = size_map(map_name);
	game.x = x * 48;
	game.y = y * 48;
	return (game);
}

void	put_to_window(char component, int y, int x, t_data *data)
{
	int	xp;
	int	yp;

	xp = x * 48;
	yp = y * 48;
	if (component == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, xp, yp);
	else if (component == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, xp, yp);
	else if (component == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coin, xp, yp);
	else if (component == 'E')
	{
		if (data->coin_cnt == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->open, xp, yp);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->close, xp, yp);
	}
}

void	game_window(t_data *data)
{
	int	i;
	int	j;

	data->coin_cnt = collectibles_number(data->map);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_to_window(data->map[i][j], i, j, data);
			j++;
		}
		i++;
	}
}
