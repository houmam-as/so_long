/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:20:53 by hait-sal          #+#    #+#             */
/*   Updated: 2023/04/22 17:07:38 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdarg.h>

typedef struct components
{
	int	i;
	int	j;
	int	p;
	int	c;
	int	e;
}	t_components;
/*----------------------------*/
typedef struct s_data
{
	t_components	door_pos;
	void			*mlx;
	void			*win;
	void			*wall;
	void			*player;
	void			*coin;
	void			*close;
	void			*open;
	char			**map;
	char			**vpm;
	int				check;
	int				coin_cnt;
	int				mouvements_count;
	char			*itoa_mv;
	int				wid;
	int				hei;
}	t_data;
/*                                                                  */
typedef struct dimensions
{
	int	x;
	int	y;
}	t_dimensions;

typedef struct s_map
{
	char	**map;
}	t_map;
/*                                                               */
//=======================| Libft functions |=======================
/*                                                               */
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_itoa(int n);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
/*                                                               */
//=======================| printf functions |=======================
/*                                                               */
int				ft_putstr(char *s);
int				ft_printf(const char *s, ...);
int				ft_putchar(char c);
int				ft_putnbr(int m);
int				digit_nbr(int m);
/*                                                                 */
//====================| Get Next line functions |====================
/*                                                                 */
char			*get_next_line(int fd);
int				nl_check(char *s);
char			*nl_sv(int fd, char *bfr, char *str);

//==========================| Reading map |==========================
/*                                                                 */
int				size_map(char *map_name);
char			**read_map(char *map_name);
/*                                                                  */
//==========================| Checking map |==========================
/*                                                                  */
int				check_walls(char **map, char *map_name);
int				check_components(char **map);
int				check_invalid_components(char **map);
int				collectible_sides(char **map, int i, int j);
int				check_collectibles_sides(char **map);
int				check_dimensions(char **map, char *map_name);
int				is_map_filled(char **map);
int				fill_sides(char **map, int i, int j, int count);
int				valid_path(char **map);
int				errors_check(char *map_name);
int				map_extension(char *map_name);
/*                                                              */
//==================| puts components to window |=================
/*                                                              */
void			put_to_window(char component, int x, int y, t_data *data);
t_dimensions	game_dimensions(char **map, char *map_name);
void			game_window(t_data *data);
int				collectibles_number(char **map);
void			all_items(t_data *data, t_dimensions	*my_window);
void			all_items_one(t_data *data);
void			all_items_two(t_data *data);
void			all_items_three(t_data *data);
int				handle_key_press(int keysym, t_data *data);
int				close_window(t_data *data);
void			counter(t_data *data);
void			free_map(char **map);
void			door_fix(t_data *data);
void			mouvement_part(t_data *data);
t_components	find_component(char **map, char item);

/*                                                                */
//==========================| Game moves |==========================
/*                                                                */
void			right_move(t_data *data);
void			left_move(t_data *data);
void			up_move(t_data *data);
void			down_move(t_data *data);

#endif