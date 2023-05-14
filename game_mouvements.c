/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mouvements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:53:31 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/22 01:46:21 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_move(t_data *data)
{
	t_components	player;

	player = find_component(data->map, 'P');
	if (data->map[player.i][player.j + 1] != '1')
	{
		data->map[player.i][player.j] = '0';
		data->map[player.i][player.j + 1] = 'P';
		door_fix(data);
		mouvement_part(data);
	}
	if (data->map[player.i][player.j + 1] != '1' && data->coin_cnt == 0
		&& (data->map[player.i][player.j + 1] == \
		data->map[data->door_pos.i][data->door_pos.j]))
	{
		data->map[player.i][player.j] = '0';
		data->map[player.i - 1][player.j] = 'P';
		mouvement_part(data);
		free_map(data->map);
		exit(0);
	}
	game_window(data);
}

void	left_move(t_data *data)
{
	t_components	player;

	player = find_component(data->map, 'P');
	if (data->map[player.i][player.j - 1] != '1')
	{
		data->map[player.i][player.j] = '0';
		data->map[player.i][player.j - 1] = 'P';
		door_fix(data);
		mouvement_part(data);
	}
	if (data->map[player.i][player.j - 1] != '1' && data->coin_cnt == 0
		&& (data->map[player.i][player.j - 1] == \
		data->map[data->door_pos.i][data->door_pos.j]))
	{
		data->map[player.i][player.j] = '0';
		data->map[player.i - 1][player.j] = 'P';
		mouvement_part(data);
		free_map(data->map);
		exit(0);
	}
	game_window(data);
}

void	up_move(t_data *data)
{
	t_components	player;

	player = find_component(data->map, 'P');
	if (data->map[player.i - 1][player.j] != '1')
	{
		data->map[player.i][player.j] = '0';
		data->map[player.i - 1][player.j] = 'P';
		door_fix(data);
		mouvement_part(data);
	}
	if (data->map[player.i - 1][player.j] != '1' && data->coin_cnt == 0
		&& (data->map[player.i - 1][player.j] == \
		data->map[data->door_pos.i][data->door_pos.j]))
	{
		data->map[player.i][player.j] = '0';
		data->map[player.i - 1][player.j] = 'P';
		mouvement_part(data);
		free_map(data->map);
		exit(0);
	}
	game_window(data);
}

void	down_move(t_data *data)
{
	t_components	player;

	player = find_component(data->map, 'P');
	if (data->map[player.i + 1][player.j] != '1')
	{
		data->map[player.i][player.j] = '0';
		data->map[player.i + 1][player.j] = 'P';
		door_fix(data);
		mouvement_part(data);
	}
	if (data->map[player.i + 1][player.j] != '1' && data->coin_cnt == 0
		&& (data->map[player.i + 1][player.j] == \
		data->map[data->door_pos.i][data->door_pos.j]))
	{
		data->map[player.i][player.j] = '0';
		data->map[player.i - 1][player.j] = 'P';
		mouvement_part(data);
		free_map(data->map);
		exit(0);
	}
	game_window(data);
}

t_components	find_component(char **map, char item)
{
	t_components	component;
	int				i;
	int				j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == item)
			{
				component.i = i;
				component.j = j;
				return (component);
			}
			j++;
		}
		i++;
	}
	component.i = -1;
	component.j = -1;
	return (component);
}
