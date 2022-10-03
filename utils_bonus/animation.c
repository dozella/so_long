/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:42:41 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 22:29:16 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	show_steps(t_vars *vars)
{
	char	*steps;

	steps = ft_itoa(vars->count_steps);
	mlx_string_put(vars->mlx, vars->mlx_win, 35, 35, 0xFF0000, steps);
	free(steps);
}

int	hold_time(void)
{
	static int	time = 0;

	time++;
	if (time == 21)
		time = 0;
	return (time);
}

void	find_enemy_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map->map[i])
	{
		j = 0;
		while (vars->map->map[i][j])
		{
			if (vars->map->map[i][j] == 'L')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->img_enemy[vars->steps], j * 32, i * 32);
			if (vars->map->map[i][j] == 'R')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->img_enemy[vars->steps], j * 32, i * 32);
			if (vars->map->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->img_player[vars->steps], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

int	player_enemy_animation(t_vars *vars)
{	
	static int	step = 0;

	if (hold_time() == 20)
	{
		enemy_move_left(vars);
		enemy_move_right(vars);
	}
	if (hold_time() == 20)
	{
		step++;
		if (step == 3)
			step = 0;
	}
	vars->steps = step;
	find_enemy_player(vars);
	draw_map(vars->map, vars);
	show_steps(vars);
	return (0);
}

void	animation(t_vars *vars)
{
	vars->img_player[0] = mlx_xpm_file_to_image
		(vars->mlx, PLAYER1, &vars->pxl_x, &vars->pxl_y);
	vars->img_player[1] = mlx_xpm_file_to_image
		(vars->mlx, PLAYER2, &vars->pxl_x, &vars->pxl_y);
	vars->img_player[2] = mlx_xpm_file_to_image
		(vars->mlx, PLAYER3, &vars->pxl_x, &vars->pxl_y);
	vars->img_enemy[0] = mlx_xpm_file_to_image
		(vars->mlx, ENEMY1, &vars->pxl_x, &vars->pxl_y);
	vars->img_enemy[1] = mlx_xpm_file_to_image
		(vars->mlx, ENEMY2, &vars->pxl_x, &vars->pxl_y);
	vars->img_enemy[2] = mlx_xpm_file_to_image
		(vars->mlx, ENEMY2, &vars->pxl_x, &vars->pxl_y);
	mlx_loop_hook(vars->mlx, &player_enemy_animation, vars);
}
