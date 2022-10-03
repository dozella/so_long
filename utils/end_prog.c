/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:39:11 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 20:42:41 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
