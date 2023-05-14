/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:46:18 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/22 17:00:41 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data			data;
	int				fd;
	t_dimensions	my_window;

	fd = open(av[1], O_RDONLY);
	data.mouvements_count = 0;
	if (fd == -1)
	{
		ft_printf("Error\nFile not exist\n");
		return (1);
	}
	close(fd);
	if (ac == 0 || ac != 2)
	{
		ft_printf("Error\narguements error");
		return (1);
	}
	if (errors_check(av[1]) != 0)
		return (1);
	data.map = read_map(av[1]);
	my_window = game_dimensions(data.map, av[1]);
	all_items(&data, &my_window);
	mlx_hook(data.win, 2, 0, handle_key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}

void	mouvement_part(t_data *data)
{
	data->mouvements_count++;
	ft_printf("%d\n", data->mouvements_count);
	mlx_clear_window(data->mlx, data->win);
}

void	counter(t_data *data)
{
	data->itoa_mv = ft_itoa(data->mouvements_count);
	mlx_string_put(data->mlx, data->win, 35, 35, 13906591, data->itoa_mv);
	free(data->itoa_mv);
}

int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_map(data->map);
		exit(0);
	}
	if (keysym == 124 || keysym == 2)
		right_move(data);
	if (keysym == 123 || keysym == 0)
		left_move(data);
	if (keysym == 126 || keysym == 13)
		up_move(data);
	if (keysym == 125 || keysym == 1)
		down_move(data);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	exit(1);
	return (0);
}
