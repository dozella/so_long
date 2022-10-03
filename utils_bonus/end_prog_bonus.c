/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:43:31 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 17:44:46 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_all(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map->map[i])
		free(vars->map->map[i++]);
	free(vars->map->map);
}

void	ft_exit_win(t_vars *vars)
{
	write(1, "You won!\n", 9);
	free_all(vars);
	exit(0);
}

void	ft_exit_lost(t_vars *vars)
{
	write(1, "You lost!\n", 10);
	free_all(vars);
	exit(0);
}

void	ft_exit(t_map *map)
{
	int	i;

	write(2, "Error\n", 6);
	if (map->map)
	{
		i = 0;
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
	exit(1);
}

int	end_prog(t_vars *vars)
{
	(void) vars;
	free_all(vars);
	exit (0);
	return (0);
}
