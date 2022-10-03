/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:44:00 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 21:17:53 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_init_map(t_map *map)
{
	map->rows = 0;
	map->columns = 0;
	map->coin = 0;
	map->exit = 0;
	map->map = NULL;
	map->player = 0;
	map->x = 0;
	map->y = 0;
	map->enemy = 0;
}

void	ft_init_vars(t_vars *vars)
{
	vars->steps = 0;
	vars->pxl_x = 32;
	vars->pxl_y = 32;
	vars->fd = 0;
	vars->count_steps = 0;
	vars->line_map = NULL;
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->img_coin = NULL;
	vars->img_exit = NULL;
	vars->img_floor = NULL;
	vars->img_player[0] = NULL;
	vars->img_player[1] = NULL;
	vars->img_player[2] = NULL;
	vars->img_enemy[0] = NULL;
	vars->img_enemy[1] = NULL;
	vars->img_wall = NULL;
}
