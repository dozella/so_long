/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:44:42 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 22:29:16 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	help_draw(t_map *map, t_vars *vars, int i)
{
	int	j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == '0')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->img_floor, (j * 32), (i * 32));
		if (map->map[i][j] == '1')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->img_wall, (j * 32), (i * 32));
		if (map->map[i][j] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->img_exit, (j * 32), (i * 32));
		if (map->map[i][j] == 'C')
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->img_coin, (j * 32), (i * 32));
		j++;
	}
}

void	draw_map(t_map *map, t_vars *vars)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		help_draw(map, vars, i);
		i++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		end_prog(vars);
	if (keycode == 0)
		move_left(vars);
	if (keycode == 1)
		move_down(vars);
	if (keycode == 2)
		move_right(vars);
	if (keycode == 13)
		move_up(vars);
	return (0);
}

void	start_game(t_map *map, t_vars *vars)
{
	vars->map = map;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx,
			(map->columns + 1) * 32, (map->rows) * 32, "So_long");
	vars->img_coin = mlx_xpm_file_to_image(vars->mlx,
			COIN, &vars->pxl_x, &vars->pxl_y);
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx,
			EXIT, &vars->pxl_x, &vars->pxl_y);
	vars->img_floor = mlx_xpm_file_to_image(vars->mlx,
			FLOOR, &vars->pxl_x, &vars->pxl_y);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx,
			WALL, &vars->pxl_x, &vars->pxl_y);
	draw_map(map, vars);
	mlx_string_put(vars->mlx, vars->mlx_win, 35, 35, 0xFF0000, "Steps 0");
	animation(vars);
	mlx_hook(vars->mlx_win, 2, 0, &key_hook, vars);
	mlx_hook(vars->mlx_win, 17, 0, &end_prog, vars);
	mlx_loop(vars->mlx);
}
