/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mlx_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:47:35 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/22 01:04:42 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_items(t_data *data, t_dimensions	*my_window)
{
	data->door_pos = find_component(data->map, 'E');
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_map(data->map);
		ft_printf("Error\n- mlx init error -");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, my_window->x, \
	my_window->y, "so_long");
	if (!data->win)
	{
		free_map(data->map);
		ft_printf("Error\n- mlx window error -");
		exit(1);
	}
	all_items_one(data);
	all_items_two(data);
	all_items_three(data);
	game_window(data);
}

void	all_items_one(t_data *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, \
	"textures/wall.xpm", &data->wid, &data->hei);
	if (!data->wall)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_map(data->map);
		ft_printf("Error\n- wall image error -");
		exit(1);
	}
	data->open = mlx_xpm_file_to_image(data->mlx, \
	"textures/open.xpm", &data->wid, &data->hei);
	if (!data->open)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_map(data->map);
		ft_printf("Error\n- door open error -");
		exit(1);
	}
}

void	all_items_two(t_data *data)
{
	data->coin = mlx_xpm_file_to_image(data->mlx, \
	"textures/coin.xpm", &data->wid, &data->hei);
	if (!data->coin)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_map(data->map);
		ft_printf("Error\n- coin error -");
		exit(1);
	}
	data->player = mlx_xpm_file_to_image(data->mlx, \
	"textures/player.xpm", &data->wid, &data->hei);
	if (!data->player)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_map(data->map);
		ft_printf("Error\n- player error -");
		exit(1);
	}
}

void	all_items_three(t_data *data)
{
	data->close = mlx_xpm_file_to_image(data->mlx, \
	"textures/close.xpm", &data->wid, &data->hei);
	if (!data->close)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_map(data->map);
		ft_printf("Error\n- door closed error -");
		exit(1);
	}
}

void	door_fix(t_data *data)
{
	t_components	player;

	player = find_component(data->map, 'P');
	if (player.i != data->door_pos.i || player.j != data->door_pos.j)
		data->map[data->door_pos.i][data->door_pos.j] = 'E';
}
