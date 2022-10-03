/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:08:40 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 22:12:46 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	enemy_move_left(t_vars	*vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map->map[i])
	{
		j = 0;
		while (vars->map->map[i][j] != 0)
		{
			if (vars->map->map[i][j] == 'L')
			{
				if (vars->map->map[i][j - 1] == 'P')
					ft_exit_lost(vars);
				else if (vars->map->map[i][j - 1] == '0')
				{
					vars->map->map[i][j - 1] = 'L';
					vars->map->map[i][j] = '0';
				}
				else
					vars->map->map[i][j] = 'R';
			}
			j++;
		}
		i++;
	}
}

void	enemy_move_right(t_vars	*vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map->map[i])
	{
		j = 0;
		while (vars->map->map[i][j++])
		{
			if (vars->map->map[i][j] == 'R')
			{
				if (vars->map->map[i][j + 1] == 'P')
					ft_exit_lost(vars);
				else if (vars->map->map[i][j + 1] == '0')
				{
					vars->map->map[i][j + 1] = 'R';
					vars->map->map[i][j] = '0';
					j++;
				}
				else
					vars->map->map[i][j] = 'L';
			}
		}
		i++;
	}
}
